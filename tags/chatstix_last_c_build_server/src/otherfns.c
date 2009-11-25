#include "../includes/sockheads.h"

//allocate space for struct

job *stralloc() {
    job *str;
    str = (job *) malloc(sizeof (job));
    str->qcmsg = (char *) malloc(MAXCLI * sizeof (char));
    str->cliaddr = (char *) malloc(16 * sizeof (char));
    str->next = NULL;
    return str;
}

//free queue element memory space

void strfree(job *job_free) {
    //leads to munmap_chunk() error
    //free(job_free->qcmsg);
    free(job_free);
}

//random id generator

void crandgen(char *rid) {
    const char seq[] = "abcdefghijklmnopqrstuvwxyz123456789";
    int i;
    srand(time(NULL)); // give different seed each time so that sequence is different.
    for (i = 0; i < (NAMELEN - 1); i++)
        if (i == 0) // to make sure 1st char is not a number.
            rid[i] = seq[rand() % 26];
        else
            rid[i] = seq[rand() % 35];
    rid[NAMELEN - 1] = '\0';
    printf("Random ID generated is:%s\n", rid);
}

//send function

void sendpkt(char *caddr, char *msg, int port) {
    struct sockaddr_in sendsock;
    int tempfd;
    tempfd = createsocket(&sendsock, caddr, port, UDP, B_NO);
#ifdef TRACEPRINT
    printf("TP:in sendpkt()\n");
#endif
    if (sendto(tempfd, msg, strlen(msg), 0, (struct sockaddr *) & sendsock, sizeof (sendsock)) == -1)
        progerror("send error");
    printf("Msg sent is - %s\n", msg);
    if (close(tempfd) == -1)
        progerror("temp sock close error");
}

//find roomnumer corresponding to room name

int findroom(char *roomname, int *roomnum) {
    int i;
    for (i = 0; i < MAXROOMS; i++) {
        if (mrooms[i].roomname == NULL)
            continue;
        if (!strcmp(roomname, mrooms[i].roomname)) {
            *roomnum = i;
            return 0; //return 0 if room with asked name is found
        }
    }
    //if room not found, find first room which is not in use
    for (i = 0; i < MAXROOMS; i++) {
        if (mrooms[i].inuse == 0) {
            *roomnum = i;
            return 1; //free room found
        }
    }
    return -1; //return -1 if all rooms are in use.
}

//create new room for non existing name

void createroom(char *rname, int rnum) {
    int len, i;
    len = strlen(rname);
    if (len > 10)
        len = 10;
    mrooms[rnum].roomname = (char *) malloc(len * sizeof (char));
    mrooms[rnum].clientlist = (int *) malloc(MAXCLIENTS * sizeof (int));
    for (i = 0; i < MAXCLIENTS; i++)
        *((mrooms[rnum].clientlist) + i) = 0;
    strcpy(mrooms[rnum].roomname, rname);
    //printf("Room name of new room is %s\n", mrooms[rnum].roomname);
}

//crate user

int findfreeuserslot() {
    int i;
    for (i = 0; i < MAXCLIENTS; i++) {
        if (!infostr[i].inuse)
            return i; //return index of infostr which is free
    }
    return -1; //return -1 if all clients are in use
}
//generate multicast address

int getmultiaddr(char *cbuf, char *addr, int clientid) {
    int roomnum, newroom;
    char *delimiter = " ", *token;
    token = strtok(cbuf, delimiter);
    token = strtok(NULL, delimiter); //get only room name by removing /join
    newroom = findroom(token, &roomnum); //if newroom=1,roomnum will have first free room
    if (newroom == 1) //if newroom = 1, then room doesnt exist, create.
    {
        printf("new room created\n");
        createroom(token, roomnum); //alloc mem and store name of room
        mrooms[roomnum].inuse = 1;
    } else if (newroom == -1) {
        sprintf(addr, "roomsfull");
        return -1;
    }
    infostr[clientid].room = roomnum; //clientinfo updated to which room he was assigned
    strcpy(addr, mrooms[roomnum].roomaddr);
    //printf("in getmultiaddr(), Room addr assigned is %s\n", addr);
    return roomnum;
}

