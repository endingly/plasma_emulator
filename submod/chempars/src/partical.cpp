#include "chempars/partical.hpp"

gds::chempars::Partical::Partical(std::string name) {
  this->name   = name;
  this->type   = ParticleType::atom;
  this->charge = 0;
  if (name == "e") {
    this->type   = ParticleType::electron;
    this->charge = -1;
  }
  if (auto index_0 = name.find('^') != std::string::npos) {
    if (auto index = name.find('+') != std::string::npos) {
      this->type = ParticleType::ion;
      if (index - index_0 == 1)
        this->charge = 1;
      else
        this->charge = atoi(name.substr(index_0, index - index_0).c_str());
    } else if (name.find('*') != std::string::npos) {
      this->type = ParticleType::excite;
    }
  }
}