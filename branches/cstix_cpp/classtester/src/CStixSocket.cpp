/*
 * File:   Socket.cpp
 * Author: rahul
 *
 * Created on November 25, 2009, 5:00 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;

CStixSocket::CStixSocket(int socktype, int portnum) {
    if ((socketfd = socket(AF_INET, socktype, 0)) == -1)
        CStixUtil::ProgError(SHUTDOWN_SOCKETCREATIONERROR);
    saddr = new ::sockaddr_in;
    this->sockport = portnum;
}

// Private method
void CStixSocket::FillSockAaddr(string caddr) {
    ::memset(saddr, 0, sizeof (saddr));

    this->saddr->sin_family = AF_INET;
    if (::inet_pton(AF_INET, caddr.c_str(), &this->saddr->sin_addr) == -1)
        CStixUtil::ProgError(SHUTDOWN_PTONERROR);
    saddr->sin_port = ::htons(sockport);
}

void CStixSocket::SendPkt(string caddr, string msg) {

    this->FillSockAaddr(caddr);
#ifdef TRACEPRINT
    cout << "TP:in sendpkt()\n";
#endif
    if (::sendto(socketfd, msg.c_str(), msg.length(), 0,
            (::sockaddr *) saddr, sizeof(::sockaddr_in)) == -1)
        CStixUtil::ProgError(SHUTDOWN_SENDERROR);
    cout << "Msg sent is - " << msg << endl;
}

CStixSocket::~CStixSocket() {
    if (::close(socketfd) == -1)
        CStixUtil::ProgError(SHUTDOWN_SOCKETCLOSEERROR);
    delete saddr;
}