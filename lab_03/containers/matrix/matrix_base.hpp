#ifndef MATRIX_BASE_HPP
#define MATRIX_BASE_HPP

#include <cstddef>
#include <iostream>

#include "exceptions/container_exceptions.hpp"
#include "containers/iterator/iterator.hpp"
#include "containers/iterator/const_iterator.hpp"

template <class T>
class matrix_base {
        class proxy {
            public:
                proxy(size_t, T*);

                T& at(size_t);
                const T& at(size_t) const;
                T& operator[](size_t);
                const T& operator[](size_t) const;

            private:
                size_t col_count;
                T* data;
        };

    public:
        typedef _iterator<T> iterator;
        typedef _const_iterator<T> const_iterator;

        explicit matrix_base(size_t, size_t);
        explicit matrix_base(size_t, size_t, const T&);
        matrix_base(size_t, size_t, iterator, iterator);
        matrix_base(size_t, size_t, const_iterator, const_iterator);
        matrix_base(size_t, size_t, std::initializer_list<T>);
        matrix_base(const matrix_base&);
        matrix_base(matrix_base&&);
        virtual ~matrix_base();
        matrix_base& operator=(const matrix_base&);
        matrix_base& operator=(matrix_base&&);
        matrix_base& operator=(std::initializer_list<T>);

        proxy at(size_t);
        const proxy at(size_t) const;
        proxy operator[](size_t);
        const proxy operator[](size_t) const;

        iterator begin();
        const_iterator cbegin() const;
        iterator end();
        const_iterator cend() const;

        iterator rbegin();
        const_iterator rcbegin() const;
        iterator rend();
        const_iterator rcend() const;

        size_t rows() const;
        size_t columns() const;
        size_t capacity() const;
        void zero();
        void swap(matrix_base&);

        template <class U>
        friend inline void swap(matrix_base<U>&, matrix_base<U>&);

        template <class U>
        friend inline bool operator==(const matrix_base<U>&, const matrix_base<U>&);
        template <class U>
        friend inline bool operator!=(const matrix_base<U>&, const matrix_base<U>&);
        template <class U>
        friend inline bool operator<(const matrix_base<U>&, const matrix_base<U>&);
        template <class U>
        friend inline bool operator<=(const matrix_base<U>&, const matrix_base<U>&);
        template <class U>
        friend inline bool operator>(const matrix_base<U>&, const matrix_base<U>&);
        template <class U>
        friend inline bool operator>=(const matrix_base<U>&, const matrix_base<U>&);

        template <class U>
        friend inline std::ostream& operator<<(std::ostream&, const matrix_base<U>&);

    protected:
        size_t row_count;
        size_t col_count;
        size_t memory_dump;
        T* buffer;
};

template <class T>
matrix_base<T>::proxy::proxy(size_t col_count, T* data) : col_count(col_count), data(data) {

}

template <class T>
T& matrix_base<T>::proxy::at(size_t index) {
    if (index < this->col_count) {
        return *(this->data + index);

    } else {
        throw out_of_range_exception("matrix_base::proxy::(out of range index)!");
    }
}

template <class T>
const T& matrix_base<T>::proxy::at(size_t index) const {
    if (index < this->col_count) {
        return *(this->data + index);

    } else {
        throw out_of_range_exception("matrix_base::proxy::(out of range index)!");
    }
}

template <class T>
T& matrix_base<T>::proxy::operator[](size_t index) {
    if (index < this->col_count) {
        return *(this->data + index);

    } else {
        throw out_of_range_exception("matrix_base::proxy::(out of range index)!");
    }
}

template <class T>
const T& matrix_base<T>::proxy::operator[](size_t index) const {
    if (index < this->col_count) {
        return *(this->data + index);

    } else {
        throw out_of_range_exception("matrix_base::proxy::(out of range index)!");
    }
}

template <class T>
matrix_base<T>::matrix_base(size_t row_count, size_t col_count)
    : row_count(row_count), col_count(col_count), memory_dump(row_count * col_count) {
    try {
        this->buffer = new T[this->memory_dump];

    } catch (std::bad_alloc& ex) {
        throw bad_memory_allocation_exception("matrix_base::(bad memory allocation)!");
    }
}

template <class T>
matrix_base<T>::matrix_base(size_t row_count, size_t col_count, const T& value)
    : matrix_base(row_count, col_count) {
    for (size_t i = 0; i < this->memory_dump; ++i) {
        this->buffer[i] = value;
    }
}

