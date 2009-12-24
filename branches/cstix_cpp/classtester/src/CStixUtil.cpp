/*
 * util.cpp
 *
 *  Created on: Nov 25, 2009
 *      Author: rahul
 */

#include "../includes/CStixIncludes.h"
using namespace std;

void CStixUtil::ProgError(string errorstr) {
    CStixAbstractProgramExternalizer *progext =
            new CStixCmdlineProgramExternalizer();
    progext->ProgError(errorstr);
}

long CStixUtil::GetTimeElapsed() {
    return ::clock();
}