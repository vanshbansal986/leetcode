#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<unordered_set>
using namespace std;

bool find(vector<string> mini , string temp){
    
}

vector<vector<string>> helper(string end,vector<string>& wordList, unordered_map<string,int> m, queue<pair<pair<string,int>,vector<string>>> pending)
{
    
}

vector<vector<string>> findLadder(string beginWord, string endWord, vector<string>& wordList){
    
    unordered_set<string> st(wordList.begin() , wordList.end());
    
    queue<vector<string>> pending;
    pending.push({beginWord});

    vector<string> usedOnlevel;
    usedOnlevel.push_back(beginWord);
    int lvl = 0;
    vector<vector<string>> ans;

    while(!pending.empty()){
        vector<string> vec = pending.front();
        pending.pop();

        if(vec.size() > lvl){
            lvl++;
            for(auto it: vec){
                st.erase(it);
            }
        }

        string curr = vec.back();
        int word_size = curr.size();
        for(int i=0; i<word_size; i++){
            char orig = curr[i];
            for(int j=0; j<26; j++){
                string temp = curr;
                
                temp[i] =  'a' + j;

                if(st.count(temp) > 0){
                    vec.push_back(temp);
                    pending.push(vec);
                    usedOnlevel.push_back(temp);
                    vec.pop_back();
                    
                }
            }
            curr[i] = orig;
        }

    } 
}