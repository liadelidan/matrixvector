#include "Matrix3D.h"

/**
 * CPP file of class Matrix3D
 */

Matrix3D::Matrix3D()
{
    Vector3D zero_vector(RESET, RESET, RESET);
    _vector1 = zero_vector;
    _vector2 = zero_vector;
    _vector3 = zero_vector;
}

Matrix3D::Matrix3D(double x)
{
    Vector3D first_vector(x, RESET, RESET);
    Vector3D second_vector(RESET, x, RESET);
    Vector3D third_vector(RESET, RESET, x);

    _vector1 = first_vector;
    _vector2 = second_vector;
    _vector3 = third_vector;
}

Matrix3D::Matrix3D(double x1, double y1, double z1, double x2, double y2, double z2,
                   double x3, double y3, double z3)
{
    Vector3D first_vector(x1, y1, z1);
    Vector3D second_vector(x2, y2, z2);
    Vector3D third_vector(x3, y3, z3);

    _vector1 = first_vector;
    _vector2 = second_vector;
    _vector3 = third_vector;
}

Matrix3D::Matrix3D(double arr[MATRIX_SIZE])
{

    Vector3D first_vector(arr[0], arr[1], arr[2]);
    Vector3D second_vector(arr[3], arr[4], arr[5]);
    Vector3D third_vector(arr[6], arr[7], arr[8]);

    _vector1 = first_vector;
    _vector2 = second_vector;
    _vector3 = third_vector;
}

Matrix3D::Matrix3D(double arr[VECTOR_SIZE][VECTOR_SIZE])
{

    Vector3D first_vector(arr[0][0], arr[0][1], arr[0][2]);
    Vector3D second_vector(arr[1][0], arr[1][1], arr[1][2]);
    Vector3D third_vector(arr[2][0], arr[2][1], arr[2][2]);

    _vector1 = first_vector;
    _vector2 = second_vector;
    _vector3 = third_vector;
}

Matrix3D::Matrix3D(Vector3D other1, Vector3D other2, Vector3D other3)
{
    _vector1 = other1;
    _vector2 = other2;
    _vector3 = other3;
}

Matrix3D::Matrix3D(const Matrix3D& old_matrix)
{
    _vector1 = old_matrix._vector1;
    _vector2 = old_matrix._vector2;
    _vector3 = old_matrix._vector3;
}

Matrix3D& Matrix3D::operator+=(const Matrix3D& other)
{
    _vector1 += other._vector1;
    _vector2 += other._vector2;
    _vector3 += other._vector3;

    return *this;
}

Matrix3D& Matrix3D::operator-=(const Matrix3D& other)
{
    _vector1 -= other._vector1;
    _vector2 -= other._vector2;
    _vector3 -= other._vector3;

    return *this;
}

Matrix3D Matrix3D::operator*=(Matrix3D& other)
{
    *this = *this * other;

    return *this;
}


Matrix3D Matrix3D::operator*(Matrix3D& other)
{
    Matrix3D matrix;

    for (int i = RESET; i < VECTOR_SIZE; i++)
    {
        //first row
        matrix._vector1[i] = this->_vector1[X_VAL] * other._vector1[i] + this->_vector1[Y_VAL]
                * other._vector2[i] + this->_vector1[Z_VAL] * other._vector3[i];
        //second row
        matrix._vector2[i] = this->_vector2[X_VAL] * other._vector1[i] + this->_vector2[Y_VAL]
                * other._vector2[i] + this->_vector2[Z_VAL] * other._vector3[i];
        //third row
        matrix._vector3[i] = this->_vector3[X_VAL] * other._vector1[i] + this->_vector3[Y_VAL]
                * other._vector2[i] + this->_vector3[Z_VAL] * other._vector3[i];
    }

    return matrix;
}


Matrix3D Matrix3D::operator+(const Matrix3D& other)
{
    Matrix3D matrix;
    matrix._vector1 = this->_vector1 + other._vector1;
    matrix._vector2 = this->_vector2 + other._vector2;
    matrix._vector3 = this->_vector3 + other._vector3;

    return matrix;
}

