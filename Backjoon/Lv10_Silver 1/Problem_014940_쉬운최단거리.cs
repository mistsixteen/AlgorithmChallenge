//Backjoon Problem No.14940
//https://www.acmicpc.net/problem/14940
//Mist16, 2022-12-20

using System;
using System.Collections.Generic;
using System.Text;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            int xSize, ySize;


            Queue<KeyValuePair<int, int>> findQueue = new Queue<KeyValuePair<int, int>>(1000 * 1000);

            var input = Console.ReadLine();
            var words = input.Split(' ');

            ySize = int.Parse(words[0]);
            xSize = int.Parse(words[1]);

            int[,] array = new int[ySize, xSize];

            for (int i = 0; i < ySize; i++)
            {
                input = Console.ReadLine();
                words = input.Split();

                for (int j = 0; j < xSize; j++)
                {
                    switch (int.Parse(words[j]))
                    {
                        case 0:
                            array[i, j] = 0;
                            break;
                        case 1:
                            array[i, j] = -1;
                            break;
                        case 2:
                            array[i, j] = 0;
                            findQueue.Enqueue(new KeyValuePair<int, int>(i, j));
                            break;
                    }

                }
            }
            while (findQueue.Count != 0)
            {
                var Pair = findQueue.Dequeue();
                var yPos = Pair.Key;
                var xPos = Pair.Value;
                //up
                if (yPos - 1 >= 0 && array[yPos - 1, xPos] == -1)
                {
                    array[yPos - 1, xPos] = array[yPos, xPos] + 1;
                    findQueue.Enqueue(new KeyValuePair<int, int>(yPos - 1, xPos));
                }

                //down
                if (yPos + 1 < ySize && array[yPos + 1, xPos] == -1)
                {
                    array[yPos + 1, xPos] = array[yPos, xPos] + 1;
                    findQueue.Enqueue(new KeyValuePair<int, int>(yPos + 1, xPos));
                }

                //left
                if (xPos - 1 >= 0 && array[yPos, xPos - 1] == -1)
                {
                    array[yPos, xPos - 1] = array[yPos, xPos] + 1;
                    findQueue.Enqueue(new KeyValuePair<int, int>(yPos, xPos - 1));
                }
                //right
                if (xPos + 1 < xSize && array[yPos, xPos + 1] == -1)
                {
                    array[yPos, xPos + 1] = array[yPos, xPos] + 1;
                    findQueue.Enqueue(new KeyValuePair<int, int>(yPos, xPos + 1));
                }
            }

            StringBuilder strBuilder = new StringBuilder();

            for (int i = 0; i < ySize; i++)
            {
                for (int j = 0; j < xSize; j++)
                {
                    strBuilder.Append(array[i, j].ToString()).Append(' ');
                }
                strBuilder.Append("\n");
            }
            Console.WriteLine(strBuilder.ToString());
        }
    }
}