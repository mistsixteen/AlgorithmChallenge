//Backjoon Problem No.25916
//https://www.acmicpc.net/problem/25916
//Mist16, 2022-12-17

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {

        static void Main(string[] args)
        {
            //input
            var input = Console.ReadLine();
            string[] words = input.Split(' ');
            int n = int.Parse(words[0]);
            int m = int.Parse(words[1]);
            int[] array = new int[n];

            input = Console.ReadLine();
            words = input.Split(' ');
            for (int i = 0; i < n; i++)
            {
                array[i] = int.Parse(words[i]);
            }

            //two pointer
            int maxValue = 0;
            int currentValue = array[0];
            int a = 0, b = 0;

            while (b <= n)
            {
                if (currentValue <= m)
                {
                    if (currentValue >= maxValue)
                    {
                        maxValue = currentValue;
                    }
                    b++;
                    if (b >= n) break;
                    currentValue += array[b];
                }
                else
                {
                    if (a == b)
                    {
                        a++; b++;
                        if (b >= n) break;
                        currentValue = array[b];
                    }
                    else
                    {
                        currentValue -= array[a];
                        a++;
                    }
                }
            }
            Console.WriteLine(maxValue);

        }
    }
}