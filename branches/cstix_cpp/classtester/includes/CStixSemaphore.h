/* 
 * File:   CStixSemaphore.h
 * Author: rahul
 *
 * Created on December 5, 2009, 8:50 PM
 */

#ifndef _CSTIXSEMAPHORE_H
#define	_CSTIXSEMAPHORE_H
#include "CStixIncludes.h"

typedef sem_t SemID;

class CStixSemaphore {
public:
    void setSemID(SemID semid);
    SemID getSemID();
    SemID semid;
private:

};

#endif	/* _CSTIXSEMAPHORE_H */

