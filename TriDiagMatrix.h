//
// Created by Austin Clyde on 4/1/18.
//

#ifndef CMSC28515HEATPROJECT_TRIDIAGMATRIX_H
#define CMSC28515HEATPROJECT_TRIDIAGMATRIX_H

#include <Eigen/Dense>

typedef Eigen::MatrixXd TriDiagMatrix;
typedef Eigen::VectorXd NumVec;

static const Eigen::IOFormat &CleanFmt(Eigen::FullPrecision, 0, ", ", "\n", "[", "]");

TriDiagMatrix zeros(int n, double m);

NumVec solveTriDiagMatrix(TriDiagMatrix A, NumVec d);
NumVec superDiag(TriDiagMatrix A);
NumVec diag(TriDiagMatrix A);
NumVec subDiag(TriDiagMatrix A);
void testTriDiagSolver();

#endif //CMSC28515HEATPROJECT_TRIDIAGMATRIX_H
