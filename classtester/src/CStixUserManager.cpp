/* 
 * File:   CStixUserManager.cpp
 * Author: rahul
 * 
 * Created on December 23, 2009, 4:45 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

CStixUserManager::CStixUserManager() {
    this->users = new CStixList<CStixUser>;
    this->numofusers = 0;
}

CStixUserManager::~CStixUserManager() {
    if (numofusers > 0)
        this->users->Clear();
    delete users;
}

int CStixUserManager::CreateUser(string username, string ipaddr) {
    if (DoesUserExist(username) != -1)
        return -1;

    CStixUser userobj(username, ipaddr);
    this->users->Add(userobj);
    this->numofusers++;
    return 0;
}

int CStixUserManager::DeleteUser(string username) {
    int itindex;

    if ((itindex = DoesUserExist(username)) == -1)
        return -1; //user not found

    //user found. delete
    this->users->DeleteAt(itindex);
    this->numofusers--;
    return 0;
}

int CStixUserManager::DoesUserExist(string name) {
    list<CStixUser>::iterator it;
    bool flag = false;
    int i;
    
    for (i = 1; i <= this->numofusers; i++) {
        it = (this->users->GetIteratorAt(i));
        if (name == (*it).GetUserName()) {
            flag = true;
            break;
        }
    }
    if (flag == true)
        return i; //user found. return index

    return -1; //user not found
}

int CStixUserManager::ChangeUsername(string oldname, string newname) {
    list<CStixUser>::iterator it;
    int itindex;

    if ((itindex = DoesUserExist(oldname)) == -1){
        cout << "changeusername(), itindex = "<<itindex<<endl;
        return -1; //user doesnt exist
    }
    if (DoesUserExist(newname) != -1)
        return 1; //name already exists, pick another
    
    it = (this->users->GetIteratorAt(itindex));
    (*it).SetUserName(newname);
    return 0; //name successfully changed
}

int CStixUserManager::ChangeRoom(string username, string roomname) {
    list<CStixUser>::iterator it;
    int itindex;

    if ((itindex = DoesUserExist(username)) == -1) {
        return -1; //user doesnt exist
    }
        

    it = (this->users->GetIteratorAt(itindex));
    (*it).SetRoomName(roomname);
    return 0; //roomname successfully changed
}

void CStixUserManager::ListAllUsers() {
    list<CStixUser>::iterator it;
    it = this->users->GetIteratorAt(1);
    int i;

    cout << "Users are - \n";
    for(i = 1; i <= this->numofusers; i++) {
        cout << (*it).GetUserName() << endl;
        it++;
    }
}