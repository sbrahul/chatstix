/* 
 * File:   CStixChatRoom.h
 * Author: rahul
 *
 * Created on December 19, 2009, 4:16 PM
 */

#ifndef _CSTIXCHATROOM_H
#define	_CSTIXCHATROOM_H
#include "CStixIncludes.h"

class CStixChatRoom {

private:
    string roomname; //room name
    string roomaddr; //multicast addr of room
    CStixAbstractList<string> *clientlist; //list of clients in that room
    int numusers; //number of users in the room
    void IncreaseUsers();
    void DecreaseUsers();
    friend ostream &operator<<(ostream &, const CStixChatRoom &);


public:
    CStixChatRoom();
    ~CStixChatRoom();
    string GetRoomName();
    string GetRoomAddr();
    int GetNumOfUsers();
    void SetRoomName(string name);
    void SetRoomAddr(string addr);
    void AddToClientList(string name);
    void RemoveFromClientList(string name);
    string ListUsers();
    int operator==(const CStixChatRoom &rhs) const;
};

#endif	/* _CSTIXCHATROOM_H */

