/* 
 * File:   CStixList.h
 * Author: rahul
 *
 * Created on December 19, 2009, 7:02 PM
 */

#ifndef _CSTIXLIST_H
#define	_CSTIXLIST_H
#include "CStixIncludes.h"

template <class T>
class CStixList : public CStixAbstractList<T> {
public:

    void Add(T t) {
        this->List.push_back(t);
    }

    void AddAt(T t, int loc) {
        typename list<T>::iterator it;
        it = this->List.begin();

        for (int i = 0; i < loc; ++i)
            it++;

        this->List.insert(it, t);
    }

    void DeleteAt(int loc) {
        typename list<T>::iterator it;
        it = List.begin();

        for (int i = 1; i < loc; i++)
            (it)++;

        this->List.erase(it);
    }

    void Delete(T t) {
        this->List.remove(t);
    }

    void Clear() {
        this->List.clear();
    }

    void ListContents() {
        typename list<T>::iterator it;
        it = List.begin();
        T value;

        cout << "Listing contents of list - " << endl;

        for (int i = 0; i < this->List.size(); ++i) {
            value = *it;
            cout << value << endl;
            (it)++;
        }
    }

    typename list<T>::iterator GetIteratorAt(int loc) {
        typename list<T>::iterator it;
        it = List.begin();

        for (int i = 1; i < loc; ++i)
            it++;

        return (it);
    }

    T GetValueAt(int loc) {
        typename list<T>::iterator it;
        it = List.begin();

        for (int i = 1; i < loc; ++i)
            it++;
        //T tmp1 = *it;
        //cout << "value in getvalueat() is " << *it <<endl;
        return *it;
    }

private:
    T b;
    list<T> List;
};

#endif	/* _CSTIXLIST_H */

