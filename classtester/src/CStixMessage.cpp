/* 
 * File:   CStixMessage.cpp
 * Author: gnarayan
 * 
 * Created on December 24, 2009, 2:24 PM
 */

#include "../includes/CStixMessage.h"
#include <iostream>
using namespace std;

CStixMessage::CStixMessage() {
}

CStixMessage::CStixMessage(string& msg) {
    this->msg = msg;
}

CStixMessage::CStixMessage(const CStixMessage& orig) {
}

string CStixMessage::getMessageString() {
    return this->msg;
}
CStixMessage::~CStixMessage() {
}

ostream& operator<<(ostream& output, const CStixMessage& csmsg) {
    output << csmsg.msg;
    return output;  
}