//Backjoon Problem No.1145
//https://www.acmicpc.net/problem/1145
//Mist16, 2025-06-09

#nullable disable

using System.Text;

namespace CSharp_Common
{
    class Program
    {
        static StringBuilder sb = new();
        static void Main(string[] args)
        {
            var intArr = new int[5];
            int max = 0;

            //1. Y M D
            var str = Console.ReadLine();

            var arr = str.Split(" ");

            for (int idx = 0; idx < 5; idx++)
            {
                intArr[idx] = int.Parse(arr[idx]);
            }

            while (true)
            {
                var answer = 0;
                for (int idx = 0; idx < 5; idx++)
                {
                    if (max >= intArr[idx] && max % intArr[idx] == 0)
                    {
                        answer++;
                    }
                }

                if (answer >= 3)
                {
                    Console.WriteLine(max);
                    return;
                }

                max++;
            }
        }
    }
}