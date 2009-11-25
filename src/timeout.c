#include "../includes/sockheads.h"

void alrmhandler() {
    int i, diff;
    char pingmsg[] = "#adm#:-1:ping", discmsg[15];
    struct timeval tv;
    for(i = 0; i < MAXCLIENTS; i++) { //for every client
        if(!infostr[i].inuse) //if index not in use, skip
            continue;
        gettimeofday(&tv, NULL); //get current time
        diff = tv.tv_sec - infostr[i].lastping; //find time from last ping reply
        if (diff > (2 * TIMEOUTVAL)) { //if diff more than twice timeout, user is gone
            sprintf(discmsg, "/disconnect:%d", i);
            disconnectuser(discmsg, infostr[i].cliipaddr); //remove user from database
            printf("User %d timed out!\n", i);
            continue;
        }
        sendpkt(infostr[i].cliipaddr, pingmsg, SENDPORT); //send ping packet
    }
}

void setalarm() {
    struct itimerval it;
    struct sigaction sa;
    memset(&it, 0, sizeof(it));
    memset(&sa, 0, sizeof(sa));
    it.it_value.tv_sec = TIMEOUTVAL; //set alarm time
    it.it_interval.tv_sec = TIMEOUTVAL; //set repetition interval
    sa.sa_handler = &alrmhandler; //signal handler
    sa.sa_flags = SA_RESTART; //to restart interrupted blocking fn (recvfrom)
    sigemptyset(&sa.sa_mask); //ditto
    sigaction(SIGALRM, &sa, NULL); //use sigalrm
    setitimer(ITIMER_REAL, &it, NULL); //set timer
    printf("Alarm set!\n");
}

void pinghandler(char *input) {
    struct timeval tv;
    char *token, *delimit = ":";
    int id;
    token = strtok(input, delimit);
    token = strtok(NULL, delimit);
    id = (int) strtol(token, NULL, 10); //get id from ping reply
    gettimeofday(&tv, NULL);
    infostr[id].lastping = tv.tv_sec; //update lastping with current time
}