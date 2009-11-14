#include "../includes/sockheads.h"

int main()
{
	//struct sockaddr_in sendaddr;
	pthread_t thid;
	//initialize semaphore
	if(sem_init(&sem1, 0, 0) == -1)
		progerror("semaphore initialization error");
        if(sem_init(&semjoballocation, 0, 0) == -1)
            progerror("semaphore initialization error");
	if(pthread_create(&thid, NULL, &threcvfn, NULL) != 0)
		progerror("thread creation error");
#ifdef TRACEPRINT
	printf("TP:in main(), created thread\n");
#endif
	//populate rooms with addresses
	populateroom();
        //set timeout alarm
        setalarm();
	//start worker
	printf("Everything set. Waiting for data.\n");
	job_worker();
	//quit thread
	if(pthread_cancel(thid) != 0)
		progerror("thread cancel error");
	if(pthread_join(thid, NULL) != 0)
		progerror("thread join error");

	return 0;
}