//fill in the infostr associated with the index
void filluserinfo(int cid, char *rid, char *ipaddr){
        infostr[cid].inuse = 1;
        infostr[cid].cliname = (char *) malloc(NAMELEN * sizeof (char));
        strcpy(infostr[cid].cliname, rid);
        infostr[cid].cliipaddr = (char *) malloc(16 * sizeof (char));
        strcpy(infostr[cid].cliipaddr, ipaddr);
}

//add a user to the clientlist in mroomstr

void addusertoroomlist(int cid, int roomn) {
    *(mrooms[roomn].clientlist + cid) = 1;
    mrooms[roomn].numusers++;
}

//remove user from roomlist

void removeuserfromroomlist(int cid, int roomn) {
    *(mrooms[roomn].clientlist + cid) = 0;
    mrooms[roomn].numusers--;
    if (!mrooms[roomn].numusers) {
        free(mrooms[roomn].roomname);
        free(mrooms[roomn].clientlist);
        mrooms[roomn].inuse = 0;
    }
}

//find if username exists

int finduser(char *name) {
    int i;
    for (i = 0; i < MAXCLIENTS; i++) {
        if (!infostr[i].inuse)
            continue;
        if (!strcmp(infostr[i].cliname, name))
            return i;
    }
    return -1;
}

//populate rooms with multicast addr

void populateroom() {
    int x[4] = {224, 0, 0, 0}, i;
    char msg[] = "#adm#:-1:srvrst";
    for (i = 0; i < MAXROOMS; i++) {
        (x[3] = (++x[3]) % 255) ? 0 :
                (x[2] = (++x[2]) % 255) ? 0 :
                (x[1] = (++x[1]) % 255) ? 0 :
                x[0]++;
        mrooms[i].roomaddr = (char *) malloc(16 * sizeof (char));
        sprintf(mrooms[i].roomaddr, "%d.%d.%d.%d", x[0], x[1], x[2], x[3]);
        mrooms[i].inuse = 0;
        mrooms[i].numusers = 0;
        infostr[i].inuse = 0;
        infostr[i].room = -1;
        sendpkt(mrooms[i].roomaddr, msg, SENDPORT);
    }
}

//generator thread fn

void *threcvfn(void *targs) {
    int rcvfd, rcvlen, qlen;
    char rcvline[MAXBUF], *ipaddr;
    struct sockaddr_in rcvaddr;
    socklen_t slen;
    job *producer;
    job_queue = stralloc();
    sem_post(&semjoballocation);
    producer = job_queue;

    if (pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL) != 0)
        progerror("cancel state could not be set!");
    rcvfd = createsocket(&rcvaddr, "any", RECVPORT, UDP, B_YES);
    //start receiving
    while (1) {
        if ((rcvlen = recvfrom(rcvfd, rcvline, MAXBUF, 0, (struct sockaddr *) & rcvaddr, &slen)) == -1)
            progerror("recv	error");
        //printf("hex addr or rcv pkt = %x\n", rcvaddr.sin_addr.s_addr);
        rcvline[rcvlen] = '\0';
        sem_getvalue(&sem1, &qlen);
        if (qlen > 20) {
            printf("queue full, msg dropped!\n");
            continue;
        }
        //lock mutex so that worker thread doesnt access
        pthread_mutex_lock(&job_mutex);
        producer->qcmsg = rcvline;
        if ((ipaddr = inet_ntop(AF_INET, &rcvaddr.sin_addr, producer->cliaddr, (16 * sizeof (char)))) == NULL)
            progerror("inet_ntop error");
        printf("Ip address of rcvd pkt is %s\n", ipaddr);
        producer->next = stralloc();
        producer = producer->next;
        pthread_mutex_unlock(&job_mutex);
        printf("added new msg to queue: %s\n", rcvline);
        sem_post(&sem1);
    }
}

//hendle /exitroom from user

