#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class A {
  int a;
public:
  A() : a(5) {};

  void virtual dinner() {
    std::cout << a << std::endl;
  }
};

class B : public A {
public:
  B() : A() {};

  void dinner() {
    std::cout << "yam~" << std::endl;
  }
};

int main() {
  A a;
  B b;
  A* p_b = &b;
  p_b->dinner();
}