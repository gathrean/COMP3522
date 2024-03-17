//
// Created by Gathrean Dela Cruz on 2023-10-09.
//

//Name: Gathrean Dela Cruz
//Student# : A01167248

#pragma once

#include <fstream>
#include <sstream>
#include "Matrix.hpp"

using namespace std;

const double P = 0.85;
const double Q = 1.0 - P;

/**
 * @brief The MatrixBuilder class builds a Matrix object
 * from reading a text file.
 */
class MatrixBuilder {
private:
    /**
     * @brief The number of rows of a local Matrix object.
     */
    int rows;

    /**
     * @brief The number of columns of a local Matrix object.
     */
    int cols;

    /**
     * @brief A 2D vector of the Matrix data.
     */
    vector<vector<int>> matrixFromFile;

    /**
     * @brief Each line of the txt file.
     */
    string lineTxtFile;

    /**
     * @brief Each value in the txt file.
     */
    int value;

    /**
     * @brief Reads the data from a text file and stores it in a 2D vector.
     *
     * @param fileName The name of the text file.
     * @return A 2D vector containing the Matrix data from the text file.
     */
    vector<vector<int>> readMatrixData(const string& fileName);

    /**
     * @brief Counts the number of rows and columns of a Matrix object.
     *
     * @param matrix A constant reference to a Matrix object.
     */
    void countRowsAndCols(const vector<vector<int>>& matrix);

public:
    /**
     * @brief Creates a Matrix object from reading a text file.
     *
     * @param fileName The name of the text file.
     * @return A Matrix object.
     */
    Matrix buildConnectivity(const string& fileName);

    /**
     * @brief Creates a Stochastic Matrix object.
     *
     * @param connectivityMatrix A constant reference to a Matrix object.
     * @return A Stochastic Matrix object.
     */
    Matrix buildStochastic(const Matrix& connectivityMatrix);

    /**
     * @brief Creates a Teleportation Matrix object.
     *
     * @param connectivityMatrix A constant reference to a Matrix object.
     * @return A Teleportation Matrix object.
     */
    Matrix buildTeleportation(const Matrix& connectivityMatrix);

    /**
     * @brief Creates a Transition Matrix object.
     *
     * @param connectivityMatrix A constant reference to a Matrix object.
     * @param stochasticMatrix A constant reference to a Matrix object.
     * @param teleportationMatrix A constant reference to a Matrix object.
     * @return A Transition Matrix object.
     */
    Matrix buildTransition(const Matrix& connectivityMatrix, const Matrix& stochasticMatrix, const Matrix& teleportationMatrix);
};