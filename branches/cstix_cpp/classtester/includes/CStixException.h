/* 
 * File:   CStixException.h
 * Author: gnarayan
 *
 * Created on December 23, 2009, 10:50 AM
 */

#ifndef _CSTIXEXCEPTION_H
#define	_CSTIXEXCEPTION_H
#include <exception>
using namespace std;

class CStixException : public exception {
public:
    CStixException(string str);
    CStixException(const CStixException& orig);
    ~CStixException() throw();
    virtual const char* what() const throw();
private:
    string *exceptionstring;
};

#endif	/* _CSTIXEXCEPTION_H */

