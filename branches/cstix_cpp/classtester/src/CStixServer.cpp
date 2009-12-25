/* 
 * File:   CStixServer.cpp
 * Author: gnarayan
 * 
 * Created on December 24, 2009, 12:20 PM
 */

#include "../includes/CStixServer.h"
#include "../includes/CStixMessageParser.h"
#include "../includes/CStixCommunications.h"
#include "../includes/CStixGlobals.h"

#include <iostream>
#include <setjmp.h>
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

/*
 * Start receiving messages. Let the callbacks do the rest.
 */
void CStixServer::run() {
    cout << "Attempting to start server." << endl;
    bool runstate = true;
    while(runstate) {
        static int i = 0;
        int retcode = ::setjmp(CStixGlobals::environment); // Save the environment for error case jumps
        if (retcode == SHUTDOWN_CLEAN) {
            // Main processing.
            this->ccomms->ReceiveMessage();
            // Simulate error
            if (++i >= 3)
                CStixUtil::ProgError(SHUTDOWN_CLEAN);
        } else { // error code.
            // Point of loop exit.
            cout << "Retcode = " << retcode << endl;
            runstate = false; // use this only to limit runs.
        }
    }

}

void CStixServer::init() {
    this->RegisterCallbacks();   
    CStixGlobals::init(); // Initialize the globals.
}

void CStixServer::exit() {
    CStixGlobals::PrintVerboseError(cout);
}

CStixServer::~CStixServer() {
}
