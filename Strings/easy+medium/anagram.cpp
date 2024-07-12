#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

bool check(vector<string>& s , int i){
    
}

bool isAnagram(string s , string t){
    string output = s + t;
    int n = output.length();
    char c;
    for(int i=0; i<n; i++){
        c = c ^ output[i];
    }
    
    cout<<c<<endl;
    return true;
}

int main(){
    return 0;
}