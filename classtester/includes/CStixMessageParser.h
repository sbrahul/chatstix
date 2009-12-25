/* 
 * File:   CStixMessageParser.h
 * Author: gnarayan
 *
 * Created on December 24, 2009, 12:27 PM
 */

#ifndef _CSTIXMESSAGEPARSER_H
#define	_CSTIXMESSAGEPARSER_H

#include "../includes/CStixTypedefs.h"
#include <string>
using namespace std;

class CStixMessageParser {
public:
    CStixMessageParser();
    void registerLoginCallback(callback_v2str* loginCB);
    void parseMessage(CStixMessage message);
private:
    callback_v2str* loginCB;
};

#endif	/* _CSTIXMESSAGEPARSER_H */

