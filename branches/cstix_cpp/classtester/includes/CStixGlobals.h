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

class CStixGlobals {
public:
    static CStixMessageQ *getJobQueue();
    static CStixSemaphore sem1;
private:
    static CStixMessageQ *jobQueue;
};

#endif	/* _CSTIXGLOBALS_H */

