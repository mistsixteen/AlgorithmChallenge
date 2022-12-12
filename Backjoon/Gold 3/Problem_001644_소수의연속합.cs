//Backjoon Problem No.1644
//https://www.acmicpc.net/problem/1644
//Mist16, 2022-12-12

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            int num = int.Parse(input);
            int total = 0;
            int answer = 0;
            List<int> primeList = new List<int>();

            //1. 에라스토테네스의 채로 Prime Number List 생성
            bool[] a = new bool[num + 1];
            for (int i = 2; i <= num; i++)
            {
                if (!a[i])
                {
                    primeList.Add(i);
                    total += i;
                    for (int j = i; j <= num; j += i)
                    {
                        a[j] = true;
                    }
                }
            }

            if (primeList.Count == 0)
            {
                Console.WriteLine(0);
                return;
            }

            //2.Two Pointer
            int idxA = 0;
            int idxB = 0;
            total = primeList[0];

            while (true)
            {
                if (total == num)
                {
                    answer++;
                    idxB++;
                    if (idxB >= primeList.Count)
                    {
                        break;
                    }
                    total += primeList[idxB];
                }
                else if (total < num)
                {
                    idxB++;
                    if (idxB >= primeList.Count)
                    {
                        break;
                    }
                    total += primeList[idxB];
                }
                else
                {
                    if (idxA > idxB)
                    {
                        break;
                    }
                    total -= primeList[idxA];
                    idxA++;
                }
            }
            Console.WriteLine(answer);
        }
    }
}