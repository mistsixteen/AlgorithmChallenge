//Backjoon Problem No.5524
//https://www.acmicpc.net/problem/5524
//Mist16, 2022-01-01

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int testCases = int.Parse(str);

            for (int i = 0; i < testCases; i++)
            {
                str = Console.ReadLine();
                Console.WriteLine(str.ToLower());
            }

        }
    }
}