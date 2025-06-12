//Backjoon Problem No.25314
//https://www.acmicpc.net/problem/25314
//Mist16, 2025-06-12

#nullable disable

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();

            var N = int.Parse(str);

            for (int i = 0; i < N / 4; i++)
            {
                Console.Write("long ");
            }
            Console.Write("int");
        }
    }
}