using System;

namespace Reverse_Add
{
    public class Program
    {

        static int GetReverseInt(int target){
            if(target < 10)
                return target;
            else if(target < 100){
                var digit1 = target % 10;
                target = (target - digit1) / 10;
                var digit2 = target % 10;

                return (digit1 * 10 + digit2);

            }else if(target < 1000){
                var digit1 = target % 10;
                target = (target - digit1) / 10;
                var digit2 = target % 10;
                target = (target - digit2) / 10;
                var digit3 = target % 10;

                return (digit1 * 100 + digit2 * 10 + digit3);
            }
            else{
                var digit1 = target % 10;
                target = (target - digit1) / 10;
                var digit2 = target % 10;
                target = (target - digit2) / 10;
                var digit3 = target % 10;
                target = (target - digit3) / 10;
                var digit4 = target % 10;
                return (digit1 * 1000 + digit2 * 100 + digit3 * 10 + digit4);
            }
        }
        static void Main(){
            string inputLine = Console.ReadLine();
            string[] words = inputLine.Split(' ');
            int numA = Int32.Parse(words[0]);
            int numB = Int32.Parse(words[1]);
            Console.WriteLine(GetReverseInt(GetReverseInt(numA)+GetReverseInt(numB)));
        }
    }
}
