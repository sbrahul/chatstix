#include "../include/sockheads.h"

//print wrapper

void msg_print(char *msg, MsgType type) {
    switch(type) {
        case msgtypeerr:
        case msgtypeinfo:
        case msgtypepm:
        case msgtypenorm:
            printf("%s", msg);
            break;
    }
}

//add membership to multicast addr

void add_memship(int *fd, char *addr, BOOL optval) {

    struct ip_mreq mreq;
    int loopopt = 0;
    //printf("mcast addr:%s, loop = %d\n", addr, loopopt);
    mreq.imr_multiaddr.s_addr = inet_addr(addr);
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);
    if (optval == 1) {
        if (setsockopt(*fd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof (struct ip_mreq)) == -1)
            progerror("couldnt add membership");
    } else if (optval == 0) {
        if (setsockopt(*fd, IPPROTO_IP, IP_DROP_MEMBERSHIP, &mreq, sizeof (struct ip_mreq)) == -1)
            progerror("couldnt drop membership");
    }

    if (setsockopt(*fd, IPPROTO_IP, IP_MULTICAST_LOOP, &loopopt, sizeof (int)) == -1)
        progerror("loopback disable error");

}

//send function

void sendpkt(char *addr, char *msg, int port) {
    struct sockaddr_in sendpktaddr;
    memset(&sendpktaddr, 0, sizeof (sendpktaddr));
    sendpktaddr.sin_family = AF_INET;
    if (inet_pton(AF_INET, addr, &sendpktaddr.sin_addr) == -1)
        progerror("pton error");
    sendpktaddr.sin_port = htons(port);
    if (sendto(gsendfd, msg, strlen(msg), 0, (struct sockaddr *) & sendpktaddr, sizeof (sendpktaddr)) == -1)
        progerror("sendto error");
    //printf("sent %s\n", msg);
}

//join server first

BOOL servcommand(char *input) {
    char pkt[MAXCLI], *token, *delimit = " ";
    struct sockaddr_in sendaddr;
    if (!strcmp(input, "/quit")) {
        if (gflagstatus != notinroom) {
            sprintf(pkt, "/exit:%d", cliid);
            sendpkt(gservaddr, pkt, SERVPORT);
        }
        gflagstatus = exitprog;
        return 1; //exit prog
    } else if (!strcmp(input, "/connect")) {
        if(gflagstatus == notinroom) {
            sendpkt(gservaddr, "/connect", SERVPORT);
        } else {
            msg_print("You are already connected!\n", msgtypeerr);
        }
    } else if (!strncmp(input, "/joinroom ", 10)) {
        if (strlen(input) < 13) {
            msg_print("Min room name length is 3!\n", msgtypeerr);
            return 0;
        }
        if (gflagstatus == inroom)
            msg_print("Already in a room. Disconnect from present to join"
                    " another\n", msgtypeerr);
        else {
            if(gflagstatus == availforpm)
                sprintf(pkt, "%s:%d", input, cliid);
            else
                sprintf(pkt, "%s", input);
            sendpkt(gservaddr, pkt, SERVPORT);
        }
    } else if (!(strncmp(input, "/leaveroom", 10))) {
        if (gflagstatus == availforpm) {
            msg_print("You are not in any room!\n", msgtypeerr);
            return 0;
        }
        sprintf(pkt, "/leaveroom:%d", cliid);
        sendpkt(gservaddr, pkt, SERVPORT);
    } else if (!strcmp(input, "/listusers")) {
         if(gflagstatus == inroom) {
            sprintf(pkt, "/listusers:%d", cliid);
            sendpkt(gservaddr, pkt, SERVPORT);
         }
         else
             msg_print("This command can only be used only inside a room\n", msgtypeinfo);
    } else if (!(strncmp(input, "/pm ", 4)) && strlen(input) > 8) {
        if(gflagstatus == inroom || gflagstatus == availforpm) {
        token = strtok(input, delimit);
        token = strtok(NULL, delimit);
        if (strlen(token) < 3 || strlen(token) > MAXNAMELEN) {
            msg_print("Invalid username! Please try again\n", msgtypeerr);
            return 0;
        }
        if (strcmp(clicache.lastpmname, token)) {
            sprintf(pkt, "/getip:%d:%s", cliid, token);
            sendpkt(gservaddr, pkt, SERVPORT);
            sem_wait(&semforpm);
            if(clicache.lastpmerror)
                return 0;
        }
        token = input + (strlen(rndname) + 5); //strtok cannot be used, so manually set pointer to start of msg
        sprintf(pkt, "#pm#:%s:%s", rndname, token);
        sendpkt(clicache.lastpmip, pkt, MRECVPORT);
        }
        else
             msg_print("This command can only be used once connected to server."
                     " Try /connect\n", msgtypeinfo);
    } else if (!strncmp(input, "/nick ", 6)) {
        if(strlen(input) < 9 || strlen(input) > 16) {
            msg_print("Min length of name is 3, max is 10\n", msgtypeinfo);
            return 0;
        }
        if (gflagstatus == notinroom) {
            msg_print("You must connect to the server first\n", msgtypeerr);
            return 0;
        }
        token = strtok(input, delimit);
        token = strtok(NULL, delimit); //get name from input
        if (!strcmp(token, rndname))
            return 0; //if same name, dont do anything
        sprintf(pkt, "/nick:%d:%s", cliid, token);
        sendpkt(gservaddr, pkt, SERVPORT);
    } else if (!strncmp(input, "/help", 5))
        msg_print("/connect\n/joinroom <room_name>\n/listusers\n/pm <user_name> <msg>\n"
                "/nick <nick_name>\n/leaveroom\n/quit\n", msgtypeinfo);
    else if (!strcmp(input, "!@quit")) { //backdoor to exit server (temp)
        if (!gsendfd)
            gsendfd = createsocket(&sendaddr, "any", SERVPORT, UDP, B_NO);
        sendpkt(gservaddr, input, SERVPORT);
    } else
        msg_print("Invalid command/syntax. type /help for help\n", msgtypeerr);

    return 0; //prog not exiting
}

