#include <iostream>
#include <Eigen/Dense>
#include "TriDiagMatrix.h"

int main() {
  NumVec x(5), y(5);
  x << 1,2,3,4,5;
  y << 5,4,3,2,1;

  std::cout << (x + 2*y).format(CleanFmt) << std::endl;

  TriDiagMatrix A(5,5);
  A << 1, 1, 0, 0, 0,
       1, 2, 2, 0, 0,
       0, 2, 3, 3, 0,
       0, 0, 3, 4, 4,
       0, 0, 0, 4, 5;

  std::cout << std::endl;
  std::cout << (A * x).format(CleanFmt) << std::endl;

  testTriDiagSolver();

  return 0;
}