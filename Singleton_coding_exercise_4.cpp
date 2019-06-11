#include <functional>
using namespace std;

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    // TODO
    T* _f1 = factory();
    T* _f2 = factory();
    return _f1 == _f2;
  }
};
