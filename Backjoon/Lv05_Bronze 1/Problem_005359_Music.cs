//Backjoon Problem No.5359
//https://www.acmicpc.net/problem/5359
//Mist16, 2025-06-07

#nullable disable

namespace CSharp_Common
{
    class Program
    {
        static void Main(string[] args)
        {
            int numDataSet = 0;
            var str = Console.ReadLine();

            numDataSet = int.Parse(str);

            for (int i = 0; i < numDataSet; i++)
            {
                Console.WriteLine(Run());
            }
        }

        static int Run()
        {
            int n, m, c;
            var str = Console.ReadLine();
            var nmc = str.Split(" ");
            var volumes = new List<int>();
            int result = 0;

            n = int.Parse(nmc[0]);
            m = int.Parse(nmc[1]);
            c = int.Parse(nmc[2]);

            str = Console.ReadLine();
            var numArr = str.Split(" ");

            for (int i = 0; i < n; i++)
            {
                volumes.Add(int.Parse(numArr[i]));
            }

            for (int i = 0; i <= n - m; i++)
            {
                int maxVol = -1;
                int minVol = 1001;
                for (int j = 0; j < m; j++)
                {
                    int idx = i + j;
                    if (maxVol < volumes[idx])
                    {
                        maxVol = volumes[idx];
                    }

                    if (minVol > volumes[idx])
                    {
                        minVol = volumes[idx];
                    }
                }

                var sLevel = maxVol - minVol;
                if (sLevel <= c)
                {
                    result++;
                }
            }

            return result;
        }
    }
}