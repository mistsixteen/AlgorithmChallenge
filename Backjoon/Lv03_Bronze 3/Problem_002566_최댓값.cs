//Backjoon Problem No.2566
//https://www.acmicpc.net/problem/2566
//Mist16, 2022-12-19

using System;
using System.Collections.Generic;

namespace CSharp_Common
{

    class Program
    {

        static void Main(string[] args)
        {
            int maxValue = -1;
            int xPos = 0, yPos = 0;

            for (int i = 0; i < 9; i++)
            {
                var input = Console.ReadLine();
                string[] words = input.Split(' ');
                for (int j = 0; j < 9; j++)
                {
                    var value = int.Parse(words[j]);
                    if (value > maxValue)
                    {
                        maxValue = value;
                        xPos = i;
                        yPos = j;
                    }

                }
            }

            xPos++;
            yPos++;

            Console.WriteLine(maxValue);
            Console.WriteLine(xPos.ToString() + " " + yPos.ToString());

        }
    }
}