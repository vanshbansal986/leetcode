#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;


int helper(string end,vector<string>& wordList, unordered_map<string,int> m, queue<pair<string,int>> pending)
{
    
    int word_size = end.size();
    while(!pending.empty()){

        string curr = pending.front().first;
        int size = pending.front().second;

        pending.pop();

        if(curr == end){
            return size;
        }
        
        for(int i=0; i<word_size; i++){

            for(int j=0; j<26; j++){
                string temp = curr;
                temp[i] =  'a' + j;

                if(m.count(temp) > 0 && m[temp] == -1){
                    m[temp] = 1;
                    pending.push({temp,size+1});
                    
                }
            }
        }

    }   

    return 0;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    
    int n = wordList.size();
    vector<string> output;

    unordered_map<string,int> m;

    for(int i=0; i<n; i++){
        string word = wordList[i];
        m[word] = -1;
    }
    queue<pair<string,int>> pending;
    m[beginWord] = 1;
    pending.push({beginWord,1});
    bool ans = helper(endWord , wordList , m , pending);
    return output.size();
        
}