//parse received string

void parseandprint(char *str, int *recvfd) {
    char *search = ":", *token, *buffer, *userspointer, msgbuffer[255], character[5];
    int id;

    buffer = (char *) malloc(255 * sizeof(char)); //mallocing to avoid stack overflow
    strcpy(buffer, str);

    token = strtok(str, search);

    //printf("buffer = %s\n", buffer);

    if (!strcmp(token, "#adm#")) {
        token = strtok(NULL, search);
        id = strtol(token, NULL, 10);
        if (id == -1 || id == cliid) {
            token = strtok(NULL, search);
            if (!strcmp(token, "addr")) { //copy chatroom addr
                token = strtok(NULL, search);
                sprintf(msgbuffer, "Multicast addr assigned is - %s\n", token);
                msg_print(msgbuffer, msgtypeinfo);
                add_memship(recvfd, token, TRUE);
                strcpy(gmcastaddr, token);
            } else if (!strcmp(token, "drop")) { //exit chatroom
                add_memship(recvfd, gmcastaddr, FALSE);
                msg_print("Disconnected from current room\n", msgtypeinfo);
                gflagstatus = availforpm;
            } else if (!strcmp(token, "name")) { //copy name or nickname
                token = strtok(NULL, search);
                if (strcmp(token, "#")) {
                    if (rndname != NULL)
                        free(rndname);
                    rndname = (char *) malloc((sizeof (char)) * (strlen(token)));
                    strcpy(rndname, token);
                    sprintf(msgbuffer, "Name changed to - %s\n", token);
                    msg_print(msgbuffer, msgtypeinfo);
                } else
                    msg_print("Username already exists. Please choose another"
                            "\n", msgtypeerr);
            } else if (!strcmp(token, "id")) { //copy id assigned
                token = strtok(NULL, search);
                //printf("Assigned id is - %s\n", token);
                cliid = (int) strtol(token, NULL, 10);
                gflagstatus = availforpm;
            } else if (!strcmp(token, "roomsfull")) {
                msg_print("All rooms full! PLease try after some time\n", msgtypeerr);
            } else if (!strcmp(token, "clientsfull")) {
                msg_print("Too many users! Please try after some time\n", msgtypeerr);
            } else if (!strcmp(token, "users")) { //list users in current room
                token = strtok(NULL, search);
                sprintf(msgbuffer, "Number of users in room = %ld\n", strtol(token, NULL, 10));
                msg_print(msgbuffer, msgtypeinfo);
                msg_print("Users are: ", msgtypeinfo);
                fflush(stdout);
                userspointer = buffer + 14;
                userspointer = (strchr(userspointer, ':') + 1);
                while (*userspointer != '\0') {
                    if(*userspointer == ':') {
                        userspointer++;
                        msg_print(" ", msgtypenorm);
                        continue;
                    }
                    sprintf(character, "%c", *userspointer);
                    msg_print(character, msgtypenorm);
                    userspointer++;
                }
                msg_print("\n", msgtypenorm);
            } else if (!strcmp(token, "pmip")) { //copy ipaddr of user to PM
                token = strtok(NULL, search);
                if (!strcmp(token, "nosuchuser")) {
                    msg_print("Sorry, no such username exists\n", msgtypeerr);
                    clicache.lastpmerror = 1;
                    sem_post(&semforpm);
                } else {
                strcpy(clicache.lastpmname, token);
                token = strtok(NULL, search);
                strcpy(clicache.lastpmip, token);
                clicache.lastpmerror = 0;
                sem_post(&semforpm);
                }
            } else if (!strcmp(token, "srvrst") && (gflagstatus != notinroom)) { //server got reset
                add_memship(recvfd, gmcastaddr, FALSE);
                msg_print("Connection to server reset! Disconnected from "
                        "current room\n", msgtypeerr);
                gflagstatus = notinroom;
            } else if (!strcmp(token, "ping") && gflagstatus != notinroom) { //ping
                pinghandler();
            } else if (!strcmp(token, "inroom")) { //user officially entered room
                gflagstatus = inroom;
                msg_print("You can now start chatting\n", msgtypeinfo);
            }
        }
    } else if (!strcmp(token, "#pm#")) { //received PM message
        msg_print("---PM---> ", msgtypepm);
        fflush(stdout);
        token = strtok(NULL, search);
        outputmessage(msgtypepm, token, buffer, 6);
    } else { //if nothing else, it must be a chatroom message
        if (gflagstatus != notinroom)
            outputmessage(msgtypenorm, token, buffer, 1);
    }
    free(buffer);
}

//output to console

void outputmessage(MsgType msgtype, char *name, char *message, int pointeroffset) {
    int namelen;
    char msgbuffer[255];

    namelen = strlen(name);
    sprintf(msgbuffer, "%s: %s\n", name, (message + namelen + pointeroffset));
    if (msgtype == msgtypepm)
        msg_print(msgbuffer, msgtypepm);
    else
        msg_print(msgbuffer, msgtypenorm);
    fflush(stdout);

}

void *fnthreadr(void *params) {
    int rcvlen, recvfd;
    char rcvline[MAXBUF];
    struct sockaddr_in recvaddr;
    socklen_t len;
    //printf("in thread\n");
    if (pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL) != 0)
        progerror("cancel state could not be set!");
    recvfd = createsocket(&recvaddr, "any", MRECVPORT, UDP, B_YES);
    //printf("recv sock no = %d\n", recvfd);
    while (1) {
        //	printf("before recv\n");
        len = sizeof (recvaddr);
        if ((rcvlen = recvfrom(recvfd, rcvline, MAXBUF, 0, (struct sockaddr *)
                & recvaddr, &len)) == -1)
            progerror("recv error");
        //	printf("after recv\n");
        if (!rcvlen) continue;
        rcvline[rcvlen] = '\0';
        parseandprint(rcvline, &recvfd);
        //printf("%s\n", rcvline);
    }
}

//main working function

void worker() {
    char sendline[MAXCLI + MAXNAMELEN], *replace, usrstr[MAXCLI];
    BOOL returnstatus;
    msg_print("Welcome. Enter commands (/help for help)\n", msgtypeinfo);
    while (1) {
        fgets(usrstr, MAXCLI, stdin);
        //printf("entered string is %s\n", usrstr);
        replace = strchr(usrstr, '\n'); //replace newline char with null char
        if (replace == NULL)
            usrstr[MAXCLI - 1] = '\0'; //if !newline then replace last char with null
        else
            *replace = '\0';
        if (strchr(usrstr, ':') || strchr(usrstr, '#')) {
            msg_print("Sorry, No usage of ':' or '#' allowed\n", msgtypeerr);
            continue;
        }
        strcpy(clicache.lasttypedmsg, usrstr);
        if (gflagstatus == notinroom || gflagstatus == availforpm || *usrstr ==
                '/' || *usrstr == '!') {
            returnstatus = servcommand(usrstr);
            if (gflagstatus == exitprog)
                break;
            continue; //dont send command thru multicast, just continue loop
        }
        //printf("after replace, entered string is %s\n", usrstr);
        sprintf(sendline, "%s:%s", rndname, usrstr);
        sendpkt(gmcastaddr, sendline, MRECVPORT);
    }
}
