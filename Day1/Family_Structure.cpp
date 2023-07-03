#include<bits/stdc++.h>
using namespace std;

//It is been observed in the family tree that odd no. child's gender is same as it's parent while for a even number child
//its gender is alternate. As we backtrack to even numbers's child parents the gender reverses.

//So for Odd no. the function is called for directly its parent.
//While for even no. the function is called for it's parent but the gender is tranformed with each call.

bool Solve_K(long long int k){
		if(k==1){
			return true;
		}

		if(k & 1){
			return Solve_K((k+1)/2);
		}
		else{
			return 1-Solve_K((k+1)/2);
		}
	}


int main(){

    int k,n;
    cout<<"Enter the Nth generation and Kth Child respectively : ";
    cin>>n>>k;

    if(Solve_K(k)){
		cout<< "Male";
	}
	else{
		cout<< "Female";
	}
}