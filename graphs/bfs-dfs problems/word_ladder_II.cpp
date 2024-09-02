#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

bool find(vector<string> mini , string temp){
    for(auto it : mini){
        if(it == temp){
            return true;
        }
    }
    return false;
}

vector<vector<string>> helper(string end,vector<string>& wordList, unordered_map<string,int> m, queue<pair<pair<string,int>,vector<string>>> pending)
{
    vector<vector<string>> output;
    int word_size = end.size();
    while(!pending.empty()){

        string curr = pending.front().first.first;
        int size = pending.front().first.second;
        vector<string> mini = pending.front().second;

        pending.pop();

        if(curr == end){
            output.push_back(mini);
        }
        
        for(int i=0; i<word_size; i++){

            for(int j=0; j<26; j++){
                string temp = curr;
                temp[i] =  'a' + j;

                if(m.count(temp) > 0 && find(mini,temp) == false){
                    mini.push_back(temp);
                    pending.push({{temp,size+1} , mini});
                    
                }
            }
        }

    }   

    return output;
}

vector<vector<string>> findLadder(string beginWord, string endWord, vector<string>& wordList){
    
    int n = wordList.size();
    vector<string> output;

    unordered_map<string,int> m;

    for(int i=0; i<n; i++){
        string word = wordList[i];
        m[word] = -1;
    }

    queue<pair<pair<string,int>,vector<string>>> pending;
    m[beginWord] = 1;
    pending.push({{beginWord,1},{beginWord}});
    
    return helper(endWord , wordList , m , pending);
    //return output.size();
        
}