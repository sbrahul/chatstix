/* 
 * File:   CStixException.cpp
 * Author: gnarayan
 * 
 * Created on December 23, 2009, 10:50 AM
 */

#include <string>
#include "../includes/CStixException.h"
#include <iostream>
using namespace std;

CStixException::CStixException(string s) {
    this->exceptionstring = new string("...");
}

CStixException::CStixException(const CStixException& orig) {
}

const char* CStixException::what() const throw() {
    //cout << *(this->exceptionstring) << endl;
    return "joe"; //this->exceptionstring->c_str();
}

CStixException::~CStixException() throw() {
    
}

