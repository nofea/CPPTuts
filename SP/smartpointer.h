#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

template <typename T>
class smptr
{
    private:
    T *ptr = nullptr;

    public:
    smptr(T *p) : ptr(p) {}
    ~smptr() { delete ptr;}

    T& operator *() { return *ptr;}
    T& operator ->() {return *ptr;}
};

#endif /* SMARTPOINTER_H */
