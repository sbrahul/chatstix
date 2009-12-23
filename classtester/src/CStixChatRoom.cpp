/* 
 * File:   CStixMcastRoom.cpp
 * Author: rahul
 * 
 * Created on December 19, 2009, 4:16 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

CStixChatRoom::CStixChatRoom() {
    this->clientlist = new CStixList<string>;
    this->numusers = 0;
}

CStixChatRoom::~CStixChatRoom() {
    if (this->numusers > 0)
        this->clientlist->Clear();
    //delete this->clientlist;
}

void CStixChatRoom::SetRoomName(string name) {
    this->roomname = name;
}

void CStixChatRoom::SetRoomAddr(string addr) {
    this->roomaddr = addr;
}

void CStixChatRoom::IncreaseUsers() {
    this->numusers++;
}

void CStixChatRoom::DecreaseUsers() {
    this->numusers--;
}

void CStixChatRoom::AddToClientList(string name) {
    this->clientlist->Add(name);
    this->IncreaseUsers();
    cout << "in addtoclientlist(), numousers = " <<this->numusers<<endl;
}

void CStixChatRoom::RemoveFromClientList(string name) {
    this->clientlist->Delete(name);
    this->DecreaseUsers();
}

string CStixChatRoom::ListUsers() {
    ostringstream op;
    cout << "in Listusers(), numusers = " <<this->numusers<<endl;
    op << this->numusers;                                   //write num of users
    for (int i = 0; i < this->numusers; i++) {
        string st = this->clientlist->GetValueAt(i + 1);
        op << ":" << st;             //write each username
        //printf("test... ing");
    }
    return op.str();
    
}

string CStixChatRoom::GetRoomName() {
    return this->roomname;
}

string CStixChatRoom::GetRoomAddr() {
    return this->roomaddr;
}

int CStixChatRoom::GetNumOfUsers() {
    return this->numusers;
}

ostream &operator<<(ostream &output, const CStixChatRoom &croom)
{
    string str = croom.roomname;
    output << str;
   return output;
}

int CStixChatRoom::operator==(const CStixChatRoom &rhs) const
{
    if ((this->roomname) == rhs.roomname)
        return 1;
   return 0;
}