using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            int testCases;
            string str;
            str = Console.ReadLine();
            try
            {
                testCases = Int32.Parse(str);
            }
            catch (FormatException)
            {
                testCases = 0;
            }
            for (int i = 0; i < testCases; i++)
            {
                str = Console.ReadLine();
                Console.WriteLine("" + str[0] + str[str.Length - 1]);
            }
        }
    }
}