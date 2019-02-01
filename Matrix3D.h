/**
 * Class Matrix3D header
 * Created by Liad Elidan, 203380050, user:sharon1832
 */

#ifndef EX1_MATRIX3D_H
#define EX1_MATRIX3D_H

#include "Vector3D.h"
#include "iostream"

class Matrix3D
{

private:
    Vector3D _vector1;
    Vector3D _vector2;
    Vector3D _vector3;

public:
    /**
     * Default constructor zeros all the matrix.
     */
    Matrix3D();

    /**
     * Constructor the receives a number and put diagonal and zeros
     * in the rest of the places of the matrix.
     * @param x, double the number to be put diagnoaly.
     */
    explicit Matrix3D(double x);

    /**
     * Constrcutor that receives 9 numbers and build a matrix from them.
     * @param x1, double.
     * @param y1, double.
     * @param z1, double.
     * @param x2, double.
     * @param y2, double.
     * @param z2, double.
     * @param x3, double.
     * @param y3, double.
     * @param z3, double.
     */
    explicit Matrix3D(double x1, double y1, double z1, double x2, double y2,
                      double z2, double x3, double y3, double z3);

    /**
     * Constructor that receives an array of size 9 to build a matrix from.
     * @param arr, double array of size 9.
     */
    explicit Matrix3D(double arr[9]);

    /**
     * Constructor that receives an [][] form array of size 3X3 and builds a matrix from it.
     * @param arr, double[][] array of size 3X3.
     */
    explicit Matrix3D(double arr[3][3]);

    /**
     * Constructor that recieves 3 Vector3D objects and builds a matrix from them/
     * @param other1, Vector3D object.
     * @param other2, Vector3D object.
     * @param other3, Vector3D object.
     */
    Matrix3D(Vector3D other1, Vector3D other2, Vector3D other3);

    /**
     * Copy constructor.
     */
    Matrix3D (const Matrix3D&);

    /**
     * Overloading "+=" operator between two matrixs, adding them.
     * @param other, Matrix3D& object.
     * @return Matrix3D& object which is the matrix after the "+=" operator.
     */
    Matrix3D& operator+=(const Matrix3D& other);

    /**
     * Overloading "-=" operator between two matrixs, subtracting them.
     * @param other, Matrix3D& object.
     * @return Matrix3D& object which is the matrix after the "-=" operator.
     */
    Matrix3D& operator-=(const Matrix3D& other);

    /**
     * Overloading "*=" operator between two matrixs, multiplying them.
     * @param other, Matrix3D& object.
     * @return Matrix3D object which is the matrix after the "*=" operator.
     */
    Matrix3D operator*=(Matrix3D& other);

    /**
     * Overloading "*" operator between two matrixs, multiplying them.
     * @param other, Matrix3D& object.
     * @return Matrix3D object which is the matrix after the "*" operator.
     */
    Matrix3D operator*(Matrix3D& other);

    /**
     * Overloading "+" operator between two matrixs, adding between them.
     * @param other, Matrix3D& object.
     * @return Matrix3D object which is the matrix after the "+" operator.
     */
    Matrix3D operator+(const Matrix3D& other);

    /**
     * Overloading "-" operator between two matrixs, subtracting them.
     * @param other, Matrix3D& object.
     * @return Matrix3D object which is the matrix after the "-" operator.
     */
    Matrix3D operator-(const Matrix3D& other);

    /**
     * Overloading "*=" operator between a matrix and a number, multiplying them.
     * @param other, double& number.
     * @return Matrix3D object which is the matrix after the "*=" operator.
     */
    Matrix3D operator*=(const double& other);

    /**
     * Overloading "/=" operator between a matrix and a number, dividing them.
     * @param other, double& number.
     * @return Matrix3D& object which is the matrix after the "/=" operator.
     */
    Matrix3D operator/=(const double& other);

    /**
     * Overloading "*" operator between a matrix and a vector, multiplying them.
     * @param other, Vector3D& object.
     * @return Vector3D object which is the vector after the "*" operator.
     */
    Vector3D operator*( Vector3D& other);

    /**
     * Overloading "[]" of a matrix.
     * @param index, an int number which is the index in the array of the vector.
     * @return Vector3D&&, which has the appropriate vector.
     */
    Vector3D& operator[](const int &index);

    /**
     * Overloading "=" between two matrixs.
     * @param other, Matrix3D& object.
     * @return Matrix3D& which is a copy of the vector received.
     */
    Matrix3D& operator=(const Matrix3D& other);

    /**
     * Overloading "<<" of a matrix.
     * @param out, std::ostream& object.
     * @param matrix, Matrix3D& object.
     * @return std::ostream& used in the output.
     */
    friend std::ostream& operator<<(std::ostream& out, const Matrix3D& matrix);

    /**
     * Overloading ">>" of a matrix.
     * @param input
     * @param matrix
     * @return std::istream& input, used in the input.
     */
    friend std::istream& operator>>(std::istream& input, Matrix3D& matrix);

    /**
     * Function to return a vector of the appropriate row requested.
     * @param num, short number.
     * @return Vector3D object which is the row requested.
     */
    Vector3D row(short num);

    /**
     * Function to return a vector of the appropriate column requested.
     * @param index, short number.
     * @return Vector3D object which is the column requested.
     */
    Vector3D column(short index);

    /**
     * Function to return the sum of the diagnoal numbers in the matrix.
     * @return double, which is the requested sum.
     */
    double trace();

    /**
     * Function to calculate the determinant of the matrix.
     * @return double, which is the determinant of the matrix calculated.
     */
    double determinant();

};

#endif //EX1_MATRIX3D_H