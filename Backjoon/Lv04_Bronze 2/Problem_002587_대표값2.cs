//Backjoon Problem No.2587
//https://www.acmicpc.net/problem/2587
//Mist16, 2022-12-16

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {

        static void Main(string[] args)
        {
            List<int> list = new List<int>();
            int total = 0;
            for(int i = 0; i < 5; i++)
            {
                var str = Console.ReadLine();
                int input = int.Parse(str);
                list.Add(input);
                total += input;
            }
            list.Sort();
            Console.WriteLine((int)total/5);
            Console.WriteLine(list[2]);
        }
    }
}