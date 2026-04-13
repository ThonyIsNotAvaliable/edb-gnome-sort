#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>

template<typename Itr, typename Cmp>
void gnomeSort(Itr first, Itr last, const Cmp &f);

bool biggerThan(int a, int b){
  return a > b;
}

bool lessThan(int a, int b){
  return a < b;
}


int main() {

  int n = 0;
  std::cin >> n;
  std::vector<int> list;

  for (int i = 0; i < n; ++i) {
    int val = 0;
    std::cin >> val;
    list.push_back(val);
  }
  
  auto start = std::chrono::steady_clock::now();

  gnomeSort(std::begin(list), std::end(list), lessThan);

  auto end = std::chrono::steady_clock::now();
  
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  
  for(auto e : list) {
    std::cout << e << '\n';
  }

  std::cout << "O algoritmo demorou [" << duration.count() << "] microsegundos\n";
  
  return 0;
}



template<typename Itr, typename Cmp>
void gnomeSort(Itr first, Itr last, const Cmp &f) {
  Itr gnome = first;

  while (gnome != last) {
    if(f(*gnome, *(gnome + 1))) {
      std::iter_swap(gnome, gnome + 1);
      if (gnome != first) gnome -= 2; //Gnomo anda para trás
    }
    ++gnome; //Gnomo anda para frente
  } 

  
}
