#include "equation.hpp"

#include <iostream>

#include "utils.hpp"

int gds::chempars::Equation::id_counter = 0;

gds::chempars::Equation::Equation(const std::string& str) {
  // parse the equation string
  // like: e + Ar^+ -> Ar^*
  // split the string by ","
  auto comma_index0 = str.find_first_of(",");
  auto equation_str = str.substr(0, comma_index0);
  auto type_str     = str.substr(comma_index0 + 1, str.size() - comma_index0 - 1);

  auto result = gds::common::split(equation_str, "->");
  if (result.has_value() == false) {
    throw std::invalid_argument("Invalid equation: " + equation_str);
  }
  auto reactants_str = result.value()[0];
  auto products_str  = result.value()[1];

  auto reactants_vec = parse_equation_str(reactants_str);
  auto products_vec  = parse_equation_str(products_str);

  // generate the equation object
  for (auto&& item : reactants_vec) {
    Partical p(item);
    reactants.push_back(p);
  }
  for (auto&& item : products_vec) {
    Partical p(item);
    products.push_back(p);
  }

  // parse the type string
  this->type = parse_equation_type(type_str);

  // generate the equation id
  this->eq_id = id_counter++;
}

std::vector<std::string> gds::chempars::Equation::parse_equation_str(const std::string& equation_str) {
  // parse equation string
  if (equation_str.find_last_of("+") == std::string::npos) {
    return {equation_str};
  }
  auto result_vec = gds::common::split(equation_str, "+");
  if (result_vec.has_value() == false) {
    throw std::invalid_argument("Invalid equation: " + equation_str);
  }
  auto result = result_vec.value();
  for (auto&& item : result) {
    if (item.contains("^")) {
      item.append("+");
    }
  }
  return result;
}

gds::chempars::EquationType gds::chempars::Equation::parse_equation_type(const std::string& type_str) {
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
    std::cerr << "Parsing error, invalid equation type: " << type_str << std::endl;
    exit(1);
  }
}