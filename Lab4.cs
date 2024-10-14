public class Program
{
    public static void Main()
    {
        Car car = new Car("Sorento", "KIA");

        string status = Console.ReadLine();

        car.SetStatus(status);
    }

}

public interface IVehicle
{
    void Start();
    void Stop();
}

public class Car : IVehicle
{
    public string Model;
    public string Make;

    private bool isEngineStart = false;

    public Car(string model, string make)
    {
        Model = model;
        Make = make;
    }

    public void SetStatus(string? status)
    {
        if (status == "off")
            Stop();
        else if (status == "on")
            Start();

    }

    public void Start()
    {
        isEngineStart = true;
        Console.WriteLine("Engine is started");
    }

    public void Stop()
    {
        isEngineStart = false;
        Console.WriteLine("Engine is stopped");
    }
}
