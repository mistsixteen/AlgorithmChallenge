//https://www.codewars.com/kata/54bf1c2cd5b56cc47f0007a1
#include <string>

std::size_t duplicateCount(const std::string& in)
{
    int i[100] = {0};
    int result = 0;
  
    for(char a : in)
    {
        int temp = (int)a;
        if (temp >= 97)
        {
            //tolower by ascii integer
            temp -= 32;
        }
      
        i[temp]++;
      
        if(i[temp] == 2)
        {
          result++;
        }
    }
  
    return result;
}