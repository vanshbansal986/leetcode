#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool check(vector<string>& s , int i){
    int n = s.size();

    char start = ' ';
    if(s[0].size() == 0){
        return false;
    }
    start = s[0][i];
    for(int j=1; j<n; j++){
        
        if(s[j][i] == '\0' || s[j][i] != start){
            return false;
        }
    }

    return true;
}

string longestCommonPrefix(vector<string>& str){
    string output = "";

    if (str.size() == 1){
        return output = str[0];
    }
    
    int i = 0;
    while(true){
        if(check(str , i) == true){
            output += str[0][i];
            i++;
        }
        else{
            break;
        }
    }

    return output;
}

int main(){
    return 0;
}