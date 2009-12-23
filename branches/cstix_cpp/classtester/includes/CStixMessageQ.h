/* 
 * File:   CStixMessageQ.h
 * Author: rahul
 *
 * Created on December 2, 2009, 6:52 PM
 */

#ifndef _CSTIXMESSAGEQ_H
#define	_CSTIXMESSAGEQ_H
#include "CStixIncludes.h"

class CStixMessageQ {
private:
    string Message;
    string CliIPAddr;
    CStixMessageQ *NextMessagePtr;

public:
    CStixMessageQ *GetNextMsgptr();
    void AddMsgtoQ(string msg, string ipaddr);
    void GetMsgfromQ(string &msg, string &ipaddr);
};

#endif	/* _CSTIXMESSAGEQ_H */

