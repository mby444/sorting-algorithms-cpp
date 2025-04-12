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

void insertionSort(int arr[], int n)
{
    int key;
    int j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
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