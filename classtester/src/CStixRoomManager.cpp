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

void CStixRoomManager::CreateRoom(string roomname, string roomaddr) {
    CStixChatRoom cr;
    cr.SetRoomName(roomname);
    cr.SetRoomAddr(roomaddr);
    //cr.AddToClientList("user pre def");
    this->chatrooms->Add(cr);
    this->numofrooms++;
}

void CStixRoomManager::AddUserToRoom(string username, string roomname) {
    list<CStixChatRoom>::iterator cr;

    bool flag = false;
    int i = 0;
    cout<<"##In CStixRoomManager::AddUserToRoom, username, roomname"
            " = " << username << " for " << roomname << endl;
    for (i = 0; i < this->numofrooms; i++) {
        cr = (this->chatrooms->GetIteratorAt(i));
        //cout << "roomname = " << (*cr).GetRoomName() <<endl;
        if (roomname == (*cr).GetRoomName()) {
            flag = true;
            break;
        }
    }
    if (flag == true) {
        (*cr).AddToClientList(username);
//        printf("addr of cr = %x\n", &cr);
        list<CStixChatRoom>::iterator temp = this->chatrooms->GetIteratorAt(i);
//        printf("addr of temp = %x\n", &temp);
        cout << "after adding client, "
                "numofusers in addusertoroom() = " << (*temp).GetNumOfUsers() <<endl;
    }
    else {
        CStixUtil::ProgError("In CStixRoomManager::AddUserToRoom, "
            "roomname " + roomname + " does not exist!");
    }

}

void CStixRoomManager::RemoveUserFromRoom(string username, string roomname) {
    list<CStixChatRoom>::iterator cr;
    bool flag = false;
    
    for (int i = 1; i <= this->numofrooms; i++) {
        cr = (this->chatrooms->GetIteratorAt(i));
        if (roomname == (*cr).GetRoomName()) {
            flag = true;
            break;
        }
    }
    if (flag == true)
        (*cr).RemoveFromClientList(username);
    else
        CStixUtil::ProgError("In CStixRoomManager::RemoveUserFromRoom, "
        "roomname specidied doesnt not exist!");
}


bool CStixRoomManager::DoesRoomExist(string roomname) {
    list<CStixChatRoom>::iterator cr;
    bool flag;
    
    for (int i = 1; i <= this->numofrooms; i++) {
        cr = (this->chatrooms->GetIteratorAt(i));
        if (roomname == (*cr).GetRoomName()) {
            flag = true;
            break;
        }
    }
    if (flag == true)
        return true;

    return false;
}

string CStixRoomManager::ListUsersinRoom(string roomname) {
    list<CStixChatRoom>::iterator cr;
    bool flag = false;
    string returnstr;

    for (int i = 1; i <= this->numofrooms; i++) {
        cr = (this->chatrooms->GetIteratorAt(i));
        if (roomname == (*cr).GetRoomName()) {
            flag = true;
            break;
        }
    }
    if (flag == true) {
        cout << "in ListUsersinRoom(), numousers = "<< (*cr).GetNumOfUsers() <<endl;
        returnstr = (*cr).ListUsers();
    }
    else
        CStixUtil::ProgError("In CStixRoomManager::ListUsersinRoom, "
        "roomname specidied doesnt not exist!");

    return returnstr;
}

void CStixRoomManager::DeleteRoom(string roomname) {
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
    if (flag == true) {
        this->chatrooms->DeleteAt(i);
        this->numofrooms--;
    }
    else
        CStixUtil::ProgError("In CStixRoomManager::AddUserToRoom, "
        "roomname specidied doesnt not exist!");
}