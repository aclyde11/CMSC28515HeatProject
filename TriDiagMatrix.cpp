//
// Created by Austin Clyde on 4/1/18.
//

#include "TriDiagMatrix.h"
#include <iostream>

NumVec superDiag(TriDiagMatrix A) {
  return A.diagonal(1);
}
NumVec diag(TriDiagMatrix A) {
  return A.diagonal(0);
}
NumVec subDiag(TriDiagMatrix A) {
  return A.diagonal(-1);
}

TriDiagMatrix zeros(int n, double m) {
  return Eigen::MatrixXd::Constant(n, n, m);
}

NumVec solveTriDiagMatrix(TriDiagMatrix A, NumVec d) {
  NumVec x(d);
  NumVec c(superDiag(A));
  NumVec b = diag(A);
  NumVec a = subDiag(A);
  int n = (int) A.rows();

  //Forward Sweep
  c(0) = c(0) / b(0);
  for (int i = 1; i < n-1; i++) {
    c(i) = c(i) / (b(i) - a(i-1) * c(i-1));
  }

  d(0) = d(0) / b(0);
  for (int i = 1; i < n; i++) {
    d(i) = (d(i) - a(i-1) * d(i-1)) / (b(i) - a(i-1) * c(i-1));
  }

  //Back Substitution
  x(n-1) = d(n-1);
  for(int i = n - 2; i >= 0; i--) {
    x(i) = d(i) - c(i) * x(i+1);
  }
  b(3) = 7;
  A(2,3) = 7;
  return x;
}

void testTriDiagSolver() {
  TriDiagMatrix A = zeros(5, 0.0);
  NumVec  y(5);

  //Set SuperDiag and SubDiag
  for(int i = 0; i < 4; i++) {
    A.diagonal(1)(i) = 1 + 0.2 * i + 0.01 *i * i;
    A.diagonal(-1)(i) = 1 - 0.3*i + 0.05 * i * i;
  }

  //Set Diag and y vector
  for(int i = 0; i < 5; i++) {
    A.diagonal(0)(i) = 4 + 0.1 * i + 0.01 * i *i;
    y(i) = i+1;
  }

  NumVec x = solveTriDiagMatrix(A, y);
  std::cout << "Solved for x in Ax=y with\nA =\n" << A.format(CleanFmt) << std::endl;
  std::cout << "y=\n" << y.format(CleanFmt) << std::endl;
  std::cout << "Soln x =\n" << x.format(CleanFmt) << std::endl;
  std::cout << "A*x = \n" << (A*x).format(CleanFmt) << std::endl;
}

