#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<map>
#include<string>
#include<stack>
using namespace std;
#include "disjoint_rank.cpp"

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n = accounts.size();

    disjointSet ds(n);
    map<string,int> m;

    for(int i=0; i<n; i++){
        string parent_node = accounts[i][0];
        int parent = i;

        for(int j=1; j<accounts[i].size(); j++){
            string email = accounts[i][j];
            if(m.count(email) == 0){
                m[email] = parent;
            }
            else{
                int email_parent = m[email];
                ds.unionByRank(email_parent , parent);
            }
        }
    }

    

    vector<vector<string>> merge_mails(n);
    
    for(auto it = m.begin(); it != m.end(); ++it){
        string email = it->first;
        int p = it->second;
        int ult_p = ds.findUltParent(p);

        merge_mails[ult_p].push_back(email);
    }


    vector<vector<string>> output;
    for(int i=0; i<n; i++){
        if(merge_mails[i].size() != 0){
            sort(merge_mails[i].begin() , merge_mails[i].end());
            
            string name = accounts[i][0];
            vector<string> temp;
            temp.push_back(name);
            for(int j=0; j<merge_mails[i].size(); j++){
                temp.push_back(merge_mails[i][j]);
            }
            output.push_back(temp);   
        }
        else{
            continue;
        }
        
    }

    return output;

}