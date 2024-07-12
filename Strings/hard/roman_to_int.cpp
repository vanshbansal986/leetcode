#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;



int isAnagram(string s){
    int n = s.size();
    int output = 0;

    unordered_map<char,int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int i = 0;
    while(i<n){
        if(m[s[i]] < m[s[i+1]]){
           output -= m[s[i]];
           i++;
        }
        else{
            output += m[s[i]];
            i++;
        }
    }

    return output;

}

int main(){
    return 0;
}