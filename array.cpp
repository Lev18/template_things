#include <vector>
#include <iostream>
#include <string>

struct Person {
  Person(const std::string& name, int age) : m_name{name}, m_age{age}{
  }
  Person(const Person& lhs) : m_name{lhs.m_name}, m_age{lhs.m_age} {}
  Person(Person&& p) : m_name {std::move(p.m_name)}, m_age{std::move(p.m_age)} {
    m_name = nullptr;
    m_age = 0;
  }
  std::string m_name;
  int m_age;
  friend std::ostream& operator<<(std::ostream& COUT, const Person& p) {
    COUT << p.m_name << " " << p.m_age;
    return COUT;
  }
};

template<typename T>
struct A {
  A<T>(T t) : _t{t}{}
  T _t;
  inline static std::vector<A<T>*> elems;
};

template<typename T>
void print_elem() {
  for (const auto& elem : A<T>::elems) {
    std::cout << elem->_t << " ";
  }
  std::cout << std::endl;
}
template<typename... Ts>
void print_elem_variadic() {
  (print_elem<Ts>(), ...);
}

void create_Array() {}

template<typename T, typename... Ts>
void create_Array(T t, Ts... ts) {
  A<T>* pt = new A<T>(t);
  create_Array(ts...);
  A<T>:: elems.push_back(pt);
}

int main() {

  create_Array('p',1, 2.5, 'c', "string", Person{"Sally", 18});
  print_elem_variadic<int, double, char, const char*, Person>();

  return 0;
}












