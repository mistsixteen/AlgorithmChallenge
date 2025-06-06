//Backjoon Problem No.2476
//https://www.acmicpc.net/problem/2476
//Mist16, 2022-12-31

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            int testCases = int.Parse(str);
            int maxMoney = 0;

            for (int i = 0; i < testCases; i++)
            {
                str = Console.ReadLine();
                string[] words = str.Split(' ');
                int diceA = int.Parse(words[0]);
                int diceB = int.Parse(words[1]);
                int diceC = int.Parse(words[2]);
                int prizeMoney = 0;
                if (diceA == diceB && diceB == diceC)
                {
                    prizeMoney = 10000 + diceA * 1000;
                }
                else if (diceA == diceB || diceA == diceC)
                {
                    prizeMoney = 1000 + diceA * 100;
                }
                else if (diceB == diceC)
                {
                    prizeMoney = 1000 + diceB * 100;
                }
                else
                {
                    int max = diceA;
                    if (max < diceB)
                        max = diceB;
                    if (max < diceC)
                        max = diceC;
                    prizeMoney = max * 100;
                }

                if (prizeMoney > maxMoney)
                {
                    maxMoney = prizeMoney;
                }
            }
            Console.WriteLine(maxMoney);
        }
    }
}