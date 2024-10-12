
public class Lab3
{
    public static List<int> RemoveDuplicates(List<int> numbers)
    {
        HashSet<int> uniqueNumbers = new HashSet<int>(numbers);

        return new List<int>(uniqueNumbers);
    }

    public static void Main()
    {
        List<int> numbers = new List<int> { 1, 2, 3, 2, 4, 5, 5, 6, 7, 8, 8, 9 };
        List<int> result = RemoveDuplicates(numbers);

        Console.WriteLine("List without duplicates:");
        foreach (var num in result)
        {
            Console.Write(num + " ");
        }
    }
}
