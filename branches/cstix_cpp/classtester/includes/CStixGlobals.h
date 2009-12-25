/* 
 * File:   CStixGlobals.h
 * Author: rahul
 *
 * Created on December 5, 2009, 7:29 PM
 */

#ifndef _CSTIXGLOBALS_H
#define	_CSTIXGLOBALS_H
#include "CStixIncludes.h"
#include "CStixSemaphore.h"
#include "CStixServer.h"

class CStixGlobals {
public:
    static CStixMessageQ *getJobQueue();
    static CStixSemaphore sem1;
    static CStixServer server; // The server instance.

private:
    static CStixMessageQ *jobQueue;
};

#endif	/* _CSTIXGLOBALS_H */

