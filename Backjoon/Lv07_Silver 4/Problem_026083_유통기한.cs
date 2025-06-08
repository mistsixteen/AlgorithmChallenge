//Backjoon Problem No.26083
//https://www.acmicpc.net/problem/26083
//Mist16, 2025-06-07

#nullable disable

using System.Text;

namespace CSharp_Common
{
    class Program
    {
        static StringBuilder sb = new();
        static void Main(string[] args)
        {
            int numDataSet = 0;

            //1. Y M D
            var str = Console.ReadLine();

            var arr = str.Split(" ");

            var curYear = int.Parse(arr[0]);
            var curMonth = int.Parse(arr[1]);
            var curDay = int.Parse(arr[2]);

            str = Console.ReadLine();
            numDataSet = int.Parse(str);

            for (int i = 0; i < numDataSet; i++)
            {
                Run(curYear, curMonth, curDay);
            }
            Console.Write(sb.ToString());
        }

        static void Run(int cYear, int cMon, int cDay)
        {
            var str = Console.ReadLine();

            var arr = str.Split(" ");
            var result = new int[3];

            var tYear = int.Parse(arr[0]);
            var tMon = int.Parse(arr[1]);
            var tDay = int.Parse(arr[2]);

            //Y M D
            var exam = examine(cYear, cMon, cDay, tYear, tMon, tDay);
            result[exam]++;
            //D M Y
            exam = examine(cYear, cMon, cDay, tDay, tMon, tYear);
            result[exam]++;
            //M D Y
            exam = examine(cYear, cMon, cDay, tDay, tYear, tMon);
            result[exam]++;

            //print result
            if (result[1] > 0)
            {
                sb.Append("unsafe\n");
            }
            else if (result[2] == 3)
            {
                sb.Append("invalid\n");
            }
            else
            {
                sb.Append("safe\n");
            }

        }

        //0 : safe / 1 : unsafe / 2 : invalid
        static int examine(int cYear, int cMon, int cDay, int tYear, int tMon, int tDay)
        {
            if (tMon > 12 || tMon == 0 || tDay == 0)
            {
                return 2;
            }

            var targetDay = getDay(tYear, tMon);

            if (tDay > targetDay)
            {
                return 2;
            }

            int cYM = cYear * 12 + cMon;
            int tYM = tYear * 12 + tMon;

            if (cYM > tYM)
            {
                return 1;
            }
            else if (cYM == tYM)
            {
                if (cDay > tDay)
                {
                    return 1;
                }
            }

            return 0;
        }

        static int getDay(int Year, int Mon)
        {
            if (Mon == 2)
            {
                if ((Year % 4) == 0)
                {
                    return 29;
                }                
                else
                {
                    return 28;
                }
            }

            if (Mon == 4 || Mon == 6 || Mon == 9 || Mon == 11)
            {
                return 30;
            }

            return 31;
        }
    }
}