#include "partical.hpp"

gds::chempars::partical::partical(std::string name) {
  this->name   = name;
  this->type   = particle_type::atom;
  this->charge = 0;
  if (name == "e") {
    this->type   = particle_type::electron;
    this->charge = -1;
  }
  if (name.find('^')) {
    if (auto index = name.find('+')) {
      this->type   = particle_type::ion;
      this->charge = atoi(name.substr(index, name.size() - index).c_str());
    } else if (auto index = name.find('*')) {
      this->type = particle_type::excite;
    }
  }
}