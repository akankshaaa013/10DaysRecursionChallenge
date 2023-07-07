#include<bits/stdc++.h>
using namespace std;

bool canNinjaWin(string& str) {
    if(str.length() < 2){
        return false;
    }

    //To check in a string if there are consecutive "$$" 's then replace it by ** AND again calling the function
    //recursively for the modified string. If the string is modified once and in "odd" no.s then true is returned else false
    //for even number of modifications.
    for(unsigned int i = 0;i < str.length()-1; i++){
        if(str[i] == '$' && str[i+1] == '$'){

            string ans = str.substr(0,i) + "**" + str.substr(i+2);
            if(!canNinjaWin(ans)){
                return true;
            }
        }
    }
    return false;
}


int main(){

    string s;

    cout<<"Enter the String : ";
    cin>>s;

    if(canNinjaWin(s)) cout<<"Ninja can Win";
    else cout<<"Ninja Cannot Win";

}