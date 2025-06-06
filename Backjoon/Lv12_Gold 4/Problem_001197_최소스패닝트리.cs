//Backjoon Problem No.1197
//https://www.acmicpc.net/problem/1197
//Mist16, 2022-12-10

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            PriorityQueue<KeyValuePair<int, int>, int> Indices = new PriorityQueue<KeyValuePair<int, int>, int>();
            int[] vertexGroup;
            int currentGroup = 1;
                        
            var firstline = Console.ReadLine();
            string[] words = firstline.Split(" ");
            int countVertex = int.Parse(words[0]);
            int countIndice = int.Parse(words[1]);
            long answer = 0;

            vertexGroup = new int[countVertex + 1];

            for (int i = 1; i <= countVertex; i++)
            {
                vertexGroup[i] = 0;
            }

            for (int i = 0; i < countIndice; i++)
            {
                var line = Console.ReadLine();
                string[] word = line.Split(" ");

                int Vertex1 = int.Parse(word[0]);
                int Vertex2 = int.Parse(word[1]);
                int Value = int.Parse(word[2]);
                if (Vertex1 == Vertex2)
                    continue;
                Indices.Enqueue(new KeyValuePair<int, int>(Vertex1, Vertex2), Value);
            }

            while(Indices.Count > 0)
            {
                KeyValuePair<int, int> indice;
                int value;
                Indices.TryDequeue(out indice, out value);
       
                if (vertexGroup[indice.Key] == 0 && vertexGroup[indice.Value] == 0)
                {
                    answer += value;
                    vertexGroup[indice.Key] = currentGroup;
                    vertexGroup[indice.Value] = currentGroup;
                    currentGroup++;
                }
                else if (vertexGroup[indice.Key] == vertexGroup[indice.Value])
                {
                    continue;
                }
                else if((vertexGroup[indice.Key] == 0 && vertexGroup[indice.Value] != 0))
                {
                    answer += value;
                    vertexGroup[indice.Key] = vertexGroup[indice.Value];
                }
                else if ((vertexGroup[indice.Key] != 0 && vertexGroup[indice.Value] == 0))
                {
                    answer += value;
                    vertexGroup[indice.Value] = vertexGroup[indice.Key];
                }
                else
                {
                    answer += value;
                    var target = vertexGroup[indice.Key];
                    var valueToChange = vertexGroup[indice.Value];
                    for (int i = 1; i <= countVertex; i++)
                    {
                        if (vertexGroup[i] == target)
                            vertexGroup[i] = valueToChange;
                    }
                }
            }
            Console.Write(answer);
        }
    }
}
