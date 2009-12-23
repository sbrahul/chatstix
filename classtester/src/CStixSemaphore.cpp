/* 
 * File:   CStixSemaphore.cpp
 * Author: rahul
 * 
 * Created on December 5, 2009, 8:50 PM
 */

#include "../includes/CStixIncludes.h"
using namespace std;


void CStixSemaphore::setSemID(SemID semid) {
    this->semid = semid;
}

SemID CStixSemaphore::getSemID() {
    return this->semid;
}

