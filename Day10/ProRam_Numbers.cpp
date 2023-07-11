#include <bits/stdc++.h> 
using namespace std;

//getDigits() function returns the vector of seperate digits of an integer. for e.g : if num = 123 then the function returns {1,2,3}.

vector<int> getDigits(int num){
    vector<int> nums;
    while(num!=0){
        nums.push_back(num%10);
        num/=10;
    }
    reverse(nums.begin(),nums.end());
    return nums;
}


int solve(unsigned int index, bool flag, vector<int>& digits,int n, vector<int>& nums){

    if(!flag){
        int res = 1;
        for(unsigned int i = index; i<nums.size();i++){
            res = res*digits.size();
        }
        return res;
    }

    if(index >= nums.size()){
        return 1;
    }

    int curr = 0;

    for(auto i :digits){
        if(i < nums[index]){
            curr = curr + solve(index+1,false,digits,n,nums);
        }
        else if(i == nums[index]){
            curr = curr + solve(index+1,true,digits,n,nums);
        }
        else{
            break;
        }
    }

    return curr;

}


int possibleNumbers(int n, int m, vector<int>& digits) {
	
    vector<int> nums = getDigits(m);

    int len = nums.size();
    
    int count = 0;

    //count the numbers with length less than m.

    for(int i = 1; i<len ; i++){
        count = count + pow(n,i);
    }

    //Count the numbers with length equal to n.
    count = count + solve(0,true,digits,n,nums);

    return count;

}

int main(){
    int n,m;
    cout<<"Enter the value of n : ";
    cin>>n;

    vector<int> num;

    cout<<"Enter the vector elements : ";
    for(int i = 0;i<n;i++){
        int a;
        cin>>a;
        num.push_back(a);
    }

    cout<<"Enter the target element : ";
    cin>>m;

    cout<<"Number of elements are  :  "<<possibleNumbers(n,m,num);
}