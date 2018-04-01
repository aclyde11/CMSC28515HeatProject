#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main() {
  std::cout << "Hello, World!" << std::endl;
  MatrixXd m(2,2);
  Eigen::Vector2d v;
  v << 1, 2;
  m(0,0) = 2;
  m(0,1) = 1;
  m(1,0) = 2;
  m(1,1) = 3;



  std::cout << "m = " << m << std::endl;
  std::cout << "v = " << v << std::endl;

  std::cout << "m*v = " << (m * v) << std::endl;
  return 0;
}