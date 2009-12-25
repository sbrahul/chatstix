/* 
 * File:   CStixGlobals.cpp
 * Author: rahul
 * 
 * Created on December 5, 2009, 7:29 PM
 */

#include "../includes/CStixIncludes.h"
#include "../includes/CStixGlobals.h"
using namespace std;

void CStixGlobals::init() {
    errormap.insert(pair<int, string>(SHUTDOWN_CLEAN, "Clean shutdown."));
    errormap.insert(pair<int, string>(SHUTDOWN_NPE, "Null pointer errors."));
    errormap.insert(pair<int, string>(SHUTDOWN_PTONERROR, "Problems with platform to network."));
    errormap.insert(pair<int, string>(SHUTDOWN_SEMAPHOREINITERROR, "Problems with sem init."));
    errormap.insert(pair<int, string>(SHUTDOWN_SENDERROR, "Problems with send."));
    errormap.insert(pair<int, string>(SHUTDOWN_SOCKETCLOSEERROR, "Problems with socket closing."));
    errormap.insert(pair<int, string>(SHUTDOWN_SOCKETCREATIONERROR, "Problems with socket closing."));
    errormap.insert(pair<int, string>(SHUTDOWN_THREADCANCELERROR, "Problems with thread cancellation."));
    errormap.insert(pair<int, string>(SHUTDOWN_THREADCREATIONERROR, "Problems with thread creation."));
    errormap.insert(pair<int, string>(SHUTDOWN_THREADJOINERROR, "Problems with thread join."));

}

CStixMessageQ* CStixGlobals::getJobQueue() {
    return CStixGlobals::jobQueue;
}

void CStixGlobals::PrintVerboseError(ostream& out) {
    out << (errormap.find(errorcode))->second << endl;
}

string CStixGlobals::GetVerboseError() {
    return (errormap.find(errorcode))->second;
}
/*
 * Static initializations
 */

CStixMessageQ* CStixGlobals::jobQueue = new CStixMessageQ();
CStixSemaphore CStixGlobals::sem1;
CStixServer    CStixGlobals::server;
int CStixGlobals::errorcode = SHUTDOWN_CLEAN; // init.
jmp_buf CStixGlobals::environment;
map<int, string> CStixGlobals::errormap;

