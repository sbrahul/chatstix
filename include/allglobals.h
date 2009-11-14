#ifndef ALLGLOBALS_H_
#define ALLGLOBALS_H_
#include "alltypedefs.h"

extern int gsendfd; //socket to send data
extern clientstate gflagstatus; //to keep track of room status
extern int cliid; // client id assigned by server
extern char *gservaddr; //address of chat server
extern char *rndname; //buffer to store rnd name assigned by server
extern char gmcastaddr[16]; //address of mcast assigned by server
extern sem_t semforpm; //used to wait till IP addr of user to PM is rcvd from server
extern clientcache clicache; //struct to cache data

#endif /*ALLGLOBALS_H_*/
