//Name: Gathrean Dela Cruz
//Student# : A01167248

#include "Matrix.hpp"
#include "MatrixBuilder.hpp"
#include "PageRanker.hpp"

#define DEFAULT_FILE "../connectivity.txt"

int main() {
    MatrixBuilder builder;

    Matrix connectivityMatrix = builder.buildConnectivity(DEFAULT_FILE);

    Matrix stochasticMatrix = builder.buildStochastic(connectivityMatrix);

    Matrix teleportationMatrix = builder.buildTeleportation(connectivityMatrix);

    Matrix transitionMatrix = builder.buildTransition(connectivityMatrix, stochasticMatrix, teleportationMatrix);

    PageRanker(connectivityMatrix, transitionMatrix);

    return 0;
}