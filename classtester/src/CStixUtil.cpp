/*
 * util.cpp
 *
 *  Created on: Nov 25, 2009
 *      Author: rahul
 */

#include "../includes/CStixIncludes.h"
#include "../includes/CStixAbstractProgramExternalizer.h"
#include "../includes/CStixCmdlineProgramExternalizer.h"
using namespace std;

void CStixUtil::ProgError(string errorstr) {
    CStixAbstractProgramExternalizer *progext =
            new CStixCmdlineProgramExternalizer();
    progext->ProgError(errorstr);
}

