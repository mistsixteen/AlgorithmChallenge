//Backjoon Problem No.1475
//https://www.acmicpc.net/problem/1475
//Mist16, 2022-06-23

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            int[] array = new int[10];
            int max = 0;

            foreach(char c in str)
            {
                switch(c)
                {
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '7':
                    case '8':
                        array[(c - '0')]++;
                        break;
                    case '6':
                    case '9':
                        array[6]++;
                        break;
                }
            }
            if (array[6] % 2 == 1)
                array[6]++;

            array[6] = array[6] / 2;

            for(int i = 0; i < 9; i++)
            {
                if (max < array[i])
                    max = array[i];
            }
            Console.WriteLine(max);

        }
    }
}