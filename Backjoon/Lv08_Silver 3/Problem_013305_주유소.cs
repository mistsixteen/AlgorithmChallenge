//Backjoon Problem No.13305
//https://www.acmicpc.net/problem/13305
//Mist16, 2022-12-20

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            int n;

            ulong[] ulRoadLength;
            ulong[] ulOilprice;

            ulong totalPrice = 0;
            ulong minOilPrice = 1000000001;

            var input = Console.ReadLine();
            n = int.Parse(input);

            ulRoadLength = new ulong[n];
            ulOilprice = new ulong[n];

            input = Console.ReadLine();
            var words = input.Split(' ');

            for (int i = 0; i < n - 1; i++)
            {
                ulRoadLength[i] = ulong.Parse(words[i]);
            }

            input = Console.ReadLine();
            words = input.Split(' ');

            for (int i = 0; i < n; i++)
            {
                ulOilprice[i] = ulong.Parse(words[i]);
            }

            for (int i = 0; i < n - 1; i++)
            {
                if (minOilPrice > ulOilprice[i])
                    minOilPrice = ulOilprice[i];
                totalPrice += minOilPrice * ulRoadLength[i];
            }


            Console.WriteLine(totalPrice);

        }
    }
}