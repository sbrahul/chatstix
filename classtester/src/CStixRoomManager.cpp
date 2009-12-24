/* 
 * File:   CStixRoomManager.cpp
 * Author: rahul
 * 
 * Created on December 20, 2009, 1:54 PM
 */

#include "../includes/CStixIncludes.h"

CStixRoomManager::CStixRoomManager() {
    this->chatrooms = new CStixList<CStixChatRoom>;
    this->numofrooms = 0;
}

CStixRoomManager::~CStixRoomManager() {
    this->chatrooms->Clear();
    delete this->chatrooms;
}

int CStixRoomManager::CreateRoom(string roomname, string roomaddr) {
    if (DoesRoomExist(roomname) != -1)
        return 1; //room already exists
    CStixChatRoom cr;
    cr.SetRoomName(roomname);
    cr.SetRoomAddr(roomaddr);
    //cr.AddToClientList("user pre def");
    this->chatrooms->Add(cr);
    this->numofrooms++;
    return 0;
}

int CStixRoomManager::AddUserToRoom(string username, string roomname) {
    list<CStixChatRoom>::iterator cr;
    int itval;

    if ((itval = DoesRoomExist(roomname)) == -1)
        return 1; //room not found

    cr = (this->chatrooms->GetIteratorAt(itval));
    (*cr).AddToClientList(username);
    //        printf("addr of cr = %x\n", &cr);
    //list<CStixChatRoom>::iterator temp = this->chatrooms->GetIteratorAt(i);
    //        printf("addr of temp = %x\n", &temp);
    //cout << "after adding client, "
    //        "numofusers in addusertoroom() = " << (*temp).GetNumOfUsers() <<endl;
    return 0;
}

int CStixRoomManager::RemoveUserFromRoom(string username, string roomname) {
    list<CStixChatRoom>::iterator cr;
    int itval;

    if ((itval = DoesRoomExist(roomname)) == -1)
        return 1; //room not found

    cr = (this->chatrooms->GetIteratorAt(itval));
    (*cr).RemoveFromClientList(username);
    return 0;
}

int CStixRoomManager::DoesRoomExist(string roomname) {
    list<CStixChatRoom>::iterator cr;
    bool flag = false;
    int i;

    for (i = 1; i <= this->numofrooms; i++) {
        cr = (this->chatrooms->GetIteratorAt(i));
        if (roomname == (*cr).GetRoomName()) {
            flag = true;
            break;
        }
    }
    if (flag == true)
        return i; //if room exists, return iterator index

    return -1; //room not found
}

string CStixRoomManager::ListUsersinRoom(string roomname) {
    list<CStixChatRoom>::iterator cr;
    string returnstr;
    int itval;

    if ((itval = DoesRoomExist(roomname)) == -1)
        return "noroom"; //room not found

    cr = (this->chatrooms->GetIteratorAt(itval));
    //cout << "in ListUsersinRoom(), numousers = "<< (*cr).GetNumOfUsers() <<endl;
    returnstr = (*cr).ListUsers();

    return returnstr;
}

int CStixRoomManager::DeleteRoom(string roomname) {
    list<CStixChatRoom>::iterator cr;
    int itval;

    if ((itval = DoesRoomExist(roomname)) == -1)
        return 1; //room not found

    this->chatrooms->DeleteAt(itval);
    this->numofrooms--;
    return 0;
}