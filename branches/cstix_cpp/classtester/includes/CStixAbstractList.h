/* 
 * File:   CStixAbstractList.h
 * Author: rahul
 *
 * Created on December 19, 2009, 6:20 PM
 */

#ifndef _CSTIXABSTRACTLIST_H
#define	_CSTIXABSTRACTLIST_H
#include <list>
using namespace std;

template <class T>
class CStixAbstractList {

public:
    virtual void Add(T t) = 0;                  //add at the end
    virtual void AddAt(T t, int loc) = 0;       //add at loc
    virtual void Delete(T t) = 0;               //delete element t
    virtual void DeleteAt(int loc) = 0;         //delete at loc
    virtual void Clear() = 0;                   //remove all elements
    virtual void ListContents() = 0;
    virtual typename list<T>::iterator GetIteratorAt(int loc) = 0; //return element at loc
    virtual T GetValueAt(int loc) = 0;

};

#endif	/* _CSTIXABSTRACTLIST_H */

