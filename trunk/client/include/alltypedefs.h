#ifndef ALLTYPEDEFS_H_
#define ALLTYPEDEFS_H_

#include "allhashdefines.h"


typedef int BOOL;

typedef enum {
    notinroom = 0,
    inroom,
    availforpm,
    exitprog = -1
} clientstate;

typedef struct _clientcache {
    char lastpmname[MAXNAMELEN];
    char lastpmip[16];
    int lastpmerror;
    char lasttypedmsg[MAXCLI];
} clientcache;

typedef enum {
    msgtypenorm = 0,
    msgtypepm = 1,
    msgtypeinfo = 2,
    msgtypeerr = 3
} MsgType;

#endif /*ALLTYPEDEFS_H_*/
