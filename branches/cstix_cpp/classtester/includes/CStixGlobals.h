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
#include <iostream>
#include <map>
using namespace std;
#include <setjmp.h>

#define SHUTDOWN_CLEAN                  0
#define SHUTDOWN_NPE                    1
#define SHUTDOWN_THREADCREATIONERROR    2
#define SHUTDOWN_THREADJOINERROR        3
#define SHUTDOWN_THREADCANCELERROR      4
#define SHUTDOWN_SEMAPHOREINITERROR     5
#define SHUTDOWN_SOCKETCREATIONERROR    6
#define SHUTDOWN_PTONERROR              7
#define SHUTDOWN_SENDERROR              8
#define SHUTDOWN_SOCKETCLOSEERROR       9

class CStixGlobals {
public:
    static CStixMessageQ *getJobQueue();
    static CStixSemaphore sem1;
    static CStixServer server; // The server instance.
    static int errorcode;
    static jmp_buf environment; // For long jumps

    static void init();
    static string GetVerboseError();
    static void PrintVerboseError(ostream& out);
private:
    static CStixMessageQ *jobQueue;
    static map<int, string> errormap;
};

#endif	/* _CSTIXGLOBALS_H */

