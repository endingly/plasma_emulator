#include "equation.hpp"

#include <iostream>

int gds::chempars::Equation::id_counter = 0;

gds::chempars::Equation::Equation(const std::string& str) {
  // parse the equation string
  // like: e + Ar^+ -> Ar^*
  // split the string by ","
  auto comma_index0 = str.find_first_of(",");
  auto equation_str = str.substr(0, comma_index0);
  auto type_str = str.substr(comma_index0 + 1, str.size() - comma_index0 - 1);

  auto index = equation_str.find("->");
  if (index == std::string::npos) {
    throw std::invalid_argument("Invalid equation: " + equation_str);
  }
  auto reactants_str = equation_str.substr(0, index);
  auto products_str =
      equation_str.substr(index + 2, equation_str.size() - index - 2);

  auto reactants_vec = parse_equation_str(reactants_str);
  auto products_vec  = parse_equation_str(products_str);

  // generate the equation object
  for (auto&& item : reactants_vec) {
    reactants.push_back(item);
  }
  for (auto&& item : products_vec) {
    products.push_back(item);
  }

  // parse the type string
  this->type = parse_equation_type(type_str);

  // generate the equation id
  this->eq_id = id_counter++;
}

std::vector<std::string> gds::chempars::Equation::parse_equation_str(
    const std::string& equation_str) {
  auto result_vec = std::vector<std::string>();
  int  index      = 0;
  // parse equation string
  size_t target = equation_str.find("+", index);
  while (target != std::string::npos) {
    if (equation_str[target - 1] == '^') {
      result_vec.push_back(equation_str.substr(index, target - index + 1));
      index = target + 2;
    } else {
      result_vec.push_back(equation_str.substr(index, target - index - 1));
      index = target + 1;
    }
    target = equation_str.find("+", index);
  }
  if (index < equation_str.size()) {
    result_vec.push_back(
        equation_str.substr(index, equation_str.size() - index));
  }

  return result_vec;
}

gds::chempars::EquationType gds::chempars::Equation::parse_equation_type(
    const std::string& type_str) {
  if (type_str.find("ionization") != std::string::npos)
    return EquationType::ionization;
  else if (type_str.find("elastic") != std::string::npos)
    return EquationType::elastic;
  else if (type_str.find("excite") != std::string::npos)
    return EquationType::excite;
  else if (type_str.find("compound") != std::string::npos)
    return EquationType::compound;
  else if (type_str.find("fadding_excitation") != std::string::npos)
    return EquationType::fadding_excitation;
  else {
    std::cerr << "Parsing error, invalid equation type: " << type_str
              << std::endl;
    exit(1);
  }
}