#ifndef POINT3D_HPP
#define POINT3D_HPP

#include <type_traits>
#include <ostream>

#include "containers/vector/vector.hpp"

template <class T>
class point3d {
        static_assert(std::is_arithmetic<T>::value, "Type must be arithmetic!");

    public:
        explicit point3d();
        explicit point3d(const T&, const T&, const T&);
        point3d(const point3d&);
        point3d(point3d&&);
        ~point3d() = default;

        point3d& operator=(const point3d&);
        point3d& operator=(point3d&&);

        T& get_x();
        const T& get_x() const;
        T& get_y();
        const T& get_y() const;
        T& get_z();
        const T& get_z() const;

        void set_x(const T&);
        void set_y(const T&);
        void set_z(const T&);

        vector<T> to_vector4d() const;

        void swap(point3d&);
        template <class U>
        friend inline void swap(point3d<U>&, point3d<U>&);

        template <class U>
        friend inline point3d<U> operator+(const point3d<U>&, const point3d<U>&);
        template <class U>
        friend inline point3d<U> operator+(const point3d<U>&, const U&);
        template <class U>
        friend inline point3d<U> operator-(const point3d<U>&, const point3d<U>&);
        template <class U>
        friend inline point3d<U> operator-(const point3d<U>&, const U&);
        template <class U>
        friend inline point3d<U> operator*(const point3d<U>&, const point3d<U>&);
        template <class U>
        friend inline point3d<U> operator*(const point3d<U>&, const U&);
        template <class U>
        friend inline point3d<U> operator/(const point3d<U>&, const point3d<U>&);
        template <class U>
        friend inline point3d<U> operator/(const point3d<U>&, const U&);

        inline point3d& operator+=(const point3d&);
        inline point3d& operator+=(const T&);
        inline point3d& operator-=(const point3d&);
        inline point3d& operator-=(const T&);
        inline point3d& operator*=(const point3d&);
        inline point3d& operator*=(const T&);
        inline point3d& operator/=(const point3d&);
        inline point3d& operator/=(const T&);

        template <class U>
        friend inline bool operator==(const point3d<U>&, const point3d<U>&);
        template <class U>
        friend inline bool operator!=(const point3d<U>&, const point3d<U>&);

        template <class U>
        friend std::ostream& operator<<(std::ostream&, const point3d<U>&);

    private:
        T x, y, z;
};

template <class T>
point3d<T>::point3d() : x(0), y(0), z(0) {

}

template <class T>
point3d<T>::point3d(const T& x, const T& y, const T& z) : x(x), y(y), z(z) {

}

template <class T>
point3d<T>::point3d(const point3d<T>& other) : point3d(other.x, other.y, other.z) {

}

template <class T>
point3d<T>::point3d(point3d<T>&& other) : point3d(other.x, other.y, other.z) {
    other.~point3d();
}

template <class T>
point3d<T>& point3d<T>::operator=(const point3d<T>& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;

    return *this;
}

template <class T>
point3d<T>& point3d<T>::operator=(point3d<T>&& rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->z = rhs.z;
    rhs.~point3d();

    return *this;
}

template <class T>
T& point3d<T>::get_x() {
    return this->x;
}

template <class T>
const T& point3d<T>::get_x() const {
    return this->x;
}

template <class T>
T& point3d<T>::get_y() {
    return this->y;
}

template <class T>
const T& point3d<T>::get_y() const {
    return this->y;
}

template <class T>
T& point3d<T>::get_z() {
    return this->z;
}

template <class T>
const T& point3d<T>::get_z() const {
    return this->z;
}

template <class T>
void point3d<T>::set_x(const T& x) {
    this->x = x;
}

template <class T>
void point3d<T>::set_y(const T& y) {
    this->y = y;
}

template <class T>
void point3d<T>::set_z(const T& z) {
    this->z = z;
}

template <class T>
vector<T> point3d<T>::to_vector4d() const {
    return vector<T>({this->x, this->y, this->z, 1});
}

template <class T>
void point3d<T>::swap(point3d& other) {
    std::swap(this->x, other.x);
    std::swap(this->y, other.y);
    std::swap(this->z, other.z);
}

