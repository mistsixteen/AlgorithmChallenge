//Backjoon Problem No.15873
//https://www.acmicpc.net/problem/15873
//Mist16, 2022-12-10

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
                       
            var input = Console.ReadLine();
            int answer = 0;

            switch (input.Length)
            {
                case 2:
                    answer = int.Parse(input.Substring(0, 1)) + int.Parse(input.Substring(1, 1));
                    break;
                case 3:
                    if (input[0] == '1' && input[1] == '0')
                    {
                        answer = int.Parse(input.Substring(0, 2)) + int.Parse(input.Substring(2, 1));
                    }
                    else
                        answer = int.Parse(input.Substring(0, 1)) + int.Parse(input.Substring(1, 2));
                    break;
                case 4:
                    answer = 20;
                    break;
            }

            Console.Write(answer);
        }
    }
}