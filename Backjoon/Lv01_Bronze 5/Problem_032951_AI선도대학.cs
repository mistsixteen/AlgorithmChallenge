//Backjoon Problem No.32951
//https://www.acmicpc.net/problem/32951
//Mist16, 2025-06-11

#nullable disable

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();

            var year = int.Parse(str);

            Console.WriteLine(year - 2024);
        }
    }
}