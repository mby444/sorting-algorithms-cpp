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

void createSubarray(int subarr[], int arr[], int begin, int end)
{
    int i = begin;
    int j = 0;

    while (i <= end)
    {
        subarr[j] = arr[i];
        j++;
        i++;
    }
}

void merge(int arr[], int arrLeft[], int nLeft, int arrRight[], int nRight)
{
    int n = nLeft + nRight;
    int iArr = 0;
    int iL = 0;
    int iR = 0;

    while (iL < nLeft && iR < nRight)
    {
        if (arrLeft[iL] <= arrRight[iR])
        {
            arr[iArr] = arrLeft[iL];
            iL++;
        }
        else
        {
            arr[iArr] = arrRight[iR];
            iR++;
        }
        iArr++;
    }

    while (iL < nLeft)
    {
        arr[iArr] = arrLeft[iL];
        iL++;
        iArr++;
    }

    while (iR < nRight)
    {
        arr[iArr] = arrRight[iR];
        iR++;
        iArr++;
    }
}

void mergeSort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int mid = (n + 1) / 2;
    int nLeft = mid;
    int nRight = n - mid;
    int arrLeft[mid];
    int arrRight[n - mid];

    createSubarray(arrLeft, arr, 0, nLeft - 1);
    createSubarray(arrRight, arr, nLeft, n - 1);

    mergeSort(arrLeft, nLeft);
    mergeSort(arrRight, nRight);

    merge(arr, arrLeft, nLeft, arrRight, nRight);
}

int main()
{
    int n = 10;
    int arr[n] = {23, 5, 87, 12, 45, 3, 76, 34, 9, 58};

    cout << "Before sorting:" << endl;
    printArray(arr, n);

    mergeSort(arr, n);

    cout << "After sorting:" << endl;
    printArray(arr, n);
    return 0;
}