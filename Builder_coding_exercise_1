#include <string>
#include <ostream>
#include <vector>

using namespace std;

class CodeBuilder
{
  string className;
  vector<pair<string, string>> members;

public:
  CodeBuilder(const string& class_name)
  {
    // todo
    className = class_name;

  }

  CodeBuilder& add_field(const string& name, const string& type)
  {
    // todo
    members.emplace_back(make_pair(type, name));
    return *this;
   }

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj)
  {
    // todo
    os << "class" << ' ' << obj.className << endl << '{'<<endl;
  }


  for (const auto& m : obj.members)
    os <<"  "<< m.first <<' '<< m.second << ';' << endl;
  os << "}";

  return os;

 }

};

int main()
{
CodeBuilder cb = CodeBuilder{ "Person" }.add_field("name", "string").add_field("age", "int");
cout << cb;
}
