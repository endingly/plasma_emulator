#include "partical.hpp"

gds::chempars::partical::partical(std::string name) {
  this->name   = name;
  this->type   = particle_type::atom;
  this->charge = 0;
  if (name == "e") {
    this->type   = particle_type::electron;
    this->charge = -1;
  }
  if (auto index_0 = name.find('^') != std::string::npos) {
    if (auto index = name.find('+') != std::string::npos) {
      this->type = particle_type::ion;
      if (index - index_0 == 1)
        this->charge = 1;
      else
        this->charge = atoi(name.substr(index_0, index - index_0).c_str());
    } else if (name.find('*') != std::string::npos) {
      this->type = particle_type::excite;
    }
  }
}