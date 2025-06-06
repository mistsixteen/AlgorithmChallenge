//Backjoon Problem No.10156
//https://www.acmicpc.net/problem/10156
//Mist16, 2022-12-30

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            string[] words = str.Split(' ');
            int price = int.Parse(words[0]);
            int count = int.Parse(words[1]);
            int currentmoney = int.Parse(words[2]);

            var moneyRequire = (price * count) - currentmoney;
            if (moneyRequire < 0) moneyRequire = 0;

            Console.WriteLine(moneyRequire);
        }
    }
}