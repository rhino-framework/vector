#include <vector.hpp>

RHino::vector<int> v1;

void setup() {
}

void loop() {
  v1.push_back(42);
  auto back = v1.back();
  v1.clear();
}
