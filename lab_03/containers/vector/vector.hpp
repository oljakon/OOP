#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstring>

#include "vector_base.hpp"

template <class T>
class vector : public vector_base<T> {
        const size_t GROW_COEF = 2;

    public:
        typedef typename vector_base<T>::iterator iterator;
        typedef typename vector_base<T>::const_iterator const_iterator;

        explicit vector();
        explicit vector(size_t);
        explicit vector(size_t, const T&);
        vector(iterator, iterator);
        vector(const_iterator, const_iterator);
        vector(std::initializer_list<T>);
        vector(const vector&);
        vector(vector&&);
        virtual ~vector() = default;
        vector& operator=(const vector&);
        vector& operator=(vector&&);
        void assign(size_t, const T&);
        void assign(iterator, iterator);
        void assign(const_iterator, const_iterator);

        size_t max_size() const;
        void reserve(size_t);
        void shrink_to_fit();

        void insert(size_t, const T&);
        void insert(size_t, T&&);
        void erase(size_t);
        void push_back(const T&);
        void push_back(T&&);
        void pop_back();
        void resize(size_t);
        void resize(size_t, const T&);
};

template <class T>
vector<T>::vector() : vector_base<T>() {

}

template <class T>
vector<T>::vector(size_t count) : vector_base<T>(count) {

}

template <class T>
vector<T>::vector(size_t count, const T& value) : vector_base<T>(count, value) {

}

template <class T>
vector<T>::vector(iterator first, iterator last) : vector_base<T>(first, last) {

}

template <class T>
vector<T>::vector(const_iterator first, const_iterator last) : vector_base<T>(first, last) {

}

template <class T>
vector<T>::vector(std::initializer_list<T> lst) : vector_base<T>(lst) {

}

template <class T>
vector<T>::vector(const vector<T>& other) : vector_base<T>(other) {

}

template <class T>
vector<T>::vector(vector<T>&& other) : vector_base<T>(std::move(other)) {

}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>& rhs) {
    vector_base<T>::operator=(rhs);
    return *this;
}

template <class T>
vector<T>& vector<T>::operator=(vector<T>&& rhs) {
    vector_base<T>::operator=(std::move(rhs));
    return *this;
}

template <class T>
void vector<T>::assign(size_t count, const T& value) {
    if (count > this->capacity()) {
        this->memory_dump = count << GROW_COEF;
        this->reallocate();
    }

    for (size_t i = 0; i < count; ++i) {
        (*this)[i] = value;
    }

    this->element_count = count;
}

template <class T>
void vector<T>::assign(iterator first, iterator last) {
    size_t count = last - first;

    if (count > this->capacity()) {
        this->memory_dump = count << GROW_COEF;
        this->reallocate();
    }

    for (size_t i = 0; i < count; ++i, ++first) {
        (*this)[i] = *first;
    }

    this->element_count = count;
}

template <class T>
void vector<T>::assign(const_iterator first, const_iterator last) {
    size_t count = last - first;

    if (count > this->capacity()) {
        this->memory_dump = count << GROW_COEF;
        this->reallocate();
    }

    for (size_t i = 0; i < count; ++i, ++first) {
        (*this)[i] = *first;
    }

    this->element_count = count;
}

template <class T>
size_t vector<T>::max_size() const {
    return this->capacity();
}

template <class T>
void vector<T>::reserve(size_t size) {
    if (size > this->memory_dump) {
        this->memory_dump = size;
        this->reallocate();
    }
}

template <class T>
void vector<T>::shrink_to_fit() {
    this->memory_dump = this->size();
    this->reallocate();
}

template <class T>
void vector<T>::insert(size_t pos, const T& value) {
    if (this->size() == this->capacity()) {
        this->memory_dump <<= GROW_COEF;
        this->reallocate();
    }

    T* mem_flag = this->buffer + pos;
    std::memmove(mem_flag + 1, mem_flag, (this->size() - (mem_flag - this->buffer)) * sizeof(T));
    ++this->element_count;
    (*this)[pos] = value;
}

template <class T>
void vector<T>::insert(size_t pos, T&& value) {
    if (this->size() == this->capacity()) {
        this->memory_dump <<= GROW_COEF;
        this->reallocate();
    }

    T* mem_flag = this->buffer + pos;
    std::memmove(mem_flag + 1, mem_flag, (this->size() - (mem_flag - this->buffer)) * sizeof(T));
    ++this->element_count;
    (*this)[pos] = std::move(value);
}

template <class T>
void vector<T>::erase(size_t pos) {
    T* mem_flag = this->buffer + pos;
    std::memmove(mem_flag, mem_flag + 1, (this->size() - (mem_flag - this->buffer) - 1) * sizeof(T));
    --this->element_count;
}

template <class T>
void vector<T>::push_back(const T& value) {
    if (this->size() == this->capacity()) {
        this->memory_dump <<= GROW_COEF;
        this->reallocate();
    }

    (*this)[this->element_count++] = value;
}

template <class T>
void vector<T>::push_back(T&& value) {
    if (this->size() == this->capacity()) {
        this->memory_dump <<= GROW_COEF;
        this->reallocate();
    }

    (*this)[this->element_count++] = std::move(value);
}

template <class T>
void vector<T>::pop_back() {
    --this->element_count;
}

template <class T>
void vector<T>::resize(size_t size) {
    if (size > this->size()) {

        if (size > this->memory_dump) {
            this->memory_dump = size;
            this->reallocate();
        }

    } else {

        for (size_t i = this->size(); i < size; ++i) {
            (*this)[i].~T();
        }
    }

    this->element_count = size;
}

template <class T>
void vector<T>::resize(size_t size, const T& value) {
    if (size > this->size()) {

        if (size > this->capacity()) {
            this->memory_dump = size;
            this->reallocate();
        }

        for (size_t i = this->size(); i < size; ++i) {
            (*this)[i] = value;
        }

    } else {

        for (size_t i = this->size(); i < size; ++i) {
            (*this)[i].~T();
        }
    }

    this->element_count = size;
}

#endif // VECTOR_HPP
