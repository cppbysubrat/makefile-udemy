#include <future>
#include <iostream>

void f() {
  std::clog << "Update ... MT DEMO- ASYNC\n";
}

int main() {
 auto fut =
    std::async(std::launch::deferred, f);

 std::clog << "I am in MAIN()\n";
 fut.wait();
}
