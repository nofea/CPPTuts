#include "smartpointer.h"

smptr::smptr(T *p)
{
    ptr = p;
    cout << "smart pointer created" << endl;
}

smptr::~smptr()
{
    delete(ptr);
    cout << "smart pointer destroyed" << endl;
}

T& smptr::operator *()
{
    return *ptr;
}

T& smptr::operator->()
{
    return *ptr;
}