//Backjoon Problem No.27866
//https://www.acmicpc.net/problem/27866
//Mist16, 2025-06-05

#nullable disable

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            string str1 = Console.ReadLine();
            string str2 = Console.ReadLine();

            int n = int.Parse(str2);

            Console.WriteLine(str1[n-1]);
        }
    }
}