#include<bits/stdc++.h>
using namespace std;

long long Pow(int X, int N)
{
    
    //Any integer raise to 0 is 1.
    if(N == 0) return 1;

    //An integer raise to 1 is the same integer itself.
    if(N == 1) return X;

    // Recursively calling the Pow() function for
    // X raise to N/2 until and unless N/2 evaluates to 
    // either 0 or 1. 
    long long ans = Pow(X,N/2);

    //if N is odd then along with ans^2 one more times the 
    //integer X will be multiplied. 
    //e.g : 2^5 -> 2^2 -> 2^1 == 2^2 * 2^2 * 2^1 == 2^5.
    if(N & 1) return (ans*ans*X);
    //if N is even then ans*ans will be returned.
    //e.g : 2^4 -> 2^2 -> 2^0 == 2^2 * 2^2 == 2^4.
    else return (ans*ans);

}

int main(){

    int X,N;
    cout<<"Enter the value of X and N respectively : ";
    cin>>X>>N;
    cout<<"Power of X^N is : "<<Pow(X,N)<<endl;

}