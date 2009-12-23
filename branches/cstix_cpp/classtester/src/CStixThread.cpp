/* 
 * File:   CStixThreadType.cpp
 * Author: rahul
 * 
 * Created on December 4, 2009, 9:17 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

void CStixThread::setThreadEntryFunction(ThreadEntryFunction fn) {
    this->function = fn;
}

ThreadEntryFunction CStixThread::getThreadEntryFunction() {
    return this->function;
}

void CStixThread::setThreadID(ThreadID tid) {
    this->thid = tid;
}

ThreadID CStixThread::getThreadID() {
    return this->thid;
}
