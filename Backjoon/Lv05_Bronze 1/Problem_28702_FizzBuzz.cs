//Backjoon Problem No.28702
//https://www.acmicpc.net/problem/28702
//Mist16, 2025-06-07

#nullable disable

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            int answer = 0;
            int result = 0;
            var str = Console.ReadLine();

            if (int.TryParse(str, out result))
            {
                answer = result;
            }
            answer++;

            str = Console.ReadLine();
            if (int.TryParse(str, out result))
            {
                answer = result;
            }
            answer++;

            str = Console.ReadLine();
            if (int.TryParse(str, out result))
            {
                answer = result;
            }
            answer++;

            if (answer % 3 == 0)
            {
                if (answer % 5 == 0)
                {
                    Console.WriteLine("FizzBuzz");
                }
                else
                {
                    Console.WriteLine("Fizz");
                }
            }
            else if (answer % 5 == 0)
            {
                Console.WriteLine("Buzz");
            }
            else
            {
                Console.WriteLine(answer);
            }
        }
    }
}