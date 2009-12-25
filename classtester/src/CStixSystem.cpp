/* 
 * File:   testClass.cpp
 * Author: rahul
 * 
 * Created on December 4, 2009, 12:01 AM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

/*
 * Thread related methods
 */

void CStixSystem::StartThread(CStixThread &thvar) {
    pthread_t tid;
    if(pthread_create(&(tid), NULL, (thvar.getThreadEntryFunction()), NULL) != 0)
        CStixUtil::ProgError(SHUTDOWN_THREADCREATIONERROR);

    thvar.setThreadID(tid);
}

void CStixSystem::WaitForThread(CStixThread &thvar) {
    if(pthread_join(thvar.getThreadID(), NULL) != 0)
        CStixUtil::ProgError(SHUTDOWN_THREADJOINERROR);
}

void CStixSystem::KillThread(CStixThread &thvar) {
    if(pthread_cancel(thvar.getThreadID()) != 0)
        CStixUtil::ProgError(SHUTDOWN_THREADCANCELERROR);
}

/*
 * Semaphore related methods
 */

void CStixSystem::InitializeSem(CStixSemaphore &semvar, int initval) {
    //SemID tempsemid;
    if(sem_init(&semvar.semid, 0, initval) == -1)
        CStixUtil::ProgError(SHUTDOWN_SEMAPHOREINITERROR);

    //semvar.setSemID(tempsemid);
}

void CStixSystem::PostSem(CStixSemaphore &semvar) {
    //SemID tempsemid;
    //tempsemid = semvar.getSemID();
    //printf("posting sem addr = %x\n", semvar.getSemID());
    sem_post(&semvar.semid);
    //semvar.setSemID(tempsemid);
}

void CStixSystem::WaitForSem(CStixSemaphore &semvar) {
    //SemID tempsemid;
    //tempsemid = semvar.getSemID();
    //printf("waiting sem addr = %x\n", semvar.getSemID());
    sem_wait(&semvar.semid);
    //semvar.setSemID(tempsemid);
}