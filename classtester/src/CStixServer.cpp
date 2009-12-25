/* 
 * File:   CStixServer.cpp
 * Author: gnarayan
 * 
 * Created on December 24, 2009, 12:20 PM
 */

#include "../includes/CStixServer.h"
#include "../includes/CStixMessageParser.h"
#include "../includes/CStixCommunications.h"

#include <iostream>
using namespace std;

CStixServer::CStixServer() {
    this->ccomms = new CStixCommunications();
    this->msgparser = new CStixMessageParser();
    //this->usermgr = new CStixUserManager();
}

void CStixServer::RegisterCallbacks() {
    CStixCallbacks *cbs = new CStixCallbacks();

    loginCB =
            new callback_v2str(cbs, &CStixCallbacks::LoginCallback);
    msgrcvCB =
            new callback_v1csmsg(cbs, &CStixCallbacks::MsgRecvCallback);
    this->msgparser->registerLoginCallback(loginCB);
    this->ccomms->RegisterMessageReceiveCallback(msgrcvCB);   
}

void CStixServer::StartServer() {
    cout << "Attempting to start server" << endl;
    bool runstate = true;
    while(runstate) {
        InitHook(); // Start it off.
        runstate = false; // use this only to limit runs.
    }
}

/*
 * Start receiving messages. Let the callbacks do the rest.
 */
void CStixServer::InitHook() {
    this->ccomms->ReceiveMessage();
}

CStixServer::~CStixServer() {
}

