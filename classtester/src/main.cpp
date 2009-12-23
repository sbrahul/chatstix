/*
 * main.cpp
 *
 *  Created on: Nov 25, 2009
 *      Author: rahul
 */

#include "../includes/CStixIncludes.h"

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
#endif
    CStixRoomManager rm;
    rm.CreateRoom("Fractal formalism", "56418.54");
    rm.AddUserToRoom("Mandelbrot", "Fractal formalism");
    rm.AddUserToRoom("Julia", "Fractal formalism");
    rm.AddUserToRoom("Hilbert", "Fractal formalism");
    rm.AddUserToRoom("Dirac", "Fractal formalism");
    rm.AddUserToRoom("Weirstrass", "Fractal formalism");
    cout << rm.ListUsersinRoom("Fractal formalism") << endl;
    
    return (EXIT_SUCCESS);
}
