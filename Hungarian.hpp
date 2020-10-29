#pragma once

#include <vector>

namespace Hungarian {

typedef enum {
  MODE_MINIMIZE_COST,
  MODE_MAXIMIZE_UTIL,
} MODE;

typedef enum {
  NOT_ASSIGNED,
  ASSIGNED,
} ASSIGN;

using Matrix = std::vector<std::vector<int>>;

struct Result {
  // True if the algorithm completed and found a solution.
  bool success = false;
  // The solution
  Matrix assignment;
  // A normalized form of the input cost matrix.
  Matrix cost;
  // The costs incurred by the assignment
  int totalCost = 0;
};

/**
 * Runs the hungarian algorithm on the input cost matrix and returns a result
 * containing the normalized (square) cost matrix and a solution if one was
 * found.
 */
Result Solve(const Matrix &input, MODE mode);

void PrintMatrix(const Matrix &m);

};  // namespace Hungarian