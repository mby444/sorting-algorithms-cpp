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
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (arr[j] < arr[high])
        {
            i++;
            swapValue(&arr[j], &arr[i]);
        }
        j++;
    }

    i++;
    swapValue(&arr[i], &arr[high]);
    return i;
}

void quickSort(int *arr, int low, int high)
{
    if (high <= low)
    {
        return;
    }

    int pivot = partition(arr, low, high);

    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}

int main()
{
    int n = 10;
    int arr[n] = {23, 5, 87, 12, 45, 3, 76, 34, 9, 58};

    cout << "Before sorting:" << endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "After sorting:" << endl;
    printArray(arr, n);
    return 0;
}