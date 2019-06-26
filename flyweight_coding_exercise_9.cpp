#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct Sentence
{
  struct WordToken
  {
    bool capitalize;
  };

  vector<string> words;
  map<int, WordToken> tokens;

  Sentence(const string& text)
  {
    istringstream iss{text};
    words = vector<string>(istream_iterator<string>{iss},
                           istream_iterator<string>{});
  }

  WordToken& operator[](size_t index)
  {
    tokens[index] = WordToken{};
    return tokens[index];
  }

  string str() const
  {
    vector<string> my_words;
    for (size_t i = 0; i < words.size(); ++i)
    {
      string w = words[i];
      auto t = tokens.find(i);
      if (t != tokens.end() && t->second.capitalize)
      {
        // note: the annotation on ::toupper() below is only required
        // for GCC; other compilers work fine without it
        transform(w.begin(), w.end(), w.begin(), toupper);
      }
      my_words.push_back(w);
    }

    ostringstream oss;
    for (size_t i = 0; i < ws.size(); ++i)
    {
      oss << my_words[i];
      if (i+1 != my_words.size()) oss << " ";
    }
    return oss.str();
  }
};
