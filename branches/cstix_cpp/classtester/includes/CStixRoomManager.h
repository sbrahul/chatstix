/* 
 * File:   CStixRoomManager.h
 * Author: rahul
 *
 * Created on December 20, 2009, 1:54 PM
 */

#ifndef _CSTIXROOMMANAGER_H
#define	_CSTIXROOMMANAGER_H
#include "CStixIncludes.h"

class CStixRoomManager {
public:
    CStixRoomManager();
    ~CStixRoomManager();
    int CreateRoom(string roomname, string roomaddr);
    int DeleteRoom(string roomname);
    int AddUserToRoom(string username, string roomname);
    int RemoveUserFromRoom(string username, string roomname);
    int DoesRoomExist(string roomname);
    string ListUsersinRoom(string roomname);

private:
    CStixAbstractList<CStixChatRoom> *chatrooms;
    int numofrooms;

};

#endif	/* _CSTIXROOMMANAGER_H */

