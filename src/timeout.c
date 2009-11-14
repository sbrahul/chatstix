#include "../include/sockheads.h"

void pinghandler() {
    char pkt[15];
    sprintf(pkt, "#pingreply#:%d", cliid);
    sendpkt(gservaddr, pkt, SERVPORT);
}
