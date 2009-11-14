#ifndef ALLFNPROTOS_H_
#define ALLFNPROTOS_H_
#include "alltypedefs.h"

int createsocket(struct sockaddr_in *saddr, char *caddr, int iport, int stype, int bopt);
void progerror(char *errorstr);
void add_memship(int *fd, char *addr, BOOL optval);
void sendpkt(char *addr, char *msg, int port);
BOOL servcommand(char *input);
void parseandprint(char *str, int *recvfd);
void *fnthreadr(void *params);
void worker();

#endif /*ALLFNPROTOS_H_*/
