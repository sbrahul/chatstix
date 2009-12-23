/* 
 * File:   CStixThreadType.h
 * Author: rahul
 *
 * Created on December 4, 2009, 9:17 PM
 */

#ifndef _CSTIXTHREAD_H
#define	_CSTIXTHREAD_H
#include "CStixIncludes.h"

typedef void* (*ThreadEntryFunction) (void*);
typedef pthread_t ThreadID;

class CStixThread {

private:
    ThreadID thid;
    ThreadEntryFunction function;

public:
    ThreadEntryFunction getThreadEntryFunction();
    void setThreadEntryFunction(ThreadEntryFunction fn);
    ThreadID getThreadID();
    void setThreadID(ThreadID tid);
};

#endif	/* _CSTIXTHREAD_H */

