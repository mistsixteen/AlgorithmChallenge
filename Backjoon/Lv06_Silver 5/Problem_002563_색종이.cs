//Backjoon Problem No.2563
//https://www.acmicpc.net/problem/2563
//Mist16, 2022-12-11


using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            var numString = Console.ReadLine();
            int answer = 0;
            int num = int.Parse(numString);
            int[,] board = new int[101, 101];

            for (int count = 0; count < num; count++)
            {
                var str = Console.ReadLine();
                var words = str.Split(' ');
                int x = int.Parse(words[0]);
                int y = int.Parse(words[1]);
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (board[x + i, y + j] == 0)
                        {
                            board[x + i, y + j] = 1;
                            answer++;
                        }

                    }
                }
            }
            Console.WriteLine(answer);
        }
    }
}