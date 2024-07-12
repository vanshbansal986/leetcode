#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;



string isAnagram(string s){
    int n = s.size();
    string output = "";

    

    // making a map for every char and its frequency
    unordered_map<char,int> charFreq;
    for(int i = 0; i<n; i++){

        if(charFreq.count( s[i] ) == 0){
            charFreq[ s[i] ] = 1;
        }
        else{
            charFreq[ s[i] ]++;
        }
    }

    // making a map for every freq and the char that have that frequency
    unordered_map<int,unordered_set<char>> freqList;
    
    for(int i=0; i<n; i++){
        int freq_char = charFreq[ s[i] ];
        
        if(freqList.count(freq_char) == 0){
            unordered_set<char> v;
            v.insert( s[i] );
            freqList[freq_char] = v;
        }
        else{
            freqList[freq_char].insert( s[i] );
        }
    }

    // The range of this freqlist is (0 to n),since a char can occur at most 'n' times.
    // So we will traverse from n to 0 and if that freq exists, we will print all the elements corresponding to that freq.

    for(int i=n; i>=0; i--){
        if(freqList.count(i) != 0){
            unordered_set<char> v = freqList[i];
            for (auto it = v.begin(); it != v.end(); ++it) {
                output += *it;
            }
        }
    }

    return output;

}

int main(){
    return 0;
}