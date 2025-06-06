//Backjoon Problem No.2217
//https://www.acmicpc.net/problem/2217
//Mist16, 2022-01-04

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int n = int.Parse(str);

            List<int> li = new List<int>(n);
            for (int i = 0; i < n; i++)
            {
                str = Console.ReadLine();
                var number = int.Parse(str);
                li.Add(number);
            }
            li.Sort();

            //run
            long max = 0;
            for (int i = 1; i <= li.Count; i++)
            {
                long newvalue = li[n - i] * i;
                if (newvalue > max) max = newvalue;
            }
            Console.WriteLine(max);
        }
    }
}