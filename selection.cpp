#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << "] => " << arr[i] << " ";
    }
    cout << endl;
}

void swapValue(int *val1, int *val2)
{
    *val1 = *val1 + *val2;
    *val2 = *val1 - *val2;
    *val1 = *val1 - *val2;
}

void insertionSort(int arr[], int n)
{
    int smallIndex;

    for (int i = 0; i < n - 1; i++)
    {
        smallIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallIndex])
            {
                smallIndex = j;
            }
        }

        if (i != smallIndex)
        {

            swapValue(&arr[i], &arr[smallIndex]);
        }
    }
}

int main()
{
    int n = 10;
    int arr[n] = {23, 5, 87, 12, 45, 3, 76, 34, 9, 58};

    cout << "Before sorting:" << endl;
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "After sorting:" << endl;
    printArray(arr, n);
    return 0;
}