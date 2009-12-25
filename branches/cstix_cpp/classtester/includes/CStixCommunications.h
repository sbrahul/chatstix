/* 
 * File:   CStixCommunications.h
 * Author: gnarayan
 *
 * Created on December 24, 2009, 2:19 PM
 */

#ifndef _CSTIXCOMMUNICATIONS_H
#define	_CSTIXCOMMUNICATIONS_H

#include "../includes/CStixTypedefs.h"
class CStixCommunications {
public:
    CStixCommunications();
    CStixCommunications(const CStixCommunications& orig);
    void RegisterMessageReceiveCallback(callback_v1csmsg *msgrcvcb);
    void ReceiveMessage(); // Asynchronous. Therefore, no return.
    virtual ~CStixCommunications();
private:
    callback_v1csmsg *msgrcvcb;
};

#endif	/* _CSTIXCOMMUNICATIONS_H */

