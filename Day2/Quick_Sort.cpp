#include<bits/stdc++.h>
using namespace std;

//partition() function -> Considers the starting element as the pivot element and then in the one-time scanning 
//while segregate the left elements (smaller than pivot) & right elements (greater than pivot) and then finally returning 
//the pivotIndex.
int partition(vector<int> &arr,int s,int e){
    
    int pivot = arr[s];
    int i = s;

    for(int j = s;j<=e;j++){
        if(arr[j] < pivot ){
            i+=1;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i],arr[s]);

    return i;

}

//Quick_Sort() function with each recursive call(after returned) places the first element at it's correct position
//(pivotIndex).

void Quick_Sort(vector<int>& arr,int s,int e){
    
    if(s>=e){
        return;
    }

    int index = partition(arr,s,e);

    Quick_Sort(arr,s,index-1);

    Quick_Sort(arr,index+1,e);
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

    Quick_Sort(arr ,0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "   ";
    }
}