//
// Created by Gathrean Dela Cruz on 2023-10-09.
//

//Name: Gathrean Dela Cruz
//Student# : A01167248

#pragma once

#include <iomanip>
#include "Matrix.hpp"

using namespace std;

const double CONVERGENCE_THRESHOLD = 0.0001;
const double HUNDRED = 100;

/**
 * @brief The PageRanker class performs the Markov process
 * to calculate the page rank of a Matrix object.
 */
class PageRanker {
private:
    /**
     * @brief The convergence threshold.
     */
    double threshold;

    /**
     * @brief The difference between the new rank and the old rank.
     */
    double difference;

public:
    /**
     * @brief The PageRanker constructor performs the Markov process
     *
     * M = p * S + q * Q
     *
     * M = (0.85) * (Probability Matrix) + (0.15) * (Teleportation Matrix)
     *
     * @param matrixG A constant reference to a Matrix object
     * @param matrixM A constant reference to a Matrix object
     */
    PageRanker(const Matrix& matrixG, const Matrix& matrixM);

    /**
     * @brief Initializes a column matrix of size n x 1
     *
     * @param size The number of rows of the column matrix
     * @return
     */
    Matrix initializeRankMatrix(int size);

    /**
     * @brief Performs the Markov process until the rank stops changing (converges)
     *
     * @param matrixG A constant reference to a Connectivity Matrix object
     * @param matrixM A constant reference to a Transition Matrix object
     * @param rank A reference to a Rank Matrix object
     */
    void performMarkovProcess(const Matrix& matrixG, const Matrix& matrixM, Matrix& rank);

    /**
     * @brief Normalizes the rank matrix
     *
     * @param rank A reference to a Rank Matrix object
     */
    void normalizeRankMatrix(Matrix& rank);

    /**
     * @brief Prints the page rankings
     *
     * @param rank A constant reference to a Rank Matrix object
     */
    void printPageRankings(const Matrix& rank);
};