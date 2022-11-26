//Backjoon Problem No.14405
//https://www.acmicpc.net/problem/14405
//Mist16, 2022-06-22

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            int size = str.Length;
            var flag = true;
            
            for(int idx = 0; idx < size;)
            {
                if(str[idx] == 'p')
                {
                    if (idx + 1 < size && str[idx + 1] == 'i')
                    {
                        idx = idx + 2;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else if(str[idx] == 'k')
                {
                    if (idx + 1 < size && str[idx + 1] == 'a')
                    {
                        idx = idx + 2;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
                else if(str[idx] == 'c')
                {
                    if(idx+2 < size && str[idx+1] == 'h' && str[idx + 2] == 'u')

                    {
                        idx = idx + 3;
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                        
                }
                else
                {
                    flag = false;
                    break;
                }
            }

            if(flag == true)
            {
                Console.WriteLine("YES");
            }
            else
                Console.WriteLine("NO");

        }
    }
}