template <class T>
matrix_base<T>::matrix_base(size_t row_count, size_t col_count, iterator first, iterator last)
    : matrix_base(row_count, col_count) {
    size_t size = this->memory_dump <= static_cast<size_t>(last - first) ?
                  this->memory_dump : static_cast<size_t>(last - first);

    for (size_t i = 0; i < size; ++i, ++first) {
        this->buffer[i] = *first;
    }

    for (size_t i = size; i < this->memory_dump; ++i) {
        this->buffer[i] = 0;
    }
}

template <class T>
matrix_base<T>::matrix_base(size_t row_count, size_t col_count, const_iterator first, const_iterator last)
    : matrix_base(row_count, col_count) {
    size_t size = this->memory_dump <= static_cast<size_t>(last - first) ?
                  this->memory_dump : static_cast<size_t>(last - first);

    for (size_t i = 0; i < size; ++i, ++first) {
        this->buffer[i] = *first;
    }

    for (size_t i = size; i < this->memory_dump; ++i) {
        this->buffer[i] = 0;
    }
}

template <class T>
matrix_base<T>::matrix_base(size_t row_count, size_t col_count, std::initializer_list<T> lst)
    : matrix_base(row_count, col_count) {
    size_t size = this->memory_dump <= lst.size() ? this->memory_dump : lst.size();
    typename std::initializer_list<T>::iterator iter = lst.begin();

    for (size_t i = 0; i < size; ++i, ++iter) {
        this->buffer[i] = *iter;
    }

    for (size_t i = size; i < this->memory_dump; ++i) {
        this->buffer[i] = 0;
    }
}

template <class T>
matrix_base<T>::matrix_base(const matrix_base& other)
    : matrix_base(other.row_count, other.col_count) {
    std::copy(other.buffer, other.buffer + other.memory_dump, this->buffer);
}

template <class T>
matrix_base<T>::matrix_base(matrix_base&& other)
    : row_count(other.row_count), col_count(other.col_count), buffer(other.buffer) {
    other.row_count = 0;
    other.col_count = 0;
    other.memory_dump = 0;
    other.buffer = nullptr;
}

template <class T>
matrix_base<T>::~matrix_base() {
    delete[] buffer;
    this->row_count = 0;
    this->col_count = 0;
    this->memory_dump = 0;
    this->buffer = nullptr;
}

template <class T>
matrix_base<T>& matrix_base<T>::operator=(const matrix_base<T>& other) {
    if (this != &other) {
        this->row_count = other.row_count;
        this->col_count = other.col_count;
        this->memory_dump = other.memory_dump;

        try {
            delete[] this->buffer;
            this->buffer = new T[this->memory_dump];

        } catch (std::bad_alloc& ex) {
            throw bad_memory_allocation_exception("matrix_base::(bad memory allocation)!");
        }

        std::copy(other.buffer, other.buffer + other.memory_dump, this->buffer);
    }

    return *this;
}

template <class T>
matrix_base<T>& matrix_base<T>::operator=(matrix_base&& other) {
    if (this != &other) {
        this->row_count = other.row_count;
        this->col_count = other.col_count;
        this->memory_dump = other.memory_dump;

        delete[] this->buffer;
        this->buffer = other.buffer;

        other.row_count = 0;
        other.col_count = 0;
        other.memory_dump = 0;
        other.buffer = nullptr;
    }

    return *this;
}

template <class T>
matrix_base<T>& matrix_base<T>::operator=(std::initializer_list<T> lst) {
    size_t size = this->memory_dump <= lst.size() ? this->memory_dump : lst.size();
    typename std::initializer_list<T>::const_iterator iter = lst.begin();

    for (size_t i = 0; i < size; ++i, ++iter) {
        this->buffer[i] = *iter;
    }

    for (size_t i = size; i < this->memory_dump; ++i) {
        this->buffer[i] = 0;
    }

    return *this;
}

template <class T>
typename matrix_base<T>::proxy matrix_base<T>::at(size_t index) {
    if (index < this->row_count) {
        return proxy(this->col_count, this->buffer + this->col_count * index);

    } else {
        throw out_of_range_exception("matrix_base::(out of range index)!");
    }
}

template <class T>
const typename matrix_base<T>::proxy matrix_base<T>::at(size_t index) const {
    if (index < this->row_count) {
        return proxy(this->col_count, this->buffer + this->col_count * index);

    } else {
        throw out_of_range_exception("matrix_base::(out of range index)!");
    }
}

template <class T>
typename matrix_base<T>::proxy matrix_base<T>::operator[](size_t index) {
    if (index < this->row_count) {
        return proxy(this->col_count, this->buffer + this->col_count * index);

    } else {
        throw out_of_range_exception("matrix_base::(out of range index)!");
    }
}

template <class T>
const typename matrix_base<T>::proxy matrix_base<T>::operator[](size_t index) const {
    if (index < this->row_count) {
        return proxy(this->col_count, this->buffer + this->col_count * index);

    } else {
        throw out_of_range_exception("matrix_base::(out of range index)!");
    }
}

template <class T>
typename matrix_base<T>::iterator matrix_base<T>::begin() {
    return iterator(this->buffer);
}

template <class T>
typename matrix_base<T>::const_iterator matrix_base<T>::cbegin() const {
    return const_iterator(this->buffer);
}

template <class T>
typename matrix_base<T>::iterator matrix_base<T>::end() {
    return iterator(this->buffer + this->memory_dump);
}

template <class T>
typename matrix_base<T>::const_iterator matrix_base<T>::cend() const {
    return const_iterator(this->buffer + this->memory_dump);
}

template <class T>
typename matrix_base<T>::iterator matrix_base<T>::rbegin() {
    return iterator(this->buffer + this->memory_dump - 1);
}

template <class T>
typename matrix_base<T>::const_iterator matrix_base<T>::rcbegin() const {
    return const_iterator(this->buffer + this->memory_dump - 1);
}

template <class T>
typename matrix_base<T>::iterator matrix_base<T>::rend() {
    return iterator(this->buffer - 1);
}

template <class T>
typename matrix_base<T>::const_iterator matrix_base<T>::rcend() const {
    return const_iterator(this->buffer - 1);
}

template <class T>
size_t matrix_base<T>::rows() const {
    return this->row_count;
}

template <class T>
size_t matrix_base<T>::columns() const {
    return this->col_count;
}

template <class T>
size_t matrix_base<T>::capacity() const {
    return this->memory_dump;
}

template <class T>
void matrix_base<T>::zero() {
    for (size_t i = 0; i < this->memory_dump; ++i) {
        this->buffer[i] = T();
    }
}

template <class T>
void matrix_base<T>::swap(matrix_base<T>& other) {
    std::swap(this->row_count, other.row_count);
    std::swap(this->col_count, other.col_count);
    std::swap(this->memory_dump, other.memory_dump);
    std::swap(this->buffer, other.buffer);
}

template <class T>
void swap(matrix_base<T>& lhs, matrix_base<T>& rhs) {
    lhs.swap(rhs);
}

template <class T>
bool operator==(const matrix_base<T>& lhs, const matrix_base<T>& rhs) {
    bool are_equal = lhs.size() == rhs.size();

    if (are_equal) {

        for (size_t i = 0; i < lhs.size() && are_equal; ++i) {

            if (lhs[i] != rhs[i]) {
                are_equal = false;
            }
        }
    }

    return are_equal;
}

template <class T>
bool operator!=(const matrix_base<T>& lhs, const matrix_base<T>& rhs) {
    return !(rhs == lhs);
}

template <class T>
bool operator<(const matrix_base<T>& lhs, const matrix_base<T>& rhs) {
    bool is_less = lhs.size() < rhs.size();

    if (!is_less && lhs.size() == rhs.size()) {

        for (size_t i = 0; i < lhs.size() && !is_less; ++i) {

            if (lhs[i] < rhs[i]) {
                is_less = true;
            }
        }
    }

    return is_less;
}

template <class T>
bool operator<=(const matrix_base<T>& lhs, const matrix_base<T>& rhs) {
    return lhs < rhs || lhs == rhs;
}

template <class T>
bool operator>(const matrix_base<T>& lhs, const matrix_base<T>& rhs) {
    return !(lhs < rhs) && !(lhs == rhs);
}

template <class T>
bool operator>=(const matrix_base<T>& lhs, const matrix_base<T>& rhs) {
    return lhs > rhs || lhs == rhs;
}

template <class T>
std::ostream& operator<<(std::ostream& stream, const matrix_base<T>& mtx) {
    for (size_t i = 0; i < mtx.rows(); ++i) {

        for (size_t j = 0; j < mtx.columns(); ++j) {
            stream << mtx[i][j] << " ";
        }

        stream << std::endl;
    }

    return stream;
}

#endif // MATRIX_BASE_HPP
