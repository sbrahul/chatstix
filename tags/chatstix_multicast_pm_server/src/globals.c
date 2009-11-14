#include "../includes/sockheads.h"

sem_t sem1; //keep track of outstanding messages
sem_t semjoballocation;
job *job_queue; //create global queue
pthread_mutex_t job_mutex = PTHREAD_MUTEX_INITIALIZER; //mutex to add and read msg
cliinfostr infostr[MAXCLIENTS]; //array for storing client info
mcastrooms mrooms[MAXROOMS]; //array for storing room info
