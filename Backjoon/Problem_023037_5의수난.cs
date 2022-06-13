using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            int result = 0;
            string str;
            str = Console.ReadLine();
            for(int i = 0; i < 5; i++)
            {
                int temp = str[i] - '0';
                result += (temp * temp * temp * temp * temp);
            }
            Console.WriteLine(result);
        }
    }
}