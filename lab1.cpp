#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void partOne() {
    int arr[15];

    srand(static_cast<unsigned int>(time(0))); 

    for (int i = 0; i < 15; i++)
    {
        arr[i] = getRandomNumber(-50, 50);
        cout << arr[i] << " ";
    }


    int sumPositives = 0;
    int countPositives = 0;
    int sumNegatives = 0;
    int countNegatives = 0;

    for (int i = 0; i < 15; i++) {
        if (arr[i] > 0) {
            sumPositives += arr[i];
            countPositives++;
        }
        else if (arr[i] < 0) {
            sumNegatives += arr[i];
            countNegatives++;
        }
    }

    int avgPositive = 0.0;
    int avgNegative = 0.0;

    if (countPositives > 0) {
        avgPositive = sumPositives / countPositives;
    }

    if (countNegatives > 0) {
        avgNegative = sumNegatives / countNegatives;
    }

    cout << "Середнє арифметичне додатних чисел: " << avgPositive << endl;
    cout << "Середнє арифметичне від'ємних чисел: " << avgNegative << endl;

}

void partTwo()
{
    int arr[4][6];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            arr[i][j] = getRandomNumber(-50, 50);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    double min = 0;
    int minCount = 0;

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j] < 0)
            {
                min += arr[i][j];
                minCount++;
            }
        }
        cout << "Мінімальне: " << min / minCount << endl;
        min = 0;
        minCount = 0;
    }

}

int main()
{
    cout << "Part one: " << endl;
    cout << endl;
    partOne();
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Part two: " << endl;
    partTwo();

    return 0;
}