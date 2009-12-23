/* 
 * File:   CStixMessageQ.cpp
 * Author: rahul
 * 
 * Created on December 2, 2009, 6:52 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

void CStixMessageQ::AddMsgtoQ(string msg, string ipaddr) {
    this->Message = msg;
    this->CliIPAddr = ipaddr;
    this->NextMessagePtr = new CStixMessageQ;
}

void CStixMessageQ::GetMsgfromQ(string &msg, string &ipaddr) {
    msg = this->Message;
    ipaddr = this->CliIPAddr;
}

CStixMessageQ* CStixMessageQ::GetNextMsgptr() {
    return this->NextMessagePtr;
}

