#include "../include/sockheads.h"

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
    char pkt[20], *token, *delimit = " ";
    struct sockaddr_in sendaddr;
    if (!strcmp(input, "/quit")) {
        if (gflagstatus == inroom) {
            sprintf(pkt, "/disconnect:%d", cliid);
            sendpkt(gservaddr, pkt, SERVPORT);
        }
        gflagstatus = exitprog;
        return 1; //exit prog
    } else if (!strncmp(input, "/join ", 6)) {
        if (strlen(input) < 9) {
            printf("Min room name length is 3!\n");
            return 0;
        }
        if (!gsendfd)
            gsendfd = createsocket(&sendaddr, "any", SERVPORT, UDP, B_NO);
        if (gflagstatus == notinroom)
            sendpkt(gservaddr, input, SERVPORT);
        else
            printf("Already in a room. Disconnect from present to join another\n");
    } else if (!(strncmp(input, "/disconnect", 11))) {
        if (gflagstatus == notinroom) {
            printf("You are not in any room!\n");
            return 0;
        }
        sprintf(pkt, "/disconnect:%d", cliid);
        sendpkt(gservaddr, pkt, SERVPORT);
    } else if (!strcmp(input, "/listusers")) {
         if(gflagstatus == inroom) {
            sprintf(pkt, "/listusers:%d", cliid);
            sendpkt(gservaddr, pkt, SERVPORT);
         }
         else
             printf("This command can only be used once inside a room\n");
    } else if (!(strncmp(input, "/pm ", 4)) && strlen(input) > 5) {
        if(gflagstatus == inroom) {
        token = strtok(input, delimit);
        token = strtok(NULL, delimit);
        if (strlen(token) < 3 || strlen(token) > MAXNAMELEN) {
            printf("Invalid username! Please try again\n");
            return 0;
        }
        if (strcmp(clicache.lastpmname, token)) {
            sprintf(pkt, "/getip:%d:%s", cliid, token);
            sendpkt(gservaddr, pkt, SERVPORT);
            sem_wait(&semforpm);
            if(clicache.lastpmerror)
                return 0;
        }
        token = input + 10;
        sprintf(pkt, "#pm#:%s:%s", rndname, token);
        sendpkt(clicache.lastpmip, pkt, MRECVPORT);
        }
        else
             printf("This command can only be used once inside a room\n");
    } else if (!strncmp(input, "/nick ", 6)) {
        if(strlen(input) < 9 || strlen(input) > 16) {
            printf("Min length of name is 3, max is 10\n");
            return 0;
        }
        token = strtok(input, delimit);
        token = strtok(NULL, delimit); //get name from input
        if (!strcmp(token, rndname))
            return 0; //if same name, dont do anything
        sprintf(pkt, "/nick:%d:%s", cliid, token);
        sendpkt(gservaddr, pkt, SERVPORT);
    } else if (!strncmp(input, "/help", 5))
        printf("/join <room_name>\n/listusers\n/pm <user_name> <msg>\n"
                "/nick <nick_name>\n/disconnect\n/quit\n");
    else if (!strcmp(input, "!#quit")) {
        if (!gsendfd)
            gsendfd = createsocket(&sendaddr, "any", SERVPORT, UDP, B_NO);
        sendpkt(gservaddr, input, SERVPORT);
    } else
        printf("Invalid command. type /help for help\n");

    return 0; //prog not exiting
}

//parse received string

