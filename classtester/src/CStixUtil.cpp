/*
 * util.cpp
 *
 *  Created on: Nov 25, 2009
 *      Author: rahul
 */

#include "../includes/CStixIncludes.h"
using namespace std;

void CStixUtil::ProgError(int errcode) {
    CStixAbstractProgramExternalizer *progext =
            new CStixCmdlineProgramExternalizer();
    progext->ProgError(errcode);
}

long CStixUtil::GetTimeElapsed() {
    return ::clock();
}