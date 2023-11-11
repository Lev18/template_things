#include <iostream>

template<typename T>
class Singleton {
protected:
inline static T* ptr = nullptr;
  Singleton(){
  }

public:
  static T* getInst() {
    if (ptr == nullptr) {
      ptr = new T ();
    }

    return ptr;
  }
};

class Derived : public Singleton<Derived> {
private:
  friend class Singleton<Derived>;
  Derived() {
    std::cout << "Derived";
  }
};

int main() {
 auto p = Singleton<Derived>::getInst();
 auto p2 = Singleton<Derived>::getInst();
  return 0;
}
