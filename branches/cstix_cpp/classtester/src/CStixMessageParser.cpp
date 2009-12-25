/* 
 * File:   CStixMessageParser.cpp
 * Author: gnarayan
 * 
 * Created on December 24, 2009, 12:27 PM
 */

#include "../includes/CStixMessageParser.h"
#include <iostream>
using namespace std;

CStixMessageParser::CStixMessageParser() {

}

void CStixMessageParser::registerLoginCallback(callback_v2str* loginCB) {
    this->loginCB = loginCB;
}

void CStixMessageParser::parseMessage(CStixMessage message) {
    cout << message << endl;
    (*loginCB)("username", "ip address");
}
