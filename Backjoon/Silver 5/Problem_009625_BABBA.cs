//Backjoon Problem No.9625
//https://www.acmicpc.net/problem/9625
//Mist16, 2022-12-13

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {

        private static int[,] maxIntakes;
        static void Main(string[] args)
        {
            int num;
            int[,] ABgraph;
            var input = Console.ReadLine();
            num = int.Parse(input);

            ABgraph = new int[num + 1, 2];
            ABgraph[0, 0] = 1;
            ABgraph[0, 1] = 0;
            for (int i = 1; i <= num; i++)
            {
                ABgraph[i, 0] = ABgraph[i - 1, 1];
                ABgraph[i, 1] = ABgraph[i - 1, 0] + ABgraph[i - 1, 1];
            }

            Console.WriteLine(ABgraph[num, 0] + " " + ABgraph[num, 1]);
        }
    }
}