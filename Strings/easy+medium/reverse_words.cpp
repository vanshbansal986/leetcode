#include<iostream>
#include<string>
using namespace std;



string removeOuterParentheses(string s){
    int n = s.size();
    string output = "";

    int i = n-1;
    
    while(i>=0){
        while(s[i] == ' '){
            i--;
        }
        int end = i;
        while(s[i] != ' ' && i>=0){
            i--;
        }
        int start = i + 1;

        for(int i = start; i<=end; i++){
            output += s[i];
        }

        output += " ";
    }

    int j = output.size() - 1;
    while(output[j] == ' '){
        output.pop_back();
        j--;
    }
    

    return output;
}

int main(){
    return 0;
}