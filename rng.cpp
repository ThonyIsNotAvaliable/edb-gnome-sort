#include <iostream>
#include <random>
#include <chrono>


int main() {
  std::random_device rd;

  std::mt19937 eng(rd());

  std::uniform_int_distribution<int> dist(1, 100);

  int n = 0;
  std::cin >> n;

  std::cout << n << '\n';
  for(int i = 0; i < n; ++i) {
    std::cout << dist(eng) << '\n';
  }

    
  return 0;
}
