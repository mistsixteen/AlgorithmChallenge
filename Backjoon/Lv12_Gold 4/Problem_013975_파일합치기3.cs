//Backjoon Problem No.13975
//https://www.acmicpc.net/problem/13975
//Mist16, 2022-12-08

using System;
using System.Collections.Generic;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            
            var str = Console.ReadLine();
            int testCase = Int32.Parse(str);
            for(int currentCase = 0; currentCase < testCase; currentCase++)
            {
                PriorityQueue<ulong, ulong> Pages = new PriorityQueue<ulong, ulong>();
                ulong answer = 0;

                str = Console.ReadLine();
                int size = Int32.Parse(str);
                str = Console.ReadLine();
                string[] words = str.Split(" ");

                foreach(var word in words)
                {
                    var data = ulong.Parse(word);
                    Pages.Enqueue(data, data);
                }


                while (Pages.Count != 1)
                {
                    var Data1 = Pages.Dequeue();
                    var Data2 = Pages.Dequeue();

                    ulong newData = Data1 + Data2;
                    answer = answer + newData;
                    Pages.Enqueue(newData, newData);
                }
                Console.WriteLine(answer);
            }
        }
    }
}
