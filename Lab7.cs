
class Program
{
    static void PrintNumbersInRange(int start, int end)
    {
        for (int i = start; i <= end; i++)
        {
            Console.WriteLine($"Потік {Thread.CurrentThread.ManagedThreadId}: {i}");
            Thread.Sleep(100); 
        }
    }

    static void Main()
    {
        Thread thread1 = new Thread(() => PrintNumbersInRange(0, 10));
        Thread thread2 = new Thread(() => PrintNumbersInRange(11, 20));

        thread1.Start();
        thread2.Start();

        thread1.Join();
        thread2.Join();

        Console.WriteLine("Основний потік завершений.");
    }
}
