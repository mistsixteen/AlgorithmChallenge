//Backjoon Problem No.2447
//https://www.acmicpc.net/problem/2447
//Mist16, 2022-01-05

using System;
using System.Collections.Generic;
using System.Reflection.Emit;
using System.Text;

namespace CSharp_Common
{
    class StarBuilder
    {
        private bool[,] stars;
        private int size;

        public StarBuilder(int level)
        {
            this.size = level;
            stars = new bool[size, size];
        }

        public void Run()
        {
            run(0, 0, size, false);
            Result();
        }
        private void run(int x, int y, int level, bool isBlank)
        {
            if (level == 1)
            {
                stars[x, y] = !isBlank;
            }
            else if (isBlank)
            {
                for (int i = 0; i < level; i++)
                {
                    for (int j = 0; j < level; j++)
                    {
                        stars[x + i, y + j] = false;
                    }
                }
            }
            else
            {

                var nextLevel = level / 3;

                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (i == 1 && j == 1)
                            run(x + (nextLevel * i), y + (nextLevel * j), nextLevel, true);
                        else
                            run(x + (nextLevel * i), y + (nextLevel * j), nextLevel, false);
                    }
                }
            }
        }

        public void Result()
        {
            StringBuilder strBuilder = new StringBuilder();
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (stars[i, j] == true)
                        strBuilder.Append('*');
                    else
                        strBuilder.Append(' ');
                }
                strBuilder.Append('\n');
            }
            Console.WriteLine(strBuilder.ToString());
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int n = int.Parse(str);
            var starBuilder = new StarBuilder(n);
            starBuilder.Run();
        }
    }
}