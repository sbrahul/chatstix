/* 
 * File:   CStixAbstractDebugHelper.h
 * Author: gnarayan
 *
 * Created on December 25, 2009, 12:28 PM
 */

#ifndef _CSTIXABSTRACTDEBUGHELPER_H
#define	_CSTIXABSTRACTDEBUGHELPER_H

#include <string>
using namespace std;

class CStixAbstractDebugHelper {
public:
    virtual string GetBacktrace() = 0;
private:

};

#endif	/* _CSTIXABSTRACTDEBUGHELPER_H */