Matrix3D Matrix3D::operator-(const Matrix3D& other)
{
    Matrix3D matrix;
    matrix._vector1 = this->_vector1 - other._vector1;
    matrix._vector2 = this->_vector2 - other._vector2;
    matrix._vector3 = this->_vector3 - other._vector3;

    return matrix;
}


Matrix3D Matrix3D::operator*=(const double& other)
{
    this->_vector1 *= other;
    this->_vector2 *= other;
    this->_vector3 *= other;

    return *this;
}


Matrix3D Matrix3D::operator/=(const double& other)
{
    this->_vector1 /= other;
    this->_vector2 /= other;
    this->_vector3 /= other;

    return *this;
}

Vector3D Matrix3D::operator*( Vector3D& other)
{
    Vector3D result(this->_vector1* other, this->_vector2 * other , this->_vector3 * other);

    return result;
}


// [] overloading
Vector3D& Matrix3D::operator[](const int &index)
{
    if (index == X_VAL)
    {
        return this->_vector1;
    }
    else if(index == Y_VAL)
    {
        return this->_vector2;
    }
    else
    {
        return this->_vector3;
    }
}

Matrix3D& Matrix3D::operator=(const Matrix3D& other)
{
    _vector1 = other._vector1;
    _vector2 = other._vector2;
    _vector3 = other._vector3;

    return *this;
}

std::ostream& operator<<(std::ostream &out, const Matrix3D &matrix)
{
    out << matrix._vector1 << std::endl << matrix._vector2 << std::endl << matrix._vector3;

    return out;
}

std::istream& operator>>(std::istream &input, Matrix3D &matrix)
{
    input >> matrix._vector1 >> matrix._vector2 >> matrix._vector3;

    return input;
}

Vector3D Matrix3D::row(short index)
{
    if (index == X_VAL)
    {
        return _vector1;
    }
    else if(index == Y_VAL)
    {
        return _vector2;
    }
    else
    {
        return _vector3;
    }
}

Vector3D Matrix3D::column(short index)
{
    Vector3D new_vector;

    if (index == X_VAL)
    {
        new_vector[X_VAL] = this->_vector1[X_VAL];
        new_vector[Y_VAL] = this->_vector2[X_VAL];
        new_vector[Z_VAL] = this->_vector3[X_VAL];
    }
    else if(index == Y_VAL)
    {
        new_vector[X_VAL] = this->_vector1[Y_VAL];
        new_vector[Y_VAL] = this->_vector2[Y_VAL];
        new_vector[Z_VAL] = this->_vector3[Y_VAL];
    }
    else
    {
        new_vector[X_VAL] = this->_vector1[Z_VAL];
        new_vector[Y_VAL] = this->_vector2[Z_VAL];
        new_vector[Z_VAL] = this->_vector3[Z_VAL];
    }

    return new_vector;
}

double Matrix3D::trace()
{
    double sum = RESET;
    sum = this->_vector1[X_VAL] + this->_vector2[Y_VAL] + this->_vector3[Z_VAL];
    return sum;
}

double Matrix3D::determinant()
{
    double total_sum = RESET;
    Matrix3D A(_vector1, _vector2, _vector3);
    Matrix3D B(_vector2, _vector3, _vector1);
    Matrix3D C(_vector3, _vector1, _vector2);
    double sum1 = A._vector1[X_VAL] * A._vector2[Y_VAL] * A._vector3[Z_VAL];
    double sum2 = (B._vector1[X_VAL] * B._vector2[Y_VAL] * B._vector3[Z_VAL]) +
            (C._vector1[X_VAL] * C._vector2[Y_VAL] * C._vector3[Z_VAL]);
    double sum3 = -(A._vector3[X_VAL] * A._vector2[Y_VAL] * A._vector1[Z_VAL]) -
            (B._vector3[X_VAL] * B._vector2[Y_VAL] * B._vector1[Z_VAL])
            - (C._vector3[X_VAL] * C._vector2[Y_VAL] * C._vector1[Z_VAL]);
    total_sum = sum1 + sum2 + sum3;

    return total_sum;
}