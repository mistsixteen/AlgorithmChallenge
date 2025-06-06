//Backjoon Problem No.31403
//https://www.acmicpc.net/problem/31403
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
            string str3 = Console.ReadLine();

            int a = int.Parse(str1);
            int b = int.Parse(str2);
            int c = int.Parse(str3);
            int ab = int.Parse(str1 + str2);

            Console.WriteLine(a + b - c);
            Console.WriteLine(ab - c);
        }
    }
}