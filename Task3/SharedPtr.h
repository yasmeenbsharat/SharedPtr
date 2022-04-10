#include <iostream>

template < typename T >
class SharedPtr {

public:

    explicit SharedPtr(T* ptr = nullptr);

    T& operator * ();

    T* operator -> ();

    T* getPtr();

    operator bool();

    ~SharedPtr();

    SharedPtr& operator = (T* ptr);

    SharedPtr& operator = (const SharedPtr& ptr);

    SharedPtr(const SharedPtr& ptr);

private:

    T* m_ptr;
    unsigned int* m_counter;

};
template < typename T >
SharedPtr < T > ::SharedPtr(T* ptr) {
    std::cout << "SharedPtr constructor\n";
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
SharedPtr < T > ::operator bool() {
    return m_ptr != nullptr;
}

template < typename T >
SharedPtr < T > ::SharedPtr(const SharedPtr < T >& ptr) {
    std::cout << "Copy Constructor\n";
    m_ptr = ptr.m_ptr;
    m_counter = ptr.m_counter;
    (*m_counter)++;

}

template < typename T >
SharedPtr < T >& SharedPtr < T > ::operator = (const SharedPtr < T >& ptr) {
    std::cout << "Copy assignment\n";
    if (this != &ptr) {

        if ((*m_counter) == 1) {
            delete m_ptr;
            delete m_counter;
            m_ptr = nullptr;
            m_counter = nullptr;
        }
        else
            (*m_counter)--;

        m_ptr = ptr.m_ptr;
        m_counter = ptr.m_counter;
        (*m_counter)++;

    }
    return *this;
}

template < typename T >
SharedPtr < T >& SharedPtr < T > ::operator = (T* ptr) {
    std::cout << "Copy assignment 2\n";
    if (m_ptr != ptr) {
        if ((*m_counter) == 1) {
            delete m_ptr;
            delete m_counter;
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
    return *this;
}
template < typename T >
SharedPtr < T > ::~SharedPtr() {
    std::cout << "SharedPtr destructor\n";

    (*m_counter)--;
    if ((*m_counter) == 0) {
        std::cout << " allocated object is destroyed";
        delete m_ptr;
        delete m_counter;
    }

}