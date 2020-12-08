using System;

namespace EventSample
{
    public class Program
    {
        public static void SayHoge() { Console.WriteLine("Hoge"); }
        public static void SayFuga() { Console.WriteLine("Fuga"); }
        public static void SayPiyo() { Console.WriteLine("Piyo"); }

        public static void Main()
        {
            CoreClass instance = new CoreClass();

            instance.Callback += SayHoge;
            instance.Callback += SayFuga;
            instance.Callback += SayPiyo;

            instance.CallEvents();

            instance.Callback -= SayHoge;
            instance.Callback -= SayPiyo;

            instance.CallEvents();
        }
    }
}