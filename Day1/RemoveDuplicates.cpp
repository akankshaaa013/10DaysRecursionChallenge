#include<bits/stdc++.h>
using namespace std;

void removeDuplicateFromString(string &s,string &ans,unsigned int i){

    //To Terminate the recursive call once the value of i
    //is equal to the length of the string.
    if(i==s.length()) return;

    //if the current character is equal to next character then 
    //calling the function again for next character else 
    //pushing the current character in an empty string & then
    //calling the function again.
    if(s[i]==s[i+1]){
        removeDuplicateFromString(s,ans,i+1);
    }
    else{
        ans.push_back(s[i]);
        removeDuplicateFromString(s,ans,i+1);
    }

}

int main()
{
    //Initializing an empty string to Store the final answer.
    string ans_String="";

    string s;
    cout<<"Enter the String : ";
    cin>>s;
    unsigned int i = 0;
    
    removeDuplicateFromString(s,ans_String,i);

    cout<<endl<<ans_String<<endl;
}
