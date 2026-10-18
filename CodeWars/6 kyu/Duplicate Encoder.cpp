//https://www.codewars.com/kata/54b42f9314d9229fd6000d9c
#include <cctype>
#include <string>
#include <set>

std::string duplicate_encoder(const std::string& word){
  std::set<char> cSet;
  std::set<char> cSet2;
  std::string result;
  
  for (char a : word)
  {
    auto it = cSet.find((char)toupper(a));
    if(it != cSet.end())
    {
      cSet2.insert((char)toupper(a));
    }
    else
    {
      cSet.insert((char)toupper(a));
    }
  }
  
  int size = word.size();

  for (int i = 0; i < size; i++)
  {
    char ch = word[i];
    auto it = cSet2.find((char)toupper(ch));
    if(it != cSet2.end())
    {
      result.push_back(')');
    }
    else
    {
      result.push_back('(');
    }
  }
  
  return result;
}