
public class Program
{
    public static void Main()
    {
        MyList<int> list = new MyList<int>();

        list.Add(10);
        list.Add(20);
        list.Add(30);

        Console.WriteLine("Elements in the list:");
        list.PrintAll();

        list.Remove(20);

        Console.WriteLine("Elements after removing 20:");
        list.PrintAll();
    }
}

public class Node<T>
{
    public T Data;
    public Node<T> Next;

    public Node(T data)
    {
        Data = data;
        Next = null;
    }
}

public class MyList<T>
{
    private Node<T> head;

    public MyList()
    {
        head = null;
    }

    public void Add(T data)
    {
        Node<T> newNode = new Node<T>(data);

        if (head == null)
        {
            head = newNode;
        }
        else
        {
            Node<T> current = head;
            while (current.Next != null)
            {
                current = current.Next;
            }
            current.Next = newNode;
        }
    }

    public void Remove(T data)
    {
        if (head == null)
        {
            Console.WriteLine("List is empty.");
            return;
        }

        if (head.Data.Equals(data))
        {
            head = head.Next;
            return;
        }

        Node<T> current = head;
        while (current.Next != null && !current.Next.Data.Equals(data))
        {
            current = current.Next;
        }

        if (current.Next != null)
        {
            current.Next = current.Next.Next;
        }
        else
        {
            Console.WriteLine("Element not found in the list.");
        }
    }

    public void PrintAll()
    {
        if (head == null)
        {
            Console.WriteLine("List is empty.");
            return;
        }

        Node<T> current = head;
        while (current != null)
        {
            Console.WriteLine(current.Data);
            current = current.Next;
        }
    }
}
