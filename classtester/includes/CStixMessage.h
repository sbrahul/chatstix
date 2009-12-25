/* 
 * File:   CStixMessage.h
 * Author: gnarayan
 *
 * Created on December 24, 2009, 2:24 PM
 */

#ifndef _CSTIXMESSAGE_H
#define	_CSTIXMESSAGE_H

#include <string>
using namespace std;

class CStixMessage {
public:
    CStixMessage();
    CStixMessage(string &msg);
    CStixMessage(const CStixMessage& orig);
    string getMessageString();
    virtual ~CStixMessage();
private:
    friend ostream& operator<<(ostream& output, const CStixMessage& csmsg);
    string msg;
};

#endif	/* _CSTIXMESSAGE_H */

