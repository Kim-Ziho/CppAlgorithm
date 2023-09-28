#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

void plus_func(int& a, std::mutex& m) {
  for (int i = 0; i < 10000; i++) {
    std::lock_guard<std::mutex> lock(m);
    a++;
  }
}

int main() {
  int result = 0;
  std::mutex m;
  std::vector<std::thread> v;
  for (int i = 0; i < 4; i++) {
    v.push_back(std::thread(plus_func, std::ref(result), std::ref(m)));
  }
  for (int i = 0; i < 4; i++) {
    v[i].join();
  }
  std::cout << result << std::endl;
}