/* 
 * File:   CStixUser.h
 * Author: rahul
 *
 * Created on December 23, 2009, 4:22 PM
 */

#ifndef _CSTIXUSER_H
#define	_CSTIXUSER_H
#include "CStixIncludes.h"

class CStixUser {
private:
    string roomname; //room nname corresponding to index of mrooms array
    string username; //name of user
    string useripaddr; //ip addr of user
    long lastping; //time of last keepalive reply received
    friend ostream & operator<<(ostream &, const CStixUser &); //overload << operator

public:
    CStixUser();
    CStixUser(string username);
    CStixUser(string username, string ipaddr);
    void SetRoomName(string name);
    void SetUserName(string name);
    void SetIpAddr(string ipaddr);
    void SetLastPing(long pingtime);
    string GetRoomName();
    string GetUserName();
    string GetIpAddr();
    long GetLastPing();
    int operator==(const CStixUser &rhs) const;
};

#endif	/* _CSTIXUSER_H */

