/* 
 * File:   CStixCommunications.cpp
 * Author: gnarayan
 * 
 * Created on December 24, 2009, 2:19 PM
 */

#include "../includes/CStixCommunications.h"

CStixCommunications::CStixCommunications() {
}

CStixCommunications::CStixCommunications(const CStixCommunications& orig) {
}

void CStixCommunications::RegisterMessageReceiveCallback(callback_v1csmsg* msgrcvcb) {
    this->msgrcvcb = msgrcvcb;
}

void CStixCommunications::ReceiveMessage() {
    // Stub the message.
    string str("ReceivedMessage");
    CStixMessage csm(str);
    (*msgrcvcb)(csm);
}

CStixCommunications::~CStixCommunications() {
}

