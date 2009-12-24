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
    void ProgError(string error);
    
private:

};

#endif	/* _CSTIXCMDLINEPROGRAMEXTERNALIZER_H */

