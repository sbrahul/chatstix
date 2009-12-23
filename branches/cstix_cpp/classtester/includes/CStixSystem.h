/* 
 * File:   testClass.h
 * Author: rahul
 *
 * Created on December 4, 2009, 12:01 AM
 */

#ifndef _CSTIXSYSTEM_H
#define	_CSTIXSYSTEM_H
#include "CStixIncludes.h"
#include "CStixThread.h"
#include "CStixSemaphore.h"

class CStixSystem {
public:
    static void StartThread(CStixThread &thvar);
    static void WaitForThread(CStixThread &thvar);
    static void KillThread(CStixThread &thvar);
    static void InitializeSem(CStixSemaphore &semvar, int initval);
    static void WaitForSem(CStixSemaphore &semvar);
    static void PostSem(CStixSemaphore &semvar);
private:
    
};

#endif	/* _CSTIXSYSTEM_H */

