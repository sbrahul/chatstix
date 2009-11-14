#ifndef ALLTYPEDEFS_H_
#define ALLTYPEDEFS_H_

#include "allhashdefines.h"


typedef int BOOL;
typedef enum {
	notinroom = 0,
	inroom = 1,
	exitprog = -1
}clientstate;
typedef struct _clientcache
{
    char lastpmname[MAXNAMELEN];
    char lastpmip[16];
    int lastpmerror;
    char lasttypedmsg[MAXCLI];
}clientcache;

#endif /*ALLTYPEDEFS_H_*/
