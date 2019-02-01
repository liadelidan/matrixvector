/**
 * Class Vector3D header
 * Created by Liad Elidan, 203380050, user:sharon1832
 */

#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H

#include "iostream"

/* Constants */
#define ARRAY_SIZE 3
#define X_VAL 0
#define Y_VAL 1
#define Z_VAL 2
#define MINUS_VEC -1
#define POW_2 2
#define RESET 0
#define VECTOR_SIZE 3
#define MATRIX_SIZE 9
/**
 * Class Vector3D
 */
class Vector3D
{

private:
    double _x, _y, _z;

public:
    /**
     * Default constructor zeros the x,y,z.
     */
    Vector3D ();

    /**
     * Vector constructor from 3 arguments.
     * @param x is a double, x coordinate
     * @param y is a double, y coordinate
     * @param z is a double, z coordinate
     */
    Vector3D (double x, double y, double z);

    /**
     * Vector constructor to build a vector with an array of size 3.
     * @param data, double array of size 3.
     */
    explicit Vector3D (double data[ARRAY_SIZE]);

    /**
     * Copy constructor
     */
    Vector3D (const Vector3D&);

    /**
     * Overloading "+" operator between two vectors and returning a new one.
     * @param other, Vector3D object.
     * @return Vector3D object, which is the vector after adding the two vectors.
     */
    Vector3D operator+(const Vector3D& other);

    /**
     * Overloading "-" operator between two vectors and returning a new one.
     * @param other, Vector3D object.
     * @return Vector3D object, which is the vector after subtracting the two vectors.
     */
    Vector3D operator-(const Vector3D& other);

    /**
     * Overloading "+=" operator between a vector and another one.
     * @param other, Vector3D object.
     * @return Vector3D object, which is the vector after adding the vectors.
     */
    Vector3D& operator+=(const Vector3D& other);

    /**
     * Overloading "-=" operator between a vector and another one.
     * @param other, Vector3D object.
     * @return Vector3D object, which is the vector after subtracting the vectors.
     */
    Vector3D& operator-=(const Vector3D& other);

    /**
     * Overloading "=" operator between a vector and another one.
     * @param other, Vector3D object.
     * @return Vector3D object, which is a copy of the vector received.
     */
    Vector3D& operator=(const Vector3D& other);

    /**
     * Overloading "+=" operator between a vector and a number.
     * @param other, double& the number to add.
     * @return Vector3D object, which is the vector plus the number received.
     */
    Vector3D& operator+=(const double& other);

    /**
     * Overloading "-=" operator between a vector and a number.
     * @param other, double& the number to subtract.
     * @return Vector3D object, which is the vector minus the number received.
     */
    Vector3D& operator-=(const double& other);

    /**
     * Overloading "-" to a vector.
     * @return Vector3D object, which is the vector while having a -1 to all of it.
     */
    Vector3D operator-();

    /**
     * Overloading "*" operator between a vector and a number.
     * @param other, double& the number to multiply.
     * @return Vector3D object, which is the vector while multiplied other to all of it.
     */
    Vector3D operator*(const double& other);

    /**
     * Overloading "/" operator between a vector and a number.
     * @param other, double& the number to divide.
     * @return Vector3D object, which is the vector while divided other to all of it.
     */
    Vector3D operator/(const double& other);

    /**
     * Overloading "*=" operator between a vector and a number.
     * @param other, double& the number to multiply.
     * @return Vector3D object, which is the vector multiplied by other.
     */
    Vector3D& operator*=(const double& other);

    /**
     * Overloading "/=" operator between a vector and a number.
     * @param other, double& the number to divide.
     * @return Vector3D object, which is the vector divided by other.
     */
    Vector3D& operator/=(const double& other);

    /**
     * Overloading "|" operator between two vectors. distance.
     * @param other, Vector3D object.
     * @return double , distance between the two vectors.
     */
    double operator|(const Vector3D& other);

    /**
     * Overloading "*" operator between two vectors, return scalar multiplication.
     * @param other, Vector3D object.
     * @return double , scalar multiplication between the two vectors.
     */
    double operator*(Vector3D& other);

    /**
     * Overloading "^" operator between two vectors. the angle.
     * @param other, Vector3D object.
     * @return double, the angle between them in radians.
     */
    double operator^(Vector3D& other);

    /**
     * Overloading "[]" of a vector.
     * @param index, an int number which is the index in the array of the vector.
     * @return double&, which has the value in the appropriate array index.
     */
    double& operator[] (const int &index);

    /**
     * Overloading "<<" the output to the ostream.
     * @param out, std::ostream& variable.
     * @param vector, Vector3D object.
     * @return std::ostream& used in the output.
     */
    friend std::ostream& operator<<(std::ostream& out, const Vector3D& vector);

    /**
     * Overloading ">>" the input to the istream.
     * @param input, std::istream& variable.
     * @param vector, Vector3D object
     * @return std::istream& input, used in the input.
     */
    friend std::istream& operator>>(std::istream& input, Vector3D& vector);

    /**
     * Overloading "*" operator between a number and a vector received.
     * @param num, double, a number to multiply.
     * @param other, Vector3D object received, the vector to be multiplied.
     * @return Vector3D object, the vector after the multiplication.
     */
    friend Vector3D operator * (double num, Vector3D& other);

    /**
     * Function to calculate the norm of a vector.
     * @return double, the norm of the vector.
     */
    double norm();

    /**
     * Function to calculate the distance between two vectors, the current one and one received.
     * @param vector
     * @return double, the distance between the vectors.
     */
    double dist(const Vector3D& vector);

};


#endif //EX1_VECTOR3D_H