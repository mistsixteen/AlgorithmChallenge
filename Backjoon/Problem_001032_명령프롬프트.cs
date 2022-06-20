//Backjoon Problem No.1032
//https://www.acmicpc.net/problem/1032
//Mist16, 2022-06-21

using System;

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = Console.ReadLine();
            var numberOfStrings = Int32.Parse(str);

            string[] strings = new string[numberOfStrings];

            for(int i = 0; i < numberOfStrings; i++)
            {
                strings[i] = Console.ReadLine();
            }
            var numberOfCharacters = strings[0].Length;

            string output = "";

            for(int i = 0; i < numberOfCharacters; i++)
            {
                var flag = true;
                var firstCharacter = strings[0][i];

                for(int j = 0; j < numberOfStrings; j++)
                {
                    if(strings[j][i] != firstCharacter)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    output += firstCharacter;
                }
                else
                    output += "?";

            }

            Console.Write(output);

        }
    }
}