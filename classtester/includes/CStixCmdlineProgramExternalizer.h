/* 
 * File:   CStixCmdlineProgramExternalizer.h
 * Author: gnarayan
 *
 * Created on December 23, 2009, 10:38 AM
 */

#ifndef _CSTIXCMDLINEPROGRAMEXTERNALIZER_H
#define	_CSTIXCMDLINEPROGRAMEXTERNALIZER_H

#include "../includes/CStixIncludes.h"
#include "../includes/CStixAbstractProgramExternalizer.h"

class CStixCmdlineProgramExternalizer : public CStixAbstractProgramExternalizer {
public:
    CStixCmdlineProgramExternalizer();
    CStixCmdlineProgramExternalizer(const CStixCmdlineProgramExternalizer& orig);
    void ProgError(string error);
    virtual ~CStixCmdlineProgramExternalizer();
private:

};

#endif	/* _CSTIXCMDLINEPROGRAMEXTERNALIZER_H */

