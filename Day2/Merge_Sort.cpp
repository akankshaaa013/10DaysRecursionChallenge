#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    int mainArrayIndex = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;

    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] < second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void Merge_Sort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    // Sorting Left part
    Merge_Sort(arr, s, mid);

    // Sorting Right part
    Merge_Sort(arr, mid + 1, e);

    // Merging Two sorted array.
    merge(arr, s, e);
}

int main()
{

    int n;
    vector<int> arr;
    cout << "Enter the size of the array : ";
    cin >> n;

    cout << "Enter the Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    Merge_Sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
}