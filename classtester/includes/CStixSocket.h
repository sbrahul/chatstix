/*
 * File:   Socket.h
 * Author: rahul
 *
 * Created on November 25, 2009, 5:15 PM
 */

#ifndef _SOCKET_H
#define	_SOCKET_H
#include "CStixIncludes.h"

#define TCP SOCK_STREAM
#define UDP SOCK_DGRAM
#define B_NO 0
#define B_YES 1

class CStixSocket {
public:
    CStixSocket(int, int);
    ~CStixSocket();
private:
    //vars
    int socketfd;
    ::sockaddr_in *saddr;
    int sockport;
    //methods
    void FillSockAaddr(string caddr);
public:
    void SendPkt(string caddr, string msg);
};


#endif	/* _SOCKET_H */
