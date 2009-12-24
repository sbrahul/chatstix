/* 
 * File:   CStixUserManager.h
 * Author: rahul
 *
 * Created on December 23, 2009, 4:45 PM
 */

#ifndef _CSTIXUSERMANAGER_H
#define	_CSTIXUSERMANAGER_H
#include "CStixIncludes.h"

class CStixUserManager {
public:
    CStixUserManager();
    ~CStixUserManager();
    int CreateUser(string username, string ipaddr);
    int DeleteUser(string username);
    int DoesUserExist(string name);
    int ChangeUsername(string oldname, string newname);
    int ChangeRoom(string username, string roomname);
    void ListAllUsers();

private:
    CStixAbstractList<CStixUser> *users;
    int numofusers;

};

#endif	/* _CSTIXUSERMANAGER_H */

