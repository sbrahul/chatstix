/*
 * util.h
 *
 *  Created on: Nov 25, 2009
 *      Author: rahul
 */

#ifndef UTIL_H_
#define UTIL_H_
#include "CStixIncludes.h"
using namespace std;

class CStixUtil {
public:
    static void ProgError(string errorstr);
    static long GetTimeElapsed();
};

#endif /* UTIL_H_ */
