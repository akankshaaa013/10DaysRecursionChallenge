#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr1, vector<int> &arr2, int st1, int en1, int st2, int en2, int k){

    // if st1 is equal to en1 then it impies that only 1 integer is left in arr1
    // and so the kth integer exists in arr2. 
    if (st1 == en1)
    {
        return arr2[st2 + k];
    }
    
    // if st2 is equal to en2 then it impies that only 1 integer is left in arr2
    // and so the kth integer exists in arr1. 
    if (st2 == en2)
    {
        return arr1[st1 + k];
    }
    
    // Calculating the mids of 2 array so that we can eliminate the portions of array to find the kth integer.
    
    int mid1 = (en1 - st1) / 2;
    int mid2 = (en2 - st2) / 2;

    // if average of mid is less than k, it implies that kth element lies in second half of either arr1 or arr2.
    
    if ((mid1 + mid2) < k)
    {
        // if the mid element of arr1 is greater than arr2, it basically implies that our
        // solution does not lie in first half of the arr2. 
        if (arr1[st1 + mid1] > arr2[st2 + mid2])
        {
            // Rejecting the first half of 'ARR2'.
            return solve(arr1, arr2, st1, en1, st2 + mid2 + 1, en2, k - mid2 - 1);
        }
        // else if the mid element of arr2 is greater than arr1, it basically implies that our
        // solution does not lie in first half of the arr1. 
        else
        {
            // Rejecting the first half of 'ARR1'.
            return solve(arr1, arr2, st1 + mid1 + 1, en1, st2, en2, k - mid1 - 1);
        }
    }
    else
    // if average of mid is greater than k, it implies that kth element lies in first half of either arr1 or arr2.
    
    {
        if (arr1[st1 + mid1] > arr2[st2 + mid2])
        {
            // Rejecting the second half of 'ARR1'.
            return solve(arr1, arr2, st1, st1 + mid1, st2, en2, k);
        }
        else
        {
            // Rejecting the second half of 'ARR2'.
            return solve(arr1, arr2, st1, en1, st2, st2 + mid2, k);
        }
    }
}

int findKthElement(vector<int> arr1, vector<int> arr2, int k){
    int len1 = arr1.size();
    int len2 = arr2.size();

    return solve(arr1, arr2, 0, len1, 0, len2, k - 1);
}

int main(){
    vector<int> arr1;
    int n;
    cout<<"Enter the size of arr1 : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr1.push_back(a);
    }

    vector<int> arr2;
    int m;
    cout<<"Enter the size of arr2 : ";
    cin>>m;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        arr1.push_back(a);
    }

    int k;
    cout<<"Enter the kth element : ";
    cin>>k;

    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());

    int ans = findKthElement(arr1,arr2,k);
    cout<<"Kth element is : "<<ans<<endl;


}