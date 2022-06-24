#include "lib.hpp"

char const* hello_world() {
    return "hello world";
}

int one() {
    return 1;
}

void Pet::setName(const std::string &name_) {
    name = name_;
}

const std::string &Pet::getName() {
    return name;
}