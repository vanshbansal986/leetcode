#include<iostream>
#include<string>
using namespace std;

bool check(string s , int i , int n){
    if(i<n-1){
        if(s[i-1] == ')' && s[i] == ')' && s[i+1] == '('){
            return true;
        } 
    }
    else if(i == n-1){
        if(s[i-1] == ')' && s[i] == ')'){
            return true;
        }
    }
    
    return false;
    
}

string removeOuterParentheses(string s){
    int n = s.size();
    string output = "";

    int i = 0;
    while(i<n){
        if(s[i] == '('){
            i++;
            while(check(s,i,n) == false){
                output += s[i];
                i++;
            }
        }
        i++;
    }

    return output;
}

int main(){
    return 0;
}