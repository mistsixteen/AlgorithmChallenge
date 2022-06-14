//Backjoon Problem No.11052
//https://www.acmicpc.net/problem/11052
//Mist16, 2022-06-14

using System;
using System.Text.RegularExpressions;

namespace CSharp_Common
{
    class CardPurchase
    {
        int n;
        int[] buyValue;
        int[] memoryValue;

        public void setN(int newN)
        {
            n = newN;
            buyValue = new int[n];
            memoryValue = new int[n+1];           
        }
        public void setValue(string value)
        {
            string[] digits = Regex.Split(value, " ");
            int i = 0;
            foreach(string v in digits)
            {
                int number;
                if(int.TryParse(v, out number))
                {
                    buyValue[i] = number;
                    i++;
                }
            }
        }
        public int run()
        {
            operation(0, 0);
            return memoryValue[n];
        }
        private void operation(int currentNum, int currentPrice)
        {
            for(int i = 0; i < n; i++)
            {
                if (currentNum + i + 1 > n)
                    break;
                if(memoryValue[currentNum + i + 1] < currentPrice + buyValue[i])
                {
                    memoryValue[currentNum + i + 1] = currentPrice + buyValue[i];
                    operation(currentNum + i + 1, currentPrice + buyValue[i]);
                }
            }
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            CardPurchase cp = new CardPurchase();
            string str;
            int n;
            str = Console.ReadLine();
            if(int.TryParse(str, out n))
            {
                cp.setN(n);
            }

            str = Console.ReadLine();
            cp.setValue(str);

            Console.WriteLine(cp.run());
        }
    }
}