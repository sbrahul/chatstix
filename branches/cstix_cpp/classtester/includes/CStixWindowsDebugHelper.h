/* 
 * File:   CStixWindowsDebugHelper.h
 * Author: gnarayan
 *
 * Created on December 25, 2009, 12:32 PM
 */

#ifndef _CSTIXWINDOWSDEBUGHELPER_H
#define	_CSTIXWINDOWSDEBUGHELPER_H

#include "CStixAbstractDebugHelper.h"


class CStixWindowsDebugHelper : public CStixAbstractDebugHelper {
public:
    CStixWindowsDebugHelper();
    CStixWindowsDebugHelper(const CStixWindowsDebugHelper& orig);
    string GetBacktrace();
    virtual ~CStixWindowsDebugHelper();
private:

};

#endif	/* _CSTIXWINDOWSDEBUGHELPER_H */

