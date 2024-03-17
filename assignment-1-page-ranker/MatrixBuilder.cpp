//
// Created by Gathrean Dela Cruz on 2023-10-09.
//

//Name: Gathrean Dela Cruz
//Student# : A01167248

#include "MatrixBuilder.hpp"

using namespace std;

/**
 * @brief Reads the data from a text file and stores it in a 2D vector.
 *
 * @param fileName The name of the text file.
 * @return A 2D vector containing the Matrix data from the text file.
 */
vector<vector<int>> MatrixBuilder::readMatrixData(const string& fileName) {

    ifstream inputFile(fileName); // Open txt file.

    // Line by line, read the data from the text file.
    while (getline(inputFile, lineTxtFile)) {
        vector<int> rowTxtFile;
        istringstream iss(lineTxtFile);

        while (iss >> value) {
            rowTxtFile.push_back(value);
        }
        matrixFromFile.push_back(rowTxtFile);
    }

    inputFile.close();
    return matrixFromFile;
}

/**
 * @brief Counts the number of rows and columns of a Matrix object.
 *
 * @param matrix A constant reference to a Matrix object.
 */
void MatrixBuilder::countRowsAndCols(const vector<vector<int>>& fileMatrix) {
    rows = fileMatrix.size();
    cols = (rows > 0) ? fileMatrix[0].size() : 0;
}

/**
 * @brief Creates a Matrix object from reading a text file.
 *
 * @param fileName The name of the text file.
 * @return A Matrix object.
 */
Matrix MatrixBuilder::buildConnectivity(const string& fileName) {
    matrixFromFile = readMatrixData(fileName);
    countRowsAndCols(matrixFromFile);

    // Create and return the Matrix object using the data read from the file.
    Matrix connectivityMatrix(rows, cols);

    // Populate the connectivityMatrix with the data read from file.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            connectivityMatrix.setValue(i, j, matrixFromFile[i][j]);
        }
    }

    return connectivityMatrix;
}

/**
 * @brief Creates a Stochastic Matrix object.
 *
 * @param connectivityMatrix A constant reference to a Matrix object.
 * @return A Stochastic Matrix object.
 */
Matrix MatrixBuilder::buildStochastic(const Matrix& connectivityMatrix) {

    rows = connectivityMatrix.getRows();
    cols = connectivityMatrix.getCols();

    // Calculate the sum of 1s in each column
    vector<int> columnSums(cols, 0);
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            columnSums[j] += connectivityMatrix.getValue(i, j);
        }
    }

    // Create a new matrix S and populate it by dividing each cell by the column sum
    Matrix stochasticMatrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (columnSums[j] != 0) {
                // Divide the cell value by the sum of 1s in the column
                stochasticMatrix.setValue(i, j, connectivityMatrix.getValue(i, j) / columnSums[j]);
            } else {
                // Handle division by zero (if there are no 1s in the column)
                stochasticMatrix.setValue(i, j, 0.0);
            }
        }
    }

    // Iterate through columns of S and replace columns of zeros with 1/n
    for (int j = 0; j < cols; ++j) {
        double columnSum = 0;
        for (int i = 0; i < rows; ++i) {
            columnSum += stochasticMatrix.getValue(i, j);
        }

        // If the sum of elements in the column is zero, replace with 1/n
        if (columnSum == 0) {
            double replacementValue = 1.0 / rows;
            for (int i = 0; i < rows; ++i) {
                stochasticMatrix.setValue(i, j, replacementValue);
            }
        }
    }

    return stochasticMatrix;
}

/**
 * @brief Creates a Teleportation Matrix object.
 *
 * @param connectivityMatrix A constant reference to a Matrix object.
 * @return A Teleportation Matrix object.
 */
Matrix MatrixBuilder::buildTeleportation(const Matrix& connectivityMatrix) {

    rows = connectivityMatrix.getRows();
    cols = connectivityMatrix.getCols();

    // Calculate the value of 1/n
    double qValue = 1.0 / cols;

    // Create the matrix Q with all elements as 1/n
    Matrix teleportationMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            teleportationMatrix.setValue(i, j, qValue);
        }
    }

    return teleportationMatrix;
}

/**
 * @brief Creates a Transition Matrix object.
 *
 * @param connectivityMatrix A constant reference to a Matrix object.
 * @param stochasticMatrix A constant reference to a Matrix object.
 * @param teleportationMatrix A constant reference to a Matrix object.
 * @return A Transition Matrix object.
 */
Matrix MatrixBuilder::buildTransition(const Matrix& connectivityMatrix, const Matrix& stochasticMatrix, const Matrix& teleportationMatrix) {

    rows = connectivityMatrix.getRows();
    cols = connectivityMatrix.getCols();

    Matrix transitionMatrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            // Calculate M = p * S + q * Q
            double mValue = P * stochasticMatrix.getValue(i, j) + Q * teleportationMatrix.getValue(i, j);

            transitionMatrix.setValue(i, j, mValue);
        }
    }

    return transitionMatrix;
}