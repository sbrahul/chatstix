/* 
 * File:   CStixCmdlineProgramExternalizer.h
 * Author: gnarayan
 *
 * Created on December 23, 2009, 10:38 AM
 */

#ifndef _CSTIXCMDLINEPROGRAMEXTERNALIZER_H
#define	_CSTIXCMDLINEPROGRAMEXTERNALIZER_H

#include "CStixIncludes.h"
#include "CStixAbstractProgramExternalizer.h"

class CStixCmdlineProgramExternalizer : public CStixAbstractProgramExternalizer {
public:
    virtual void ProgError(int errcode);
    virtual string GetBacktrace();
private:

};

#endif	/* _CSTIXCMDLINEPROGRAMEXTERNALIZER_H */

