#include "Vector3D.h"
#include "iostream"
#include <math.h>

/**
 * CPP file of class Vector3D
 */

Vector3D::Vector3D ()
{
    _x = RESET;
    _y = RESET;
    _z = RESET;
}

Vector3D::Vector3D (double x, double y, double z)
{
    _x = x;
    _y = y;
    _z = z;
}

Vector3D::Vector3D (double data[ARRAY_SIZE])
{
    _x = data[X_VAL];
    _y = data[Y_VAL];
    _z = data[Z_VAL];
}

Vector3D::Vector3D(const Vector3D& old_vector)
{
    _x = old_vector._x;
    _y = old_vector._y;
    _z = old_vector._z;
}

Vector3D Vector3D::operator+(const Vector3D& other)
{
    Vector3D vector;
    vector._x = this->_x + other._x;
    vector._y = this->_y + other._y;
    vector._z = this->_z + other._z;

    return vector;
}

Vector3D Vector3D::operator-(const Vector3D& other)
{
    Vector3D vector;
    vector._x = this->_x - other._x;
    vector._y = this->_y - other._y;
    vector._z = this->_z - other._z;

    return vector;
}

Vector3D& Vector3D::operator+=(const Vector3D& other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;

    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;

    return *this;
}

Vector3D& Vector3D::operator=(const Vector3D& other)
{
    _x = other._x;
    _y = other._y;
    _z = other._z;

    return *this;
}

Vector3D& Vector3D::operator+=(const double& other)
{
    _x += other;
    _y += other;
    _z += other;

    return *this;
}

Vector3D& Vector3D::operator-=(const double& other)
{
    _x -= other;
    _y -= other;
    _z -= other;

    return *this;
}

Vector3D Vector3D:: operator-()
{
    Vector3D vector;
    vector._x = (this->_x) * MINUS_VEC;
    vector._y = (this->_y) * MINUS_VEC;
    vector._z = (this->_z) * MINUS_VEC;

    return vector;
}

Vector3D Vector3D:: operator*(const double& other)
{
    Vector3D vector;
    vector._x = this->_x * other;
    vector._y = this->_y * other;
    vector._z = this->_z * other;

    return vector;
}

Vector3D Vector3D:: operator/(const double& other)
{
    Vector3D vector;
    vector._x = this->_x / other;
    vector._y = this->_y / other;
    vector._z = this->_z / other;

    return vector;
}

Vector3D& Vector3D:: operator*=(const double& other)
{
    _x *= other;
    _y *= other;
    _z *= other;

    return *this;
}

Vector3D& Vector3D:: operator/=(const double& other)
{
    _x /= other;
    _y /= other;
    _z /= other;

    return *this;
}

double Vector3D:: operator|(const Vector3D &other)
{
    double result = sqrt(pow(this->_x - other._x, POW_2) + pow(this->_y - other._y, POW_2) + pow(this->_z - other._z, POW_2));

    return result;
}

double Vector3D::operator*(Vector3D& other)
{
    double result;
    result = this->_x * other[X_VAL] + this->_y * other[Y_VAL] + this->_z * other[Z_VAL];
    return result;
}

double Vector3D:: operator^(Vector3D &other)
{
    double result = acos((*this*other) / (this->norm()*other.norm()));

    return result;
}

double& Vector3D::operator[](const int &index)
{
    if (index == X_VAL)
    {
        return this->_x;
    }
    else if(index == Y_VAL)
    {
        return this->_y;
    }
    else
    {
        return this->_z;
    }
}

std::ostream& operator<<(std::ostream &out, const Vector3D &vector)
{
    out << vector._x << " " << vector._y << " " << vector._z;

    return out;
}

std::istream& operator>>(std::istream &input, Vector3D &vector)
{
    input >> vector._x >> vector._y >> vector._z;

    return input;
}

double Vector3D::norm()
{
    double result = sqrt(pow(this->_x, POW_2) + pow(this->_y, POW_2) + pow(this->_z, POW_2));

    return result;
}

double Vector3D::dist(const Vector3D& vector)
{
    return (*this) | vector;
}

Vector3D operator * (double num, Vector3D& other)
{
    Vector3D vector;
    vector._x = num * (other._x);
    vector._y = num * (other._y);
    vector._z = num * (other._z);

    return vector;
}
