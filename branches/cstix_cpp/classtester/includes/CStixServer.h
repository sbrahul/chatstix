/* 
 * File:   CStixServer.h
 * Author: gnarayan
 *
 * Created on December 24, 2009, 12:20 PM
 *
 * Entry point class.
 *
 */

#ifndef _CSTIXSERVER_H
#define	_CSTIXSERVER_H

#include "../includes/CStixCallbacks.h"
#include "../includes/CStixCommunications.h"
#include "../includes/CStixMessageParser.h"
//#include "../includes/CStixUserManager.h"
#include "../includes/CStixTypedefs.h"

class CStixServer {
public:
    CStixServer();
    CStixServer(const CStixServer& orig);
    void run();
    void init();
    void exit();
    virtual ~CStixServer();
private:
    friend class CStixCallbacks;
    CStixCommunications *ccomms;
    CStixMessageParser *msgparser;
    //CStixUserManager    *usermgr;
    callback_v2str *loginCB;
    callback_v1csmsg *msgrcvCB;

    void RegisterCallbacks();
};

#endif	/* _CSTIXSERVER_H */

