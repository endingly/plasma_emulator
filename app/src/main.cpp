#include <Eigen/Dense>
#include <fstream>

using namespace std;
using namespace Eigen;

int main() {
  // 线性方程求解 Ax =B;
  Matrix4d A;
  A << 2, -1, -1, 1, 
       1, 1, -2, 1, 
       4, -6, 2, -2, 
       3, 6, -9, 7;
  fstream f;
  f.open("A.csv", ios::out);
  f << A;
  f.close();
}