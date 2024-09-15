#pragma once

#ifdef ARDUINO
#include <Arduino.h>
#else
#include <cstddef>
#endif // ARDUINO

namespace RHino
{

template <typename T>
class vector
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using pointer = value_type *;
    using const_pointer = value_type const *;
    using reference = value_type &;
    using const_reference = value_type const &;

public:
    vector() = default;
    vector(size_type capacity);
    vector(const vector &other) = delete;
    vector(vector &&other) = delete;
    vector& operator=(const vector &other) = delete;
    vector& operator=(vector &&other) = delete;
    ~vector();

    // Element access

    reference operator[](size_type index);
    const_reference operator[](size_type index) const;

    reference at(size_type index);
    const_reference at(size_type index) const;

    reference front();
    const_reference front() const;

    reference back();
    const_reference back() const;

    // Capacity

    bool empty() const;
    size_type size() const;

    // Modifiers

    void clear();

    void push_back(const_reference value);

private:
    void ensureCapacity(size_type minSize);

private:
    size_type _size{0};
    size_type _capacity{0};
    pointer _storage{nullptr};
};

// public

template <typename T>
vector<T>::vector(const size_type capacity)
{
    ensureCapacity(capacity);
}

template <typename T>
vector<T>::~vector()
{
    delete[] _storage;
}

template <typename T>
auto vector<T>::operator[](const size_type index) -> reference
{
    return _storage[index];
}

template <typename T>
auto vector<T>::operator[](const size_type index) const -> const_reference
{
    return _storage[index];
}

template <typename T>
auto vector<T>::front() -> reference
{
    return _storage[0];
}

template <typename T>
auto vector<T>::front() const -> const_reference
{
    return _storage[0];
}

template <typename T>
auto vector<T>::back() -> reference
{
    return _storage[_size - 1];
}

template <typename T>
auto vector<T>::back() const -> const_reference
{
    return _storage[_size - 1];
}

template <typename T>
bool vector<T>::empty() const
{
    return _size == 0;
}

template <typename T>
auto vector<T>::size() const -> size_type
{
    return _size;
}

template <typename T>
void vector<T>::clear()
{
}

template <typename T>
void vector<T>::push_back(const_reference value)
{
    ensureCapacity(_size + 1);
    _storage[_size++] = value;
}

// private

template <typename T>
void vector<T>::ensureCapacity(const size_type minSize)
{
    if (_capacity >= minSize)
    {
        return;
    }

    size_type newCapacity = 1;
    while (newCapacity < minSize)
    {
        newCapacity <<= 1;
    }

    auto newStorage = new value_type[newCapacity];
    for (size_type i = 0; i < _size; ++i)
    {
        newStorage[i] = _storage[i];
    }

    delete[] _storage;
    _storage = newStorage;
    _capacity = newCapacity;
}

} // namespace RHino
