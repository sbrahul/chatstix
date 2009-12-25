/* 
 * File:   CStixCmdlineProgramExternalizer.cpp
 * Author: gnarayan
 * 
 * Created on December 23, 2009, 10:38 AM
 */

#include "../includes/CStixIncludes.h"
#include "../includes/CStixAbstractDebugHelper.h"
#include "../includes/CStixWindowsDebugHelper.h"

void CStixCmdlineProgramExternalizer::ProgError(int errcode) {
    try {
        CStixGlobals::errorcode = errcode;
        throw CStixGlobals::GetVerboseError();
    } catch (string error) {
        cout << error << endl;
        cout << "Backtrace:\n" << GetBacktrace() << endl;
        cout << "errcode - " << errcode << endl;
        // Jump to the point of env registry.
        ::longjmp(CStixGlobals::environment, errcode);
    }
}

string CStixCmdlineProgramExternalizer::GetBacktrace() {
    CStixAbstractDebugHelper *pDbgHelper =
            new CStixWindowsDebugHelper();
    return pDbgHelper->GetBacktrace();
}
