using System;

public class Program
{
    public static void Main()
    {
        Vector2 point1;
        Vector2 point2;
        Vector2 point3;

        Console.WriteLine("Enter coordinates of the first vertex (x1, y1):");
        point1.x = double.Parse(Console.ReadLine());
        point1.y = double.Parse(Console.ReadLine());

        Console.WriteLine("Enter coordinates of the second vertex (x2, y2):");
        point2.x = double.Parse(Console.ReadLine());
        point2.y = double.Parse(Console.ReadLine());

        Console.WriteLine("Enter coordinates of the third vertex (x3, y3):");
        point3.x = double.Parse(Console.ReadLine());
        point3.y = double.Parse(Console.ReadLine());

        double a = DistanceBetweenPoints(point1, point2);
        double b = DistanceBetweenPoints(point2, point3);
        double c = DistanceBetweenPoints(point3, point1);

        Console.WriteLine($"Side a: {a}");
        Console.WriteLine($"Side b: {b}");
        Console.WriteLine($"Side c: {c}");

        double area = AreaOfTriangle(a, b, c);

        Console.WriteLine($"The area of the triangle is: {area}");
    }

    private static double AreaOfTriangle(double a, double b, double c)
    {
        double p = (a + b + c) / 2;
        double area = Math.Sqrt(p * (p - a) * (p - b) * (p - c)); 
        return area;
    }

    private static double DistanceBetweenPoints(Vector2 firstPoint, Vector2 secondPoint)
    {
        return Math.Sqrt(Math.Pow(secondPoint.x - firstPoint.x, 2) + Math.Pow(secondPoint.y - firstPoint.y, 2));
    }
}

public struct Vector2
{
    public double x;
    public double y;
}
