/* 
 * File:   allfnprotos.h
 * Author: rahul
 *
 * Created on November 7, 2009, 1:56 PM
 */

#ifndef ALLFNPROTOS_H_
#define ALLFNPROTOS_H_
#include "alltypedefs.h"

int createsocket(struct sockaddr_in *saddr, char *caddr, int iport, int stype, int bopt);
void progerror(char *errorstr);
job *stralloc();
void strfree(job *job_free);
void crandgen(char *rid);
void sendpkt(char *caddr, char *msg, int port);
int findroom(char *roomname, int *roomnum);
void createroom(char *rname, int rnum);
int findfreeuserslot();
int getmultiaddr(char *cbuf, char *addr, int clientid);
void filluserinfo(int cid, int roomn, char *rid, char *ipaddr);
void addusertoroomlist(int cid, int roomn);
int removeuserfromroomlist(int cid, int roomn);
void populateroom();
void disconnectuser(char *rcvmsg, char *ip);
void listusers(char *cbuf);
void getipofcli(char *cbuf, char *ipaddr);
void joinuser(char *cbuf, char *ipaddr);
int process_job(char *cbuf, char *ipaddr);
void job_worker();
void *threcvfn(void *targs);

#endif /*ALLFNPROTOS_H_*/