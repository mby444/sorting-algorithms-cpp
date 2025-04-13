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

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swapValue(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swapValue(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n = 10;
    int arr[n] = {23, 5, 87, 12, 45, 3, 76, 34, 9, 58};

    cout << "Before sorting:" << endl;
    printArray(arr, n);

    heapSort(arr, n);

    cout << "After sorting:" << endl;
    printArray(arr, n);
    return 0;
}