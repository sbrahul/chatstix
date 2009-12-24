/* 
 * File:   CStixCmdlineProgramExternalizer.cpp
 * Author: gnarayan
 * 
 * Created on December 23, 2009, 10:38 AM
 */

#include "../includes/CStixIncludes.h"

void CStixCmdlineProgramExternalizer::ProgError(string error) {
    try {
        throw error;
    } catch (string error) {
        cout << error << endl;
        ::exit(1);
    }
}
