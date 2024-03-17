//
// Created by Gathrean Dela Cruz on 2023-10-09.
//

//Name: Gathrean Dela Cruz
//Student# : A01167248

#include "PageRanker.hpp"

/**
 * @brief The PageRanker constructor performs the Markov process
 *
 * M = p * S + q * Q
 *
 * M = (0.85) * (Probability Matrix) + (0.15) * (Teleportation Matrix)
 *
 * @param connectivityMatrix A constant reference to a Matrix object
 * @param transitionMatrix A constant reference to a Matrix object
 */
PageRanker::PageRanker(const Matrix& connectivityMatrix, const Matrix& transitionMatrix) {

    threshold = CONVERGENCE_THRESHOLD;
    difference = CONVERGENCE_THRESHOLD + 1.0;

    // Create a column matrix of size n x 1
    Matrix rank = initializeRankMatrix(connectivityMatrix.getRows());

    // Perform the Markov process until the rank stops changing (converges)
    performMarkovProcess(connectivityMatrix, transitionMatrix, rank);

    // Divide each element in rank by the sum of the values
    normalizeRankMatrix(rank);

    // Output the converged rank matrix
    printPageRankings(rank);
}

/**
 * @brief Initializes a column matrix of size n x 1
 *
 * @param size The number of rows of the column matrix
 * @return
 */
Matrix PageRanker::initializeRankMatrix(int size) {
    Matrix rank(size, 1);
    for (int i = 0; i < size; ++i) {
        rank.setValue(i, 0, 1.0);
    }
    return rank;
}

/**
 * @brief Performs the Markov process until the rank stops changing (converges)
 *
 * @param matrixG A constant reference to a Connectivity Matrix object
 * @param matrixM A constant reference to a Transition Matrix object
 * @param rank A reference to a Rank Matrix object
 */
void PageRanker::performMarkovProcess(const Matrix& matrixG, const Matrix& matrixM, Matrix& rank) {
    // Perform the Markov process until the rank stops changing (converges)
    while (difference > threshold) {
        Matrix newRank = matrixM * rank;
        difference = 0.0;

        // Calculate the difference between the new rank and the old rank
        for (int i = 0; i < matrixG.getRows(); ++i) {
            difference += abs(newRank.getValue(i, 0) - rank.getValue(i, 0));
        }

        rank = newRank;
    }
}

/**
 * @brief Normalizes the rank matrix
 *
 * @param rank A reference to a Rank Matrix object
 */
void PageRanker::normalizeRankMatrix(Matrix& rank) {
    // Normalize the rank matrix
    double rankSum = 0.0;

    // Calculate the sum of the values in the rank matrix
    for (int i = 0; i < rank.getRows(); ++i) {
        rankSum += rank.getValue(i, 0);
    }

    // Divide each element in rank by the sum of the values
    for (int i = 0; i < rank.getRows(); ++i) {
        double normalizedValue = rank.getValue(i, 0) / rankSum;
        rank.setValue(i, 0, normalizedValue);
    }
}

/**
 * @brief Prints the page rankings
 *
 * @param rank A constant reference to a Rank Matrix object
 */
void PageRanker::printPageRankings(const Matrix& rank) {
    // Normalize and print the results with letters for page names
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Print the results with letters for page names
    for (int i = 0; i < rank.getRows(); ++i) {
        double normalizedValue = rank.getValue(i, 0);
        string pageName = "Page " + alphabet.substr(i, 1);
        cout << pageName << ": " << fixed << setprecision(2) << (normalizedValue * HUNDRED) << "%\n";
    }
}