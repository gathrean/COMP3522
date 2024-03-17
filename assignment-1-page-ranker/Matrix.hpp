
//
// Created by Gathrean Dela Cruz on 2023-10-07.
//

//Name: Gathrean Dela Cruz
//Student# : A01167248

#pragma once

#include <stdexcept>
#include <vector>
#include <cmath>
#include <iostream>

/**
 * @brief The allowed different between double values.
 *
 * This is used in the overloaded equality operators.
 */
const double TOLERANCE = 1e-9;

class Matrix {
private:

    /**
     * @brief The Matrix stores doubles.
     *
     * I'm using a pointer-to-a-pointer double so I can
     * allocate memory for a 2D array dynamically.
     */
    double** data;

    /**
     * @brief The amount of the Matrix object's rows.
     */
    int rows;

    /**
     * @brief The amount of the Matrix object's columns.
     */
    int cols;

public:

    /**
     * @brief Matrix Default Constructor (1 x 1).
     *
     * @param none
     * @post Initializes a square 1x1 matrix that contains a 0.0.
     * @return none
     */
    Matrix();

    /**
     * @brief Matrix Constructor (n x n).
     *
     * @param n is a positive integer
     * @post n is unchanged.
     * @return a square n x n matrix that contains 0.0s.
     */
    Matrix(int n);

    /**
     * @brief Matrix Constructor (r x c).
     *
     * @param r is a positive integer (represents rows)
     * @param c is a positive integer (represents columns)
     * @post r and c are unchanged.
     * @return A matrix of size r x c.
     */
    Matrix(int r, int c);

    /**
     * @brief Matrix Constructor (Perfect Square Vectors).
     *
     * @param &inputArray is a one dimensional array/vector of double.
     * @post inputArray populates the created matrix with its values.
     * @return A perfect vector matrix
     */
    Matrix(std::vector<double>& inputArray);

    /**
     * @brief Matrix Copy Constructor.
     *
     * @param otherMatrix is a valid Matrix object.
     * @post Creates a new Matrix object that is a copy of otherMatrix
     * @return A new Matrix object that is a copy of otherMatrix
     */
    Matrix(const Matrix& otherMatrix);

    /**
     * @brief Matrix Clear function.
     *
     * @param none
     * @post Sets the values in the matrix to 0.0s.
     * @return none
     */
    void clear();

    /**
     * @brief Matrix Destructor.
     *
     * @param none
     * @post Automatically called when a Matrix object goes out of scope.
     * @return none
     */
    ~Matrix();

    /**
     * @brief Overloaded insertion operator for Matrix objects.
     *
     * @param os A reference to the ostream where the Matrix will be written.
     * @param obj The custom Matrix object to be written to the ostream.
     * @return A reference to the ostream after the Matrix has been written.
     */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& obj);

    /**
     * @brief Overloaded equality operators.
     *
     * Checks if the matrices are the same size and
     * contains the same values in the same locations.
     *
     * @param lhs A reference to the first Matrix object.
     * @param rhs A reference to the second Matrix object.
     * @return: "True" if the Matrices are the same.
     */
    friend bool operator==(const Matrix& lhs, const Matrix& rhs);

    /**
     * @brief Overloaded inequality operators.
     *
     * Checks if the Matrices are not equal.
     *
     * @param lhs A reference to the first Matrix object.
     * @param rhs A reference to the second Matrix object.
     * @return "True" if the Matrices are not the same.
     */
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);

    /**
     * @brief Matrix Increment Operator.
     *
     * Increments each value in the Matrix by 1.0
     *
     * @return Updated Matrix after incrementing each element by 1.0.
     */
    Matrix& operator++();

    /**
     * @brief Matrix Increment Operator.
     *
     * Increments each value in the Matrix by 1.0
     *
     * @return Copy of the original Matrix before the increment operation.
     */
    Matrix operator++(int);

    /**
     * @brief Matrix Decrement Operator.
     *
     * Decrements each value in the Matrix by 1.0.
     *
     * @return Updated Matrix after decrementing each element by 1.0.
     */
    Matrix& operator--();

    /**
     * @brief Matrix Decrement Operator.
     *
     * Decrements each value in the Matrix by 1.0.
     *
     * @return Copy of the original Matrix before decrementing operation.
     */
    Matrix operator--(int);

    /**
     * @brief Helper swap function to swap the contents of two Matrix objects.
     *
     * This function swaps the size and data pointers between two Matrix objects,
     * while implementing the copy-and-swap algorithm covered in class.
     *
     * @param first A reference to the first Matrix object
     * @param second A reference to the second Matrix object
     */
    friend void matrixSwap(Matrix& first, Matrix& second);

    /**
     * @brief Assignment operator overload for Matrix objects.
     *
     * Assigns the content of another Matrix object to this Matrix object,
     * implementing the copy-and-swap algorithm for safe and efficient assignment.
     *
     * @param other A constant reference to the source Matrix object
     * @return A reference to this Matrix object after the assignment.
     */
    Matrix& operator=(const Matrix& other);

    /**
     * @brief Overload Addition Assignment Operator.
     *
     * This operator adds the element of the right-hand side matrix to the
     * corresponding elements of this matrix.
     *
     * Both matrices must be of the same size
     *
     * @param rhs A constant reference to the right-hand side Matrix object.
     * @return A reference to the modified Matrix object after addition.
     */
    Matrix& operator+=(const Matrix& rhs);

    /**
     * @brief Overload Addition Operator.
     *
     * This operator performs element-wise addition of two matrices
     * and returns a new Matrix.
     *
     * Both matrices must be of the same size.
     *
     * @param lhs A copy of the left-hand side Matrix object.
     * @param rhs A constant reference to the right-hand side Matrix object.
     * @return A new Matrix object representing the result of the addition operation.
     */
    friend Matrix operator+(Matrix lhs, const Matrix& rhs);

    /**
     * @brief Overload Subtraction Assignment Operator.
     *
     * This operator subtracts the element of the right-hand side matrix to the
     * corresponding elements of this matrix.
     *
     * Both matrices must be of the same size
     *
     * @param rhs A constant reference to the right-hand side Matrix object.
     * @return A reference to the modified Matrix object after subtraction.
     */
    Matrix& operator-=(const Matrix& rhs);

    /**
     * @brief Overload Subtraction Operator.
     *
     * This operator performs element-wise subtraction of two matrices
     * and returns a new Matrix.
     *
     * Both matrices must be of the same size.
     *
     * @param lhs A copy of the left-hand side Matrix object.
     * @param rhs A constant reference to the right-hand side Matrix object.
     * @return A new Matrix object representing the result of the subtraction operation.
     */
    friend Matrix operator-(Matrix lhs, const Matrix& rhs);

    /**
     * @brief Overload Multiplication Assignment Operator.
     *
     * @param rhs A constant reference to the right-hand side Matrix object.
     * @return A reference to the modified Matrix object after multiplication.
     */
    Matrix& operator*=(const Matrix& rhs);

    /**
     * @brief Overload Multiplication Operator.
     *
     * @param lhs A copy of the left-hand side Matrix object.
     * @param rhs A constant reference to the right-hand side Matrix object.
     * @return A new Matrix object that represents the result of the multiplication operation.
     */
    friend Matrix operator*(Matrix lhs, const Matrix& rhs);

    /**
     * @brief Gets the number of rows in the Matrix.
     *
     * @return The number of rows in the Matrix.
     */
    int getRows() const;

    /**
     * @brief Gets the number of columns in the Matrix.
     *
     * @return
     */
    int getCols() const;


    /**
     * @brief Matrix Mutator that sets a new value from specified location.
     *
     * @param r is a positive integer
     * @param c is a positive integer
     * @param newValue is a positive double
     * @post Updates the value at the specified row and column in the Matrix
     * @return none
     */
    void setValue(int r, int c, double newValue);

    /**
     * @brief Matrix Accessor that gets a value from specified location.
     *
     * @param r is a positive integer.
     * @param c is a positive integer.
     * @post Gets the value from the given r x c location.
     * @return The value at specified row and column from specified row and column in the Matrix.
     */
    double getValue(int r, int c) const;
};