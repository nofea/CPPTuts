#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include <iostream>
using namespace std;

template <class T>
class smptr
{
    private:
    T *ptr;

    public:
    smptr(T *p = NULL);
    ~smptr();

    T& operator *();
    T& operator ->();
};

#endif