template <class T>
void swap(point3d<T>& lhs, point3d<T>& rhs) {
    lhs.swap(rhs);
}

template <class T>
point3d<T> operator+(const point3d<T>& rhs, const point3d<T>& lhs) {
    point3d<T> result = rhs;
    result.x += lhs.x;
    result.y += lhs.y;
    result.z += lhs.z;

    return result;
}

template <class T>
point3d<T> operator+(const point3d<T>& pnt, const T& value) {
    point3d<T> result = pnt;
    result.x += value;
    result.y += value;
    result.z += value;

    return result;
}

template <class T>
point3d<T> operator-(const point3d<T>& rhs, const point3d<T>& lhs) {
    point3d<T> result = rhs;
    result.x -= lhs.x;
    result.y -= lhs.y;
    result.z -= lhs.z;

    return result;
}

template <class T>
point3d<T> operator-(const point3d<T>& pnt, const T& value) {
    point3d<T> result = pnt;
    result.x -= value;
    result.y -= value;
    result.z -= value;

    return result;
}

template <class T>
point3d<T> operator*(const point3d<T>& rhs, const point3d<T>& lhs) {
    point3d<T> result = rhs;
    result.x *= lhs.x;
    result.y *= lhs.y;
    result.z *= lhs.z;

    return result;
}

template <class T>
point3d<T> operator*(const point3d<T>& pnt, const T& value) {
    point3d<T> result = pnt;
    result.x *= value;
    result.y *= value;
    result.z *= value;

    return result;
}

template <class T>
point3d<T> operator/(const point3d<T>& rhs, const point3d<T>& lhs) {
    point3d<T> result = rhs;
    result.x /= lhs.x;
    result.y /= lhs.y;
    result.z /= lhs.z;

    return result;
}

template <class T>
point3d<T> operator/(const point3d<T>& pnt, const T& value) {
    point3d<T> result = pnt;
    result.x /= value;
    result.y /= value;
    result.z /= value;

    return result;
}

template <class T>
point3d<T>& point3d<T>::operator+=(const point3d<T>& pnt) {
    this->x += pnt.x;
    this->y += pnt.y;
    this->z += pnt.z;

    return *this;
}

template <class T>
point3d<T>& point3d<T>::operator+=(const T& value) {
    this->x += value;
    this->y += value;
    this->z += value;

    return *this;
}

template <class T>
point3d<T>& point3d<T>::operator-=(const point3d<T>& pnt) {
    this->x -= pnt.x;
    this->y -= pnt.y;
    this->z -= pnt.z;

    return *this;
}

template <class T>
point3d<T>& point3d<T>::operator-=(const T& value) {
    this->x -= value;
    this->y -= value;
    this->z -= value;

    return *this;
}

template <class T>
point3d<T>& point3d<T>::operator*=(const point3d<T>& pnt) {
    this->x *= pnt.x;
    this->y *= pnt.y;
    this->z *= pnt.z;

    return *this;
}

template <class T>
point3d<T>& point3d<T>::operator*=(const T& value) {
    this->x *= value;
    this->y *= value;
    this->z *= value;

    return *this;
}

template <class T>
point3d<T>& point3d<T>::operator/=(const point3d<T>& pnt) {
    this->x /= pnt.x;
    this->y /= pnt.y;
    this->z /= pnt.z;

    return *this;
}

template <class T>
point3d<T>& point3d<T>::operator/=(const T& value) {
    this->x /= value;
    this->y /= value;
    this->z /= value;

    return *this;
}

template <class T>
bool operator==(const point3d<T>& rhs, const point3d<T>& lhs) {
    return rhs.x == lhs.x && rhs.y == lhs.y && rhs.z == lhs.z;
}

template <class T>
bool operator!=(const point3d<T>& rhs, const point3d<T>& lhs) {
    return !(lhs == rhs);
}

template <class T>
std::ostream& operator<<(std::ostream& stream, const point3d<T>& pnt) {
    return stream << "point3d(" << pnt.x << ", " << pnt.y << ", " << pnt.z << ")" << std::endl;
}

#endif // POINT3D_HPP
