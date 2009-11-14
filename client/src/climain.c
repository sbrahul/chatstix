#include "../include/sockheads.h"

int main(int argc, char *argv[])
{
	struct sockaddr_in sendaddr;
	pthread_t thid;
	if(argc == 2) //set server addr to that from cmd line else set to loopback
		gservaddr = argv[1];
	else
		gservaddr = "127.0.0.1";
	gsendfd = createsocket(&sendaddr, "any", SERVPORT, UDP, B_NO);
        if(sem_init(&semforpm, 0, 0) == -1)
            progerror("semaphore initialization error");
	if(pthread_create(&thid, NULL, &fnthreadr, NULL) != 0) //create rcv thread
		progerror("thread creation error");
	worker(); //create process thread.
	printf("Bye!\n");
	if(pthread_cancel(thid) != 0)
		progerror("thread cancel error");
	if(pthread_join(thid, NULL) != 0)
	        progerror("thread join error");
	if(close(gsendfd) == -1)
	        progerror("close send error");

	return 0;
}