#include <string>
#include <vector>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
int id{ 0 };
public:
  Person create_person(const string& name)
  {
    // todo
    return { id++, name };    
  }
};

