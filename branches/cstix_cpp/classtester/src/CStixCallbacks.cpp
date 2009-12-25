/* 
 * File:   CStixCallbacks.cpp
 * Author: gnarayan
 * 
 * Created on December 24, 2009, 12:15 PM
 *
 * Contains a list of callback definitions to be used for registration.
 * This is a friend of CStixServer. The design may be rehashed in the future.
 *
 */

#include "../includes/CStixCallbacks.h"
#include "../includes/CStixGlobals.h"
#include <iostream>
using namespace std;

CStixCallbacks::CStixCallbacks() {
}

CStixCallbacks::CStixCallbacks(const CStixCallbacks& orig) {
}

CStixCallbacks::~CStixCallbacks() {
}

void CStixCallbacks::LoginCallback(string s1, string s2) {
    cout << s1 << s2 << endl;
}

void CStixCallbacks::MsgRecvCallback(CStixMessage& msg) {
    cout << msg << endl;
    (CStixGlobals::server).msgparser->parseMessage(msg);
    //string s("lll");
    //return s;
}