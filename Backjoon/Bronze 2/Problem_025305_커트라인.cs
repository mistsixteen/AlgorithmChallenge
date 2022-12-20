//Backjoon Problem No.25305
//https://www.acmicpc.net/problem/25305
//Mist16, 2022-12-20

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> list = new List<int>();
            int n, k;
            var input = Console.ReadLine();
            var words = input.Split(' ');
            n = int.Parse(words[0]);
            k = int.Parse(words[1]);

            input = Console.ReadLine();
            words = input.Split(" ");

            for (int i = 0; i < n; i++)
            {
                var score = int.Parse(words[i]);
                list.Add(score);
            }
            list.Sort();
            Console.WriteLine(list[n - k]);
        }
    }
}