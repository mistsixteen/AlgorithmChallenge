//Backjoon Problem No.10815
//https://www.acmicpc.net/problem/10815
//Mist16, 2022-06-21

using System;
using System.Text;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            StringBuilder result = new StringBuilder();
            var str = Console.ReadLine();
            var n = Int32.Parse(str);

            int[] array = new int[20000001];

            str = Console.ReadLine();
            string[] numbers = str.Split(" ");

            foreach(string s in numbers)
            {
                int i = Int32.Parse(s);
                array[i + 10000000] = 1;
            }
            str = Console.ReadLine();
            str = Console.ReadLine();
            numbers = str.Split(" ");
            foreach (string s in numbers)
            {
                int i = Int32.Parse(s);
                if(array[i + 10000000] == 1)
                {
                    result.Append("1 ");
                }
                else
                    result.Append("0 ");

            }
            Console.Write(result);
        }
    }
}