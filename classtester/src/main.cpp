/*
 * main.cpp
 *
 *  Created on: Nov 25, 2009
 *      Author: rahul
 */

#include "../includes/CStixIncludes.h"
#include "../includes/CStixMessageParser.h"
#include "../includes/CStixCommunications.h"
#include "../includes/CStixCallbacks.h"
#include "../includes/CStixServer.h"

int main(int argc, char** argv) {
#if 0
    /*CStixSocket sock(UDP, 9000);
    sock.SendPkt("127.0.0.1", "hello");
     */
    ostringstream buf;
    int i;
    CStixMessageQ *MsgQ, *ProducerQ;
    CStixThread thtype;
    thtype.setThreadEntryFunction(&threadfn);
    CStixSystem::InitializeSem(CStixGlobals::sem1, 0);
    CStixSystem::StartThread(thtype);
    MsgQ = CStixGlobals::getJobQueue();
    ProducerQ = MsgQ;

    for (i = 1; i < 6; i++) {
        buf << "127.0.0." << i;
        ProducerQ->AddMsgtoQ("hello", buf.str());
        ProducerQ = ProducerQ->GetNextMsgptr();
        buf.str("");
        CStixSystem::PostSem(CStixGlobals::sem1);
        sleep(1);
        //cout << "Job " <<i<< " added\n";
    }

    //sleep(5);
    getchar();
    CStixSystem::KillThread(thtype);
    CStixSystem::WaitForThread(thtype);

    CStixRoomManager rm;
    CStixUserManager um;
    if (rm.CreateRoom("room1", "56418.54"))
        cout << "room exists! give another name\n";
    if (rm.CreateRoom("room2", "6532"))
        cout << "room exists! give another name\n";
    if (rm.AddUserToRoom("user1", "room41"))
        cout << "room doesnt exist\n";
    rm.AddUserToRoom("user2", "room1");
    rm.AddUserToRoom("user3", "room2");
    rm.AddUserToRoom("user4", "room1");
    rm.AddUserToRoom("user5", "room2");
    cout << rm.ListUsersinRoom("room1") << endl;
    cout << rm.ListUsersinRoom("room2") << endl;

    int retval;
    if (um.CreateUser("user1", "654335"))
        cout << "username already exists!\n";
    if (um.CreateUser("user2", "654335"))
        cout << "username already exists!\n";
    if (um.ChangeRoom("user1", "room1"))
        cout << "username does not exists!\n";
    
    retval = um.ChangeUsername("user1", "rah");
    if(retval == -1)
        cout << "user doesnt exist\n";
    else if (retval == 1)
        cout << "name already exists. pick another\n";
    retval = um.ChangeUsername("user2", "sb");
    if(retval == -1)
        cout << "user doesnt exist\n";
    else if (retval == 1)
        cout << "name already exists. pick another\n";
    um.ListAllUsers();
#endif
    // gnarayan tests.
//    CStixMessageParser *msgparser = new CStixMessageParser;
//    CStixCallbacks *cbs = new CStixCallbacks();
//
//    callback_v2str loginCB(cbs, &CStixCallbacks::LoginCallback);
//
//    msgparser->registerLoginCallback(&loginCB);
//    string s("Greet the hellraiser");
//    msgparser->parseMessage(s);

    (CStixGlobals::server).RegisterCallbacks();
    (CStixGlobals::server).StartServer();
    return (EXIT_SUCCESS);
}