void parseandprint(char *str, int *recvfd) {
    char *search = ":", *token, buffer[MAXCLI];
    BOOL colonflag = 0, admflag = 0;
    int id;
    token = strtok(str, search);
    while (token != NULL) {
        if (!strcmp(token, "#adm#")) {
            token = strtok(NULL, search);
            admflag = 1;
            id = strtol(token, NULL, 10);
            if (id != -1)
                if(id != cliid)
                    break;
            token = strtok(NULL, search);
            if (!strcmp(token, "addr")) {
                token = strtok(NULL, search);
                printf("Multicast addr assigned is - %s\n", token);
                add_memship(recvfd, token, TRUE);
                strcpy(gmcastaddr, token);
                break;
            } else if (!strcmp(token, "drop")) {
                add_memship(recvfd, gmcastaddr, FALSE);
                printf("Disconnected from current room\n");
                gflagstatus = notinroom;
                if (close(gsendfd) == -1)
                    progerror("close send error");
                gsendfd = 0;
                break;
            } else if (!strcmp(token, "name")) {
                token = strtok(NULL, search);
                if (rndname != NULL) {
                    if(!strcmp(token, rndname)) {
                        printf("Name already taken!\n");
                        break;
                    }
                    free(rndname);
                }
                rndname = (char *) malloc((sizeof(char)) * (strlen(token)));
                strcpy(rndname, token);
                printf("Name changed to - %s\n", token);
                break;
            } else if (!strcmp(token, "id")) {
                token = strtok(NULL, search);
                //printf("Assigned id is - %s\n", token);
                cliid = (int) strtol(token, NULL, 10);
                gflagstatus = inroom;
                printf("You can now start chatting\n");
                break;
            } else if (!strcmp(token, "roomsfull")) {
                printf("All rooms full! PLease try after some time\n");
                break;
            } else if (!strcmp(token, "clientsfull")) {
                printf("Too many users! Please try after some time\n");
                break;
            } else if (!strcmp(token, "users")) {
                token = strtok(NULL, search);
                printf("Number of users in room = %ld\n", strtol(token, NULL, 10));
                printf("Users are:");
                fflush(stdout);
                colonflag = 1;
                admflag = 0;
            } else if (!strcmp(token, "pmip")) {
                token = strtok(NULL, search);
                if(!strcmp(token, "nosuchuser")) {
                    printf("Sorry, no such username exists\n");
                    clicache.lastpmerror = 1;
                    sem_post(&semforpm);
                    break;
                }
                strcpy(clicache.lastpmname, token);
                token = strtok(NULL, search);
                strcpy(clicache.lastpmip, token);
                clicache.lastpmerror = 0;
                sem_post(&semforpm);
            } else if (!strcmp(token, "srvrst")) {
                if(gflagstatus == notinroom)
                    break;
                add_memship(recvfd, gmcastaddr, FALSE);
                printf("Connection to server reset! Disconnected from current room\n");
                gflagstatus = notinroom;
                if (close(gsendfd) == -1)
                    progerror("close send error");
                gsendfd = 0;
                break;
            } else if (!strcmp(token, "ping")) {
                pinghandler();
                break;
            }
        } else if(!strcmp(token, "#pm#")) {
            printf("---PM---> ");
            fflush(stdout);
        }
        else {
            (colonflag == 0) ?
                    sprintf(buffer, "%s:", token) :
                    sprintf(buffer, " %s", token);
            printf("%s", buffer);
            fflush(stdout);
            colonflag = 1;
        }
        token = strtok(NULL, search);
    }
    if(!admflag)
        printf("\n");
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
        if ((rcvlen = recvfrom(recvfd, rcvline, MAXBUF, 0, (struct sockaddr *) & recvaddr, &len)) == -1)
            progerror("recv error");
        //	printf("after recv\n");
        rcvline[rcvlen] = '\0';
        parseandprint(rcvline, &recvfd);
        //printf("%s\n", rcvline);
    }
}

//main working function

void worker() {
    char sendline[MAXCLI + MAXNAMELEN], *replace, usrstr[MAXCLI];
    BOOL returnstatus;
    printf("Welcome. Enter commands (/help for help)\n");
    while (1) {
        fgets(usrstr, MAXCLI, stdin);
        //printf("entered string is %s\n", usrstr);
        replace = strchr(usrstr, '\n'); //replace newline char with null char
        if (replace == NULL)
            usrstr[MAXCLI - 1] = '\0'; //if !newline then replace last char with null
        else
            *replace = '\0';
        replace = strchr(usrstr, ':'); //no : allowed
        if (replace != NULL) {
            printf("Sorry, No usage of ':' allowed\n");
            continue;
        }
        strcpy(clicache.lasttypedmsg, usrstr);
        if (gflagstatus == notinroom || *usrstr == '/' || *usrstr == '!') {
            returnstatus = servcommand(usrstr);
            if (returnstatus == 0)
                continue; //dont send command thru multicast, just continue loop
        }
        //printf("after replace, entered string is %s\n", usrstr);
        if (gflagstatus == exitprog)
            break;
        sprintf(sendline, "%s:%s", rndname, usrstr);
        sendpkt(gmcastaddr, sendline, MRECVPORT);
    }
}