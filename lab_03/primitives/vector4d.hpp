#ifndef VECTOR4D_HPP
#define VECTOR4D_HPP

#include <cmath>

#include "containers/vector/vector.hpp"

template <class T>
class vector4d : public vector<T> {
        static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic!");

    public:
        vector4d();
        vector4d(const T&, const T&, const T&);
        vector4d(std::initializer_list<T>);
        vector4d(const vector4d&);
        vector4d(vector4d&&);

        vector4d& operator=(const vector<T>&);
        vector4d& operator=(vector4d&&);

        T calculate_module();
        void normalize();

        static T scalar_product(const vector4d&, const vector4d&);
        static T angle(const vector4d&, const vector4d&);
        static vector4d cross(const vector4d&, const vector4d&);
};

template <class T>
vector4d<T>::vector4d()
    : vector<T>(4) {
    *(reinterpret_cast<vector<double>*>(this)) = {0, 0, 0, 1};
}

template <class T>
vector4d<T>::vector4d(const T& x, const T& y, const T& z)
    : vector<T>(4) {
    *this = {x, y, z, 1};
}

template <class T>
vector4d<T>::vector4d(std::initializer_list<T> lst)
    : vector<T>(lst) {

}

template <class T>
vector4d<T>::vector4d(const vector4d<T>& other)
    : vector<T>(other) {

}

template <class T>
vector4d<T>::vector4d(vector4d<T>&& other)
    : vector<T>(std::move(other)) {

}

template <class T>
T vector4d<T>::calculate_module() {
    const T x = (*this)[0];
    const T y = (*this)[1];
    const T z = (*this)[2];

    return sqrt(x * x + y * y + z * z);
}

template <class T>
void vector4d<T>::normalize() {
    const T norm = 1 / this->calculate_module();

    for (size_t i = 0; i < this->size() - 1; ++i) {
        (*this)[i] *= norm;
    }
}

template <class T>
T vector4d<T>::scalar_product(const vector4d<T>& vec1, const vector4d<T>& vec2) {
    return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

template <class T>
T vector4d<T>::angle(const vector4d<T>& vec1, const vector4d<T>& vec2) {
    return scalar_product(vec1, vec2) / (vec1.calculate_module() * vec2.calculate_module());
}

template <class T>
vector4d<T> vector4d<T>::cross(const vector4d<T>& vec1, const vector4d<T>& vec2) {
    vector4d<T> result;
    result[0] = vec1[2] * vec2[1] - vec1[1] * vec2[2];
    result[1] = vec1[0] * vec2[2] - vec1[2] * vec2[0];
    result[2] = vec1[1] * vec2[0] - vec1[0] * vec2[1];
    result[3] = 1;

    return result;
}

template <class T>
vector4d<T>& vector4d<T>::operator=(const vector<T>& other) {
    vector<T>::operator=(other);
    return *this;
}

template <class T>
vector4d<T>& vector4d<T>::operator=(vector4d<T>&& other) {
    vector<T>::operator =(std::move(other));
    return *this;
}

#endif // VECTOR4D_HPP
