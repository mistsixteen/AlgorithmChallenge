//Backjoon Problem No.1417
//https://www.acmicpc.net/problem/1417
//Mist16, 2022-06-25

using System;
namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            int people = 0;
            var str = Console.ReadLine();
            int n = Int32.Parse(str);
            str = Console.ReadLine();
            int Dasom = Int32.Parse(str);

            int[] array = new int[n - 1];

            for (int i = 0; i < n - 1; i++)
            {
                str = Console.ReadLine();
                array[i] = Int32.Parse(str);
            }

            //run
            while(true)
            {
                //check biggest
                var biggestNode = -1;
                //동점방지
                var biggest = Dasom + people - 1;

                //속도계산해보니 그냥 이래도 충분할듯
                for(int i = 0; i < n - 1; i++)
                {
                    if(array[i] > biggest)
                    {
                        biggest = array[i];
                        biggestNode = i;
                    }
                }

                //run
                if (biggestNode == -1)
                    break;
                else
                {
                    array[biggestNode]--;
                    people++;
                }
                    
            }

            Console.Write(people);

        }
    }
}