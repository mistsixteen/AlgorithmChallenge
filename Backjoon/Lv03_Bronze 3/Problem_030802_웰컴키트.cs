//Backjoon Problem No.30802
//https://www.acmicpc.net/problem/30802
//Mist16, 2025-06-05

#nullable disable

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            long N = 0;
            long[] numBySize = new long[6];
            long T = 0, P = 0;

            //Handling Input
            string str = Console.ReadLine();
            N = long.Parse(str);
            str = Console.ReadLine();
            var arr = str.Split(" ");

            for (int i = 0; i < 6; i++)
            {
                numBySize[i] = long.Parse(arr[i]);
            }

            str = Console.ReadLine();
            arr = str.Split(" ");

            T = long.Parse(arr[0]);
            P = long.Parse(arr[1]);

            //Process
            long shirtSet = 0;

            for (long i = 0; i < 6; i++)
            {
                var set = numBySize[i] / T;
                shirtSet += set;
                if (set * T != numBySize[i])
                {
                    shirtSet++;
                }
            }

            long penSet = N / P;
            long addPen = (N - (P * penSet));

            //OutPut
            Console.WriteLine(shirtSet);
            Console.WriteLine($"{penSet} {addPen}");
        }
    }
}