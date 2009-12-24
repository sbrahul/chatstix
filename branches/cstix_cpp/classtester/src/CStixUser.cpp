/* 
 * File:   CStixUser.cpp
 * Author: rahul
 * 
 * Created on December 23, 2009, 4:22 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

CStixUser::CStixUser() {
    this->lastping = CStixUtil::GetTimeElapsed();
}

CStixUser::CStixUser(string username) {
    this->username = username;
    this->lastping = CStixUtil::GetTimeElapsed();
}

CStixUser::CStixUser(string username, string ipaddr) {
    this->username = username;
    this->useripaddr = ipaddr;
    this->lastping = CStixUtil::GetTimeElapsed();
}

void CStixUser::SetUserName(string name) {
    this->username = name;
}

void CStixUser::SetIpAddr(string ipaddr) {
    this->useripaddr = ipaddr;
}

void CStixUser::SetLastPing(long pingtime) {
    this->lastping = pingtime;
}

void CStixUser::SetRoomName(string name) {
    this->roomname = name;
}

string CStixUser::GetUserName() {
    return this->username;
}

string CStixUser::GetIpAddr() {
    return this->useripaddr;
}

long CStixUser::GetLastPing() {
    return this->lastping;
}

string CStixUser::GetRoomName() {
    return this->roomname;
}

int CStixUser::operator ==(const CStixUser& rhs) const {
    if ((this->username) == rhs.username)
        return 1;
    return 0;
}

ostream &operator<<(ostream &output, const CStixUser &cuser) {
    string str = cuser.username;
    output << str;
    return output;
}