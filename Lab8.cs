class Program
{
    public static async Task<string> LoadDataFromServerAsync()
    {
        Console.WriteLine("Завантаження даних із сервера...");

        await Task.Delay(3000);

        Console.WriteLine("Завантаження завершено.");
        return "Дані з сервера";
    }

    static async Task Main(string[] args)
    {
        Console.WriteLine("Початок програми");

        string data = await LoadDataFromServerAsync();

        Console.WriteLine($"Отримані дані: {data}");

        Console.WriteLine("Кінець програми");
    }
}
