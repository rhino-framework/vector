#pragma once

#if ARDUINO
#include "Arduino.h"
#else
#include <cstddef>
#endif // ARDUINO

namespace RHino
{

template <typename T>
class vector
{
public:
    vector() = default;
    ~vector() = default;

    vector(const vector &other) = delete;
    vector(vector &&other) = delete;
    vector& operator=(const vector &other) = delete;
    vector& operator=(vector &&other) = delete;

    inline size_t size() const noexcept
    {
        return _size;
    }

    void push_back(const T&)
    {
    }

    void push_back(T&&)
    {
    }

    void clear()
    {
    }

private:
  T* _storage{nullptr};
  size_t _capacity{0};
  size_t _size{0};
};

} // namespace RHino
