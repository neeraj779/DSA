#include <iostream>
#include <cstdint>
using namespace std;

uint64_t factorial(uint64_t n) {
  uint64_t result = 1;
  for (uint64_t i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  cout << factorial(10);
  return 0;
}
