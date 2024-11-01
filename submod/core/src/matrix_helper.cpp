#include "matrix_helper.hpp"

#include <rapidcsv.h>

#include <algorithm>
#include <cstdint>
#include <string>

#include "matrix.hpp"

namespace gds::core {

Matrix MatrixHelper::load_matrix_from_CSV(const std::string& file_name) {
  rapidcsv::Document doc(file_name, rapidcsv::LabelParams(-1, -1),
                         rapidcsv::SeparatorParams(' ', 0));
  auto rows = doc.GetRowCount();
  auto row0 = doc.GetRow<std::string>(0);
  row0.erase(std::remove(row0.begin(), row0.end(), ""), row0.end());
  auto cols = row0.size();
  Matrix matrix(rows, cols);
  for (uint32_t i = 0; i < rows; i++) {
    auto tr = doc.GetRow<std::string>(i);
    tr.erase(std::remove(tr.begin(), tr.end(), ""), tr.end());
    for (int j = 0; j < cols; j++) {
      matrix(i, j) = std::stod(tr[j]);
    }
  }
  return matrix;
}

}  // namespace gds::core