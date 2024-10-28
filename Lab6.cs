class Program
{
    public delegate int SumDelegate(int a, int b);

    static void Main()
    {
        SumDelegate sumDelegate = Add;

        Console.WriteLine("Сума 3 і 5: " + sumDelegate(3, 5));
        Console.WriteLine("Сума 10 і 20: " + sumDelegate(10, 20));
        Console.WriteLine("Сума -7 і 12: " + sumDelegate(-7, 12));
    }

    public static int Add(int a, int b)
    {
        return a + b;
    }
}
