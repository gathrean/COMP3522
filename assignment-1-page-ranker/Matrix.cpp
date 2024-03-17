//
// Created by Gathrean Dela Cruz on 2023-10-07.
//

//Name: Gathrean Dela Cruz
//Student# : A01167248

#include "Matrix.hpp"

/**
 * @brief Matrix Default Constructor (1 x 1).
 *
 * @param none
 * @post Initializes a square 1x1 matrix that contains a 0.0.
 * @return none
 */
Matrix::Matrix() {
    rows = 1;
    cols = 1;

    // Allocating memory for the Matrix
    data = new double* [rows];

    // Allocating memory for the first (and only) row
    data[0] = new double[cols];

    // Setting the first element of first (and only) row to 0.0
    data[0][0] = 0.0;
}

/**
 * @brief Matrix Constructor (n x n).
 *
 * @param n is a positive integer
 * @post n is unchanged.
 * @return a square n x n matrix that contains 0.0s.
 */
Matrix::Matrix(int n) {
    // Throw an exception if the integer pass is 0 or negative.
    if (n <= 0) {
        throw std::invalid_argument("The integer n shouldn't be a 0 or a negative integer.");
    }

    rows = n;
    cols = n;

    // Allocate memory for the matrix
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];

        // Initializes all elements in the n x n matrix to 0.0s.
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0.0;
        }
    }
}

/**
 * @brief Matrix Constructor (r x c).
 *
 * @param r is a positive integer (represents rows)
 * @param c is a positive integer (represents columns)
 * @post r and c are unchanged.
 * @return A matrix of size r x c.
 */
Matrix::Matrix(int r, int c) {
    // Throw an exception if the integer pass is 0 or negative.
    if (r <= 0 || c <= 0) {
        throw std::invalid_argument("The integer r and c shouldn't be a 0 or a negative integer.");
    }

    rows = r;
    cols = c;

    // Allocating memory for my "array of row pointers" to 'double'
    data = new double* [rows];

    // Initializes all elements in the r x c matrix to 0.0s.
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0.0;
        }
    }
}

/**
 * @brief Matrix Constructor (Perfect Square Vectors).
 *
 * @param &inputArray is a one dimensional array/vector of double.
 * @post inputArray populates the created matrix with its values.
 * @return A perfect vector matrix
 */
Matrix::Matrix(std::vector<double>& inputArray) {
    // Check if the input vector is a perfect square.
    int vectorSize = inputArray.size();
    int matrixSize = sqrt(vectorSize);

    if (matrixSize * matrixSize != vectorSize) {
        throw std::invalid_argument("The input vector must be a perfect square.");
    }

    rows = matrixSize;
    cols = matrixSize;

    // Allocating memory for the matrix
    data = new double* [rows];

    // Populate the matrix with values from vector
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            // Mapping each element in the 2D matrix
            // to a unique position in the 1D vector
            data[i][j] = inputArray[i * cols + j];
        }
    }
    /*
     * Visual representation of the mapping in the inner for-loop:
     *
     * e.g.
     * Matrix (2x2):
     * data[0][0]       data[0][1]
     * data[1][0]       data[1][1]
     *
     * Input Vector (Flattened):
     * inputArray[0] inputArray[1] inputArray[2] inputArray[3]
     */
}

/**
 * @brief Matrix Copy Constructor.
 *
 * @param otherMatrix is a valid Matrix object.
 * @post Creates a new Matrix object that is a copy of otherMatrix
 * @return A new Matrix object that is a copy of otherMatrix
 */
Matrix::Matrix(const Matrix& otherMatrix) {
    // Copy the size from the otherMatrix
    rows = otherMatrix.rows;
    cols = otherMatrix.cols;

    // Allocate memory for the matrix
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];

        // Copies the values from the otherMatrix
        for (int j = 0; j < cols; ++j) {
            data[i][j] = otherMatrix.data[i][j];
        }
    }
}

/**
 * @brief Matrix Clear function.
 *
 * @param none
 * @post Sets the values in the matrix to 0.0s.
 * @return none
 */
void Matrix::clear() {
    // Deallocate existing memory if it was allocated
    // Makes sure that I'm not creating a new matrix on top of the existing one
    // to avoid a memory leak.
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Allocate memory for the matrix
    data = new double* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0.0;
        }
    }
}

/**
 * @brief Matrix Destructor.
 *
 * @param none
 * @post Automatically called when a Matrix object goes out of scope.
 * @return none
 */
