/* 
 * File:   CStixCallbacks.h
 * Author: gnarayan
 *
 * Created on December 24, 2009, 12:15 PM
 */

#ifndef _CSTIXCALLBACKS_H
#define	_CSTIXCALLBACKS_H

#include <string>
using namespace std;

#include "../includes/CStixMessage.h"

class CStixCallbacks {
public:
    CStixCallbacks();
    CStixCallbacks(const CStixCallbacks& orig);
    virtual ~CStixCallbacks();

    void LoginCallback(string s1, string s2);
    void MsgRecvCallback(CStixMessage& csmsg);
private:
//    CStixServer svr;

};

#endif	/* _CSTIXCALLBACKS_H */

