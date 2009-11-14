#include "../include/sockheads.h"

int gsendfd = 0; //socket to send data
clientstate gflagstatus; //to keep track of room status
int cliid; // client id assigned by server
char *gservaddr; //address of chat server
char *rndname; //buffer to store rnd name assigned by server
char gmcastaddr[16]; //address of mcast assigned by server
clientcache clicache; //struct to cache data
sem_t semforpm; //used to wait till IP addr of user to PM is rcvd from server