Matrix::~Matrix() {
    // Deallocate existing memory if it was allocated
    if (data != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Then set pointers to "nullptr" after de-allocation
    // Helps prevent accidental use of dangling pointers
    // and catch bugs.
    data = nullptr;
}

/**
 * @brief Overloaded insertion operator for Matrix objects.
 *
 * @param os A reference to the ostream where the Matrix will be written.
 * @param obj The custom Matrix object to be written to the ostream.
 * @return A reference to the ostream after the Matrix has been written.
 */
std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            // writing the Matrix content into the output stream
            os << obj.data[i][j] << " ";
        }
        // Reached the end of the row
        // Move to the next row in the os.
        os << std::endl;
    }
    return os;
}

/**
 * @brief Overloaded equality operators.
 *
 * Checks if the matrices are the same size and
 * contains the same values in the same locations.
 *
 * @param lhs
 * @param rhs
 * @return:
 */
bool operator==(const Matrix& lhs, const Matrix& rhs) {
    // Check if the two Matrices are the same size
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
        return false;
    }

    // Check if absolute values in the positions are within the TOLERANCE
    for (int i = 0; i < lhs.rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            if (std::abs(lhs.data[i][j] - rhs.data[i][j]) > TOLERANCE) {
                return false;
            }
        }
    }

    // Both Matrices have same size, and same values in the same locations.
    return true;
}

/**
 * @brief Overloaded inequality operators.
 *
 * Checks if the Matrices are not equal.
 *
 * @param lhs A Matrix object.
 * @param rhs A Matrix object.
 * @return "True" if the Matrices are not the same.
 */
bool operator!=(const Matrix& lhs, const Matrix& rhs) {
    return !(lhs == rhs);
}

/**
 * @brief Matrix Increment Operator.
 *
 * Increments each value in the Matrix by 1.0
 *
 * @return Updated Matrix after incrementing each element by 1.0.
 */
Matrix& Matrix::operator++() {
    // Increment each value in the Matrix by 1.0
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += 1.0;
        }
    }
    return *this; // Return the updated Matrix object
}

/**
 * @brief Matrix Increment Operator.
 *
 * Increments each value in the Matrix by 1.0
 *
 * @return Copy of the original Matrix before the increment operation.
 */
Matrix Matrix::operator++(int) {
    // Temp copy of the current Matrix
    Matrix temp(*this);

    operator++(); // Internal increment

    return temp;
}

/**
 * @brief Matrix Decrement Operator.
 *
 * Decrements each value in the Matrix by 1.0.
 *
 * @return Updated Matrix after decrementing each element by 1.0.
 */
Matrix& Matrix::operator--() {
    // Decrement each value in the Matrix by 1.0
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] -= 1.0;
        }
    }
    return *this; // Return the updated Matrix object
}

/**
 * @brief Matrix Decrement Operator.
 *
 * Decrements each value in the Matrix by 1.0.
 *
 * @return Copy of the original Matrix before decrementing operation.
 */
Matrix Matrix::operator--(int) {
    // Temp copy of the current Matrix
    Matrix temp(*this);

    operator--(); // Internal decrement

    return temp;
}

/**
 * @brief Helper swap function to swap the contents of two Matrix objects.
 *
 * This function swaps the size and data pointers between two Matrix objects,
 * while implementing the copy-and-swap algorithm covered in class.
 *
 * @param first A reference to the first Matrix object
 * @param second A reference to the second Matrix object
 */
void matrixSwap(Matrix& first, Matrix& second) {
    using std::swap;

    // Swapping size and data pointers between matrices,
    // which is essentially exchanging their entire contents.
    swap(first.rows, second.rows);
    swap(first.cols, second.cols);
    swap(first.data, second.data);
}

/**
 * @brief Assignment operator overload for Matrix objects.
 *
 * Assigns the content of another Matrix object to this Matrix object,
 * implementing the copy-and-swap algorithm for safe and efficient assignment.
 *
 * @param other A constant reference to the source Matrix object
 * @return A reference to this Matrix object after the assignment.
 */
Matrix& Matrix::operator=(const Matrix& other) {
    // 1. Use copy constructor to create a local copy of the original object
    Matrix temp(other);

    // 2. Acquire the copied data with a swap function, swapping old data with new
    matrixSwap(*this, temp);

    // 3. Temporary local copy is destroyed, taking old data and leaving you with
    // new data in the destination. Done!
    return *this;
}

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
Matrix& Matrix::operator+=(const Matrix& rhs) {
    // Check if the matrices are the same size
    if (rows != rhs.rows || cols != rhs.cols) {
        throw std::invalid_argument("Matrices must be the same size for addition.");
    }

    // Perform Matrix addition (via elements)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += rhs.data[i][j];
        }
    }

    // Return the modified matrix
    return *this;
}

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
Matrix operator+(Matrix lhs, const Matrix& rhs) {
    // Check if the matrices are the same size
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
        throw std::invalid_argument("Matrices must be the same size for subtraction.");
    }

    lhs += rhs; // uses the overloaded +=
    return lhs;
}

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
Matrix& Matrix::operator-=(const Matrix& rhs) {
    // Check if the matrices are the same size
    if (rows != rhs.rows || cols != rhs.cols) {
        throw std::invalid_argument("Matrices must be the same size for subtraction.");
    }

    // Perform Matrix addition (via elements)
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] -= rhs.data[i][j];
        }
    }

    // Return the modified matrix
    return *this;
}

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
Matrix operator-(Matrix lhs, const Matrix& rhs) {
    // Check if the matrices are the same size
    if (lhs.rows != rhs.rows || lhs.cols != rhs.cols) {
        throw std::invalid_argument("Matrices must be the same size for subtraction.");
    }

    lhs -= rhs;
    return lhs;
}

/**
 * @brief Overload Multiplication Assignment Operator.
 *
 * @param rhs A constant reference to the right-hand side Matrix object.
 * @return A reference to the modified Matrix object after multiplication.
 */
Matrix& Matrix::operator*=(const Matrix& rhs) {
    // The number of columns in the first Matrix
    // has to equal the number of rows in the second Matrix.
    if (cols != rhs.rows) {
        throw std::invalid_argument("Invalid matrix multiplication: "
                                    "Number of columns in the first matrix "
                                    "must be equal to the number of rows "
                                    "in the second matrix.");
    }

    // Result Matrix with dimensions (lhs.rows x rhs.cols)
    Matrix result(rows, rhs.cols);

    // Matrix multiplication
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            double sum = 0.0;

            // Iterates through the "common dimension" (lhs.cols or rhs.rows)
            // to calculate the sum of products
            for (int k = 0; k < cols; ++k) {
                sum += data[i][k] * rhs.data[k][j];
            }

            // Sets the calculated value into the Result Matrix
            // at position (i, j)
            result.data[i][j] = sum;
        }
    }

    // Returns the modified Matrix.
    return *this;
}

/**
 * @brief Overload Multiplication Operator.
 *
 * @param lhs A copy of the left-hand side Matrix object.
 * @param rhs A constant reference to the right-hand side Matrix object.
 * @return A new Matrix object that represents the result of the multiplication operation.
 */
Matrix operator*(Matrix lhs, const Matrix& rhs) {
    // The number of columns in the first Matrix
    // has to equal the number of rows in the second Matrix.
    if (lhs.cols != rhs.rows) {
        throw std::invalid_argument("Invalid matrix multiplication: "
                                    "Number of columns in the first matrix "
                                    "must be equal to the number of rows "
                                    "in the second matrix.");
    }

    // Result Matrix with dimensions (lhs.rows x rhs.cols)
    Matrix result(lhs.rows, rhs.cols);

    // Matrix multiplication
    for (int i = 0; i < lhs.rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            double sum = 0.0;

            // Iterates through the "common dimension" (lhs.cols or rhs.rows)
            // to calculate the sum of products
            for (int k = 0; k < lhs.cols; ++k) {
                sum += lhs.data[i][k] * rhs.data[k][j];
            }

            // Sets the calculated value into the Result Matrix
            // at position (i, j)
            result.data[i][j] = sum;
        }
    }

    // Return the resulting Matrix
    return result;
}

/**
 * @brief Gets the number of rows in the Matrix.
 *
 * @return The number of rows in the Matrix.
 */
int Matrix::getRows() const {
    return rows;
}

/**
 * @brief Gets the number of columns in the Matrix.
 *
 * @return
 */
int Matrix::getCols() const {
    return cols;
}

/**
 * @brief Matrix Mutator that sets a new value from specified location.
 *
 * @param r is a positive integer
 * @param c is a positive integer
 * @param newValue is a positive double
 * @post Updates the value at the specified row and column in the Matrix
 * @return none
 */
void Matrix::setValue(int r, int c, double newValue) {
    // Throw an exception if the integer pass is negative.
    if (r < 0 || c < 0) {
        throw std::invalid_argument("The integer r and c shouldn't be a 0 or a negative integer.");
    }

    // Finally, it sets the new value to the specified location
    data[r][c] = newValue;
}

/**
 * @brief Matrix Accessor that gets a value from specified location.
 *
 * @param r is a positive integer.
 * @param c is a positive integer.
 * @post Gets the value from the given r x c location.
 * @return The value at specified row and column from specified row and column in the Matrix.
 */
double Matrix::getValue(int r, int c) const {
    // Throw an exception if the integer pass is negative.
    if (r < 0 || c < 0) {
        throw std::invalid_argument("The integer r and c shouldn't be a 0 or a negative integer.");
    }

    // Finally, it gets the value from the specified location.
    return data[r][c];
}