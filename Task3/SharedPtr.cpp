///#include "SharedPtr.h"
/*
#include <iostream>

template < typename T >
class SharedPtr {

public:

    explicit SharedPtr(const T* ptr = nullptr);

    T& operator * ();

    T* operator -> ();

    T* getPtr();

    bool operator()();

    ~SharedPtr();

    SharedPtr& operator = (T* ptr);

    SharedPtr& operator = (const SharedPtr& ptr);

    SharedPtr(const SharedPtr& ptr);

private:

    T* m_ptr;
    unsigned int* m_counter;

};
template < typename T >
SharedPtr < T > ::SharedPtr(const T* ptr) {
    std::cout << "constructor\n";
    m_ptr = ptr;
    m_counter = new unsigned int(0);
    if (ptr)
        (*m_counter)++;

}

template < typename T >
T& SharedPtr < T > ::operator * () {
    return *m_ptr;
}

template < typename T >
T* SharedPtr < T > ::operator -> () {
    return m_ptr;
}

template < typename T >
T* SharedPtr < T > ::getPtr() {
    return m_ptr;
}

template < typename T >
bool SharedPtr < T > ::operator()() {
    return *m_ptr;
}

template < typename T >
SharedPtr < T > ::SharedPtr(const SharedPtr < T >& ptr) {

    m_ptr = ptr.m_ptr;
    m_counter = ptr.m_counter;
    (*m_counter)++;

}

template < typename T >
SharedPtr < T >& SharedPtr < T > ::operator = (const SharedPtr < T >& ptr) {

    if (this != &ptr) {

        if ((*m_counter) == 1) {
            delete this;
            m_ptr = nullptr;
            m_counter = nullptr;
        }
        else
            (*m_counter)--;

        m_ptr = ptr.m_ptr;
        m_counter = ptr.m_counter;
        (*m_counter)++;

    }
}

template < typename T >
SharedPtr < T >& SharedPtr < T > ::operator = (T* ptr) {
    if (m_ptr != &ptr) {
        if ((*m_counter) == 1) {
            delete this;
            m_ptr = nullptr;
            m_counter = nullptr;
        }
        else
            (*m_counter)--;

        m_ptr = ptr;
        m_counter = new unsigned int(0);
        if (m_ptr)
            (*m_counter)++;

    }
}
template < typename T >
SharedPtr < T > ::~SharedPtr() {

    (*m_counter)--;
    if ((*m_counter) == 0) {
        delete m_ptr;
        delete m_counter;
    }

}
*/



