using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            string str;
            float score;
            str = Console.ReadLine();

            switch (str[0])
            {
                case 'A':
                    score = 4.0f;
                    break;
                case 'B':
                    score = 3.0f;
                    break;
                case 'C':
                    score = 2.0f;
                    break;
                case 'D':
                    score = 1.0f;
                    break;
                default:
                    score = 0.0f;
                    break;
            }
            if (str.Length > 1)
            {
                if (str[1] == '+')
                    score += 0.3f;
                else if (str[1] == '-')
                    score -= 0.3f;
            }


            Console.WriteLine("{0:0.0}", score);
        }
    }
}