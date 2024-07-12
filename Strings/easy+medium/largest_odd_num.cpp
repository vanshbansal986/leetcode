#include<iostream>
#include<string>
using namespace std;



string removeOuterParentheses(string s){
    int n = s.size();
    string output = "";

    int i = n-1;
    int end = 0;
    
    while(i>=0){
        int num = s[i] - '0';
        if(num % 2 != 0){
            end = i;
        }
        else{
            i--;
        }

    }

    for(int i=0; i<=end; i++){
        output += s[i];
    }

    return output;
}

int main(){
    return 0;
}