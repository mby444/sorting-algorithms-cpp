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

int partition(int arr[], int n)
{
    int pivot = n - 1;
    int i = -1;
    int j = 0;

    while (j < pivot)
    {
        if (arr[j] < arr[pivot])
        {
            i++;
            swapValue(&arr[j], &arr[i]);
        }
        j++;
    }

    i++;
    swapValue(&arr[i], &arr[pivot]);
    return i;
}

void quickSort(int *arr, int n)
{
    if (n <= 1)
    {
        return;
    }

    int pivot = partition(arr, n);

    quickSort(arr, pivot);
    quickSort(arr + pivot + 1, n - pivot - 1);
}

int main()
{
    int n = 10;
    int arr[n] = {23, 5, 87, 12, 45, 3, 76, 34, 9, 58};

    cout << "Before sorting:" << endl;
    printArray(arr, n);

    quickSort(arr, n);

    cout << "After sorting:" << endl;
    printArray(arr, n);
    return 0;
}