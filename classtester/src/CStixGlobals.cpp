/* 
 * File:   CStixGlobals.cpp
 * Author: rahul
 * 
 * Created on December 5, 2009, 7:29 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

CStixMessageQ* CStixGlobals::getJobQueue() {
    return CStixGlobals::jobQueue;
}

/*
 * Static initializations
 */

CStixMessageQ* CStixGlobals::jobQueue = new CStixMessageQ();
CStixSemaphore CStixGlobals::sem1;
CStixServer    CStixGlobals::server;

