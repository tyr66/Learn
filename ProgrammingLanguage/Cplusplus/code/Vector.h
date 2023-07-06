#include <string.h>
#include <iostream>
#include <new>
#include <stdlib.h>

class Vector {
public:
    explicit Vector(size_t sz):_size(sz) {
        this->_data = new int[sz];
    }

    Vector():_size(0), _data(nullptr) {}

    ~Vector()
    {
        this->_size = 0;
        delete[] this->_data;
    }

    Vector(const Vector& a):_size(a._size)
    {
        _data = new int[_size];
        memcpy(_data, a._data, _size * sizeof(int));
    }

    Vector& operator=(const Vector&a)
    {
        _size = a._size;
        _data = (int*)realloc(_data, _size * sizeof(int));
        memcpy(_data, a._data, _size * sizeof(int));
        return *this;
    }

    Vector(Vector&& vec)
    {
        _size = vec._size;
        _data = vec._data;
        vec._size = 0;
        vec._data = nullptr;
    }

    Vector& operator=(Vector&& vec)
    {
        this->~Vector();
        new (this) Vector(std::move(vec));
        return *this;
    }

    int& operator[](int idx) {
        return _data[idx];
    }

    void print() {
        for (int i = 0; i < _size; i++) {

            printf("vec[%d] = %d \n", i, _data[i]);
        }

    }

private:
    size_t _size;
    int * _data;

};
