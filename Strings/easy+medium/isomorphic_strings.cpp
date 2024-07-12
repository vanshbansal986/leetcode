#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

bool check(vector<string>& s , int i){
    
}

bool longestCommonPrefix(string s , string t){
    unordered_map<char,char> m1;
    unordered_map<char,int> m2;
    
    int n = s.size();

    if(s.size() != t.size()){
        return false;
    }

    for(int i=0; i<n; i++){
        char char_s = s[i];
        char char_t = t[i];

        if(m1.count(s[i]) == 0 && m2.count(t[i]) == 0){
            m1[s[i]] = t[i];
            m2[t[i]] = 1;
        }
        else{
            if(m1[s[i]] != t[i]){
                return false;
            }
        }
    }
    
    return true;
}

int main(){
    return 0;
}