/* 
 * File:   alltypedefs.h
 * Author: rahul
 *
 * Created on November 7, 2009, 1:57 PM
 */

#ifndef ALLTYPEDEFS_H_
#define ALLTYPEDEFS_H_

typedef int BOOL;
//linked list for storing msges recevied
typedef struct _job
{
	char *qcmsg; //msg received
	char *cliaddr; //ip address from which msg received
	struct _job *next; //link to next job
}job;

//client info struct
typedef struct _cliinfostr
{
	BOOL inuse; //indicates whether client id is in use or not
	int room; //room number corresponding to index of mrooms array
	char *cliname; //random name generated
        char *cliipaddr;
        long lastping;
}cliinfostr;

//struct for keeping track of rooms
typedef struct _mcastrooms
{
	BOOL inuse; //indicates whether room is in use or not
	char *roomname; //room name
	char *roomaddr; //multicast addr of room
	int *clientlist; //list of clients in that room
	int numusers; //number of users in the room
}mcastrooms;

#endif /*ALLTYPEDEFS_H_*/