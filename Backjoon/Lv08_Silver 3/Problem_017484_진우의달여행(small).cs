//Backjoon Problem No.17484
//https://www.acmicpc.net/problem/17484
//Mist16, 2022-12-18

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    enum enumDir
    {
        none, left, down, right
    }
    class Program
    {
        static int[,] roadToMoon;
        static int n, m;
        static int minValue = 99999999;

        static void Main(string[] args)
        {
            //input
            var input = Console.ReadLine();
            string[] words = input.Split(' ');
            n = int.Parse(words[0]);
            m = int.Parse(words[1]);

            roadToMoon = new int[n, m];

            for (int i = 0; i < n; i++)
            {
                input = Console.ReadLine();
                words = input.Split(' ');
                for (int j = 0; j < m; j++)
                {
                    roadToMoon[i, j] = int.Parse(words[j]);
                }
            }

            for (int i = 0; i < m; i++)
            {
                run(i, 0, 0, enumDir.none);
            }

            Console.WriteLine(minValue);
        }
        static void run(int x, int y, int currentValue, enumDir currentDir)
        {
            if (y == n)
            {
                if (currentValue < minValue)
                    minValue = currentValue;
                return;
            }

            currentValue += roadToMoon[y, x];

            if (currentValue > minValue)
                return;

            if (x > 0 && currentDir != enumDir.left)
            {
                run(x - 1, y + 1, currentValue, enumDir.left);
            }
            if (currentDir != enumDir.down)
            {
                run(x, y + 1, currentValue, enumDir.down);
            }
            if (x < m - 1 && currentDir != enumDir.right)
            {
                run(x + 1, y + 1, currentValue, enumDir.right);
            }

        }
    }
}