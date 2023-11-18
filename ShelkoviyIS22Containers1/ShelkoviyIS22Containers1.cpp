#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float myAbs(float number)
{
    if (number > 0.0f)
        return number;
    else
        return -number;
}

void printArray(float* arr, int size)
{
    cout << fixed << setprecision(3);

    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << arr[size - 1] << '\n';

    cout << setprecision(0);
}

float* addElements(float* arr, int size, float* elements, int elementsCount)
{
    int sizeRes = size + elementsCount;
    float* result = new float[sizeRes];
    for (int i = 0; i < size; i++)
    {
        result[i] = arr[i];
    }
    for (int i = 0; i < elementsCount; i++)
    {
        result[size + i] = elements[i];
    }

    delete[] arr;
    return result;
}

float* deleteLast(float* arr, int size)
{
    int sizeRes = size - 1;
    float* result = new float[sizeRes];
    for (int i = 0; i < sizeRes; i++)
    {
        result[i] = arr[i];
    }

    delete[] arr;
    return result;
}

float* sumAndMiddle(float* arr, int size)
{
    float* result = new float[2];
    result[0] = 0;
    for (int i = 0; i < size; i++)
    {
        result[0] += arr[i];
        result[1] += myAbs(arr[i]);
    }
    result[1] = result[1] / size;

    return result;
}

void transformArray(float* arr, int size)
{
    float* t = sumAndMiddle(arr, size);
    float mid = t[0] / size;
    delete[] t;

    for (int i = 0; i < size; i++)
    {
        if ((int)arr[i] % 2 != 0) arr[i] = arr[i] / mid;
    }
}


int main()
{
    int size;
    cin >> size;

    float* arr = new float[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    float* elsToAdd = NULL;
    int op = -1;
    float* arg = new float[1];

    cout << size << '\n';
    while (true)
    {
        printArray(arr, size);
        elsToAdd = sumAndMiddle(arr, size);
        arr = addElements(arr, size, elsToAdd, 2);
        size += 2;
        delete[] elsToAdd;
        printArray(arr, size);
        transformArray(arr, size);
        printArray(arr, size);

        cin >> op;
        if (op == 0) break;
        if (op == 1)
        {
            cin >> arg[0];
            arr = addElements(arr, size, arg, 1);
            size += 1;
            cout << "+: " << size << '\n';
        }
        else
        {
            arr = deleteLast(arr, size);
            size -= 1;
            cout << "-: " << size << '\n';
        }
    }
    delete[] arg;
}