void removeuserfromroom(char *cbuf) {
    char *delimiter = ":", *token, pkt[20];
    int id, roomnum;
    token = strtok(cbuf, delimiter);
    token = strtok(NULL, delimiter);
    id = (int) strtol(token, NULL, 10); //parse client id from msg
    roomnum = infostr[id].room;
    removeuserfromroomlist(id, roomnum);
    infostr[id].room = -1;
    sprintf(pkt, "#adm#:%d:drop", id);
    sendpkt(infostr[id].cliipaddr, pkt, SENDPORT);
}

//handle /disconnect from user(remove user from db &| from room)

void disconnectuser(char *rcvmsg, char *ip) {
    char *delimiter = ":", *token, pkt[20];
    int id, roomnum;
    //printf("in disconnectuser()\n");
    token = strtok(rcvmsg, delimiter);
    token = strtok(NULL, delimiter);
    id = (int) strtol(token, NULL, 10); //parse client id from msg
    //printf("cliid = %d", id);
    infostr[id].inuse = 0;
    free(infostr[id].cliname);
    free(infostr[id].cliipaddr);
    roomnum = infostr[id].room;
    if (roomnum != -1) {
        infostr[id].room = -1;
        removeuserfromroomlist(id, roomnum);
        sprintf(pkt, "#adm#:%d:drop", id);
        sendpkt(ip, pkt, SENDPORT);
}
}
//handle /nick from user

void namechange(char *cbuf) {
    char *token, *delimiter = ":", pkt[MAXBUF];
    int id;
    token = strtok(cbuf, delimiter);
    token = strtok(NULL, delimiter);
    id = (int) strtol(token, NULL, 10); //parse client id from msg
    token = strtok(NULL, delimiter);
    if(finduser(token) != -1)
        sprintf(pkt, "#adm#:%d:name:#", id); //name exists, retain name
    else { //change name to desired one
        free(infostr[id].cliname);
        infostr[id].cliname = (char *) malloc(strlen(token) * sizeof(char));
        strcpy(infostr[id].cliname, token);
        sprintf(pkt, "#adm#:%d:name:%s", id, token);
    }
    sendpkt(infostr[id].cliipaddr, pkt, SENDPORT);
}

//send list of users in current room

void listusers(char *cbuf) {
    char *token, *delimiter = ":", pkt[MAXBUF];
    int id, roomn, i, j = 0;
    token = strtok(cbuf, delimiter);
    token = strtok(NULL, delimiter);
    id = (int) strtol(token, NULL, 10); //parse client id from msg
    roomn = infostr[id].room;
    sprintf(pkt, "#adm#:%d:users:%d", id, mrooms[roomn].numusers);
    for (i = 0; i < mrooms[roomn].numusers; i++) {
        while (*(mrooms[roomn].clientlist + j) == 0)
            j++;
        //printf("cli name being appended is %s\n", infostr[j].cliname);
        strcat(pkt, ":");
        strcat(pkt, infostr[j].cliname);
        j++;
    }
    //printf("in listusers(), pkt being sent is %s\n", pkt);
    sendpkt(infostr[id].cliipaddr, pkt, SENDPORT);
}

//handle /getip

void getipofcli(char *cbuf, char *ipaddr) {
    int pmid = -1;
    char pkt[MAXBUF], *token, *delimiter = ":", *idstr;
    token = strtok(cbuf, delimiter);
    idstr = strtok(NULL, delimiter);
    token = strtok(NULL, delimiter);
    pmid = finduser(token);
    if (pmid == -1)
        sprintf(pkt, "#adm#:%s:pmip:nosuchuser", idstr);
    else
        sprintf(pkt, "#adm#:%s:pmip:%s:%s", idstr, infostr[pmid].cliname, infostr[pmid].cliipaddr);
    sendpkt(ipaddr, pkt, SENDPORT);
}

//handle /connect from user

int connectuser(char *ipaddr, char *name) {
    char pkt[30], rid[MAXNAMELEN];
    int cid;
    struct timeval tv;
    cid = findfreeuserslot(); //get index of first free cliinfostr
    printf("id assigned is - %d\n", cid);
    if (cid == -1) //all client slots full
    {
        sprintf(pkt, "#adm#:-1:clientsfull");
        sendpkt(ipaddr, pkt, SENDPORT);
        return -1;
    }
    crandgen(rid);
    sprintf(pkt, "#adm#:-1:name:%s", rid);
    usleep(500000);
    sendpkt(ipaddr, pkt, SENDPORT);
    usleep(500000);
    sprintf(pkt, "#adm#:-1:id:%d", cid);
    sendpkt(ipaddr, pkt, SENDPORT);
    if(name != NULL)
        strcpy(name, rid);
    gettimeofday(&tv, NULL);
    infostr[cid].lastping = tv.tv_sec;
    filluserinfo(cid, rid, ipaddr);

    return cid;
}

//handle /join from user

void joinuser(char *cbuf, char *ipaddr) {
    char multiaddr[16], pkt[30], *token, *delimiter = ":";
    int cid, roomn;
    BOOL newuser = TRUE;
    char rid[MAXNAMELEN];
    token = strchr(cbuf, ':');
    if(token !=NULL) {
        token = strtok(cbuf, delimiter);
        token = strtok(NULL, delimiter);
        cid = (int) strtol(token, NULL, 10); //parse client id from msg
        newuser = FALSE;
    }
    else {
        cid = connectuser(ipaddr, rid);
        if(cid == -1)
            return;
    }
    roomn = getmultiaddr(cbuf, multiaddr, cid);
    if (!strcmp(multiaddr, "roomsfull")) //room limit reached
    {
        sprintf(pkt, "#adm#:-1:roomsfull");
        sendpkt(ipaddr, pkt, SENDPORT);
        return;
    }
    addusertoroomlist(cid, roomn);
#ifdef TRACEPRINT
    printf("TP:in process_job(), got multicast addr\n");
#endif
    printf("Allocated %s to %s\n", multiaddr, ipaddr);
    sprintf(pkt, "#adm#:%d:addr:%s", cid, multiaddr);
    sendpkt(ipaddr, pkt, SENDPORT);
    infostr[cid].room = roomn;
    usleep(500000);
    sprintf(pkt, "#adm#:%d:inroom", cid);
    sendpkt(ipaddr, pkt, SENDPORT);
#ifdef TRACEPRINT
    printf("TP:in process_job(), packet sent\n");
#endif
}

//process received messages

int process_job(char *cbuf, char *ipaddr) {
#ifdef TRACEPRINT
    printf("TP:in process_job()\n");
#endif
    //printf("message received is %s\n", cbuf);
    if (!strcmp(cbuf, "/connect"))
        connectuser(ipaddr, NULL);
    else if (!strncmp(cbuf, "/joinroom", 9))
        joinuser(cbuf, ipaddr);
    else if (!strncmp(cbuf, "/exit", 5))
        disconnectuser(cbuf, ipaddr);
    else if (!strncmp(cbuf, "/leaveroom", 9))
        removeuserfromroom(cbuf);
    else if (!strncmp(cbuf, "/listusers", 10))
        listusers(cbuf);
    else if (!strncmp(cbuf, "/getip", 6))
        getipofcli(cbuf, ipaddr);
    else if (!strncmp(cbuf, "#pingreply#", 11))
        pinghandler(cbuf);
    else if (!strncmp(cbuf, "/nick", 5))
        namechange(cbuf);
    else if (!strcmp(cbuf, "!@quit"))
        return 1;

    return 0;
}

//worker function

void job_worker() {
    int qval;
    char *getline, *cliipaddr;
    job *consumer, *job_free;
    sem_wait(&semjoballocation);
    consumer = job_queue;
    while (1) {

        //wait for job
        sem_wait(&sem1);
        //lock mutex for getting next job
        job_free = consumer;
#ifdef TRACEPRINT
        printf("TP:in job_worker(), msg rcvd:%s\n", consumer->qcmsg);
#endif
        pthread_mutex_lock(&job_mutex);
        getline = consumer->qcmsg;
        cliipaddr = consumer->cliaddr;
        consumer = consumer->next;
        pthread_mutex_unlock(&job_mutex);
        qval = process_job(getline, cliipaddr);
        if (qval == 1)
            break;
        strfree(job_free);
    }
}
