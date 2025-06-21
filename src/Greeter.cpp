#include "Greeter.hpp"

Greeter::Greeter(const std::string &thingToGreet)
    : greetTarget(thingToGreet) {
}

std::string Greeter::greet() {
  return "Hello, " + greetTarget + ", it is nice to greet you!";
}