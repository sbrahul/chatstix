/* 
 * File:   allglobals.h
 * Author: rahul
 *
 * Created on November 7, 2009, 1:58 PM
 */

#ifndef ALLGLOBALS_H_
#define ALLGLOBALS_H_

extern sem_t sem1; //keep track of outstanding messages
extern sem_t semjoballocation; //wait till job_queue is allocated
extern job *job_queue; //create global queue
extern pthread_mutex_t job_mutex; //mutex to add and read msg
extern cliinfostr infostr[MAXCLIENTS]; //array for storing client info
extern mcastrooms mrooms[MAXROOMS]; //array for storing room info

#endif /*GLOBALS_H_*/