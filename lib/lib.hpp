#ifndef MY_LIBRARY
#define MY_LIBRARY

#include <string>
#include "Eigen/Core"

char const* hello_world();
int one();
struct Pet {
    Pet(const std::string &name) : name(name) {}
    void setName(const std::string &);
    const std::string &getName();
    std::string name;
};

#endif