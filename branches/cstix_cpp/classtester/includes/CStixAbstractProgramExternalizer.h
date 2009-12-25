/* 
 * File:   CStixAbstractProgramExternalizer.h
 * Author: gnarayan
 *
 * Created on December 23, 2009, 10:30 AM
 */

#ifndef _CSTIXABSTRACTPROGEXT_H
#define	_CSTIXABSTRACTPROGEXT_H

#include "CStixIncludes.h"

class CStixAbstractProgramExternalizer {
public:
    virtual void ProgError(int errcode) = 0;
    virtual string GetBacktrace(void) = 0;
private:

};

#endif	/* _CSTIXABSTRACTPROGEXT_H */

