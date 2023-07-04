#include<bits/stdc++.h>
using namespace std;

//The below Function will generate the sequence of 
//Binary strings without any consecutive 1's. It is 
//pushed in the vector opposite to that of lexographical
// order.

//Thus, In the main() function, before returning the vector 
//we sort it.

//Prev string allows me to store the "last character" of the currently
//generating string & so There are "no consecutive" 1's appended 
//to the string.

void GenerateBinaryString(string s,int k,vector<string>& v,string prev){
    
    if(k == 0){
        v.push_back(s);
        return;
    }
    
    if(prev == "0"){
        GenerateBinaryString(s + "1",k-1,v,"1");
    }
        GenerateBinaryString(s + "0",k-1,v,"0");
    
}

int main(){

    int N;
    cout<<"Enter the length of the string : ";
    cin>>N;

    vector<string> v;
    
    GenerateBinaryString("",N,v,"0");

    //Reverse of Lexographically Order.
    // for(auto i : v){
    //     cout<<i<<"   ";
    // }

    cout<<endl;
    
    sort(v.begin(),v.end());

    //Lexographically Order.
    for(auto i : v){
        cout<<i<<"   ";
    }
    
}