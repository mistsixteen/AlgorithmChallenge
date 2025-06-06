//Backjoon Problem No.5341
//https://www.acmicpc.net/problem/5341
//Mist16, 2022-01-04

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                string str = Console.ReadLine();
                int n = int.Parse(str);
                if (n == 0) break;
                int result = (n) * (n + 1) / 2;
                Console.WriteLine(result);
            }
        }
    }
}