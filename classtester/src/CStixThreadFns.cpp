/* 
 * File:   CStixThread.cpp
 * Author: rahul
 * 
 * Created on December 2, 2009, 8:00 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

void *threadfn(void *args) {
    string msg, ipaddr;
    CStixMessageQ *freeQ, *consumerQ;
    consumerQ = CStixGlobals::getJobQueue();
    while (1) {
        //cout << "Waiting for job\n";
        CStixSystem::WaitForSem(CStixGlobals::sem1);
        freeQ = consumerQ;
        consumerQ->GetMsgfromQ(msg, ipaddr);
        cout << "msg from q is " << msg << " and ip addr is " << ipaddr << endl;
        consumerQ = consumerQ->GetNextMsgptr();
        delete freeQ;
    }
    return NULL;
}
