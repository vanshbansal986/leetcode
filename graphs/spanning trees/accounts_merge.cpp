#include <iostream>
#include <queue>
#include<vector>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;
#include "disjoint_rank.cpp"


vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    int n = accounts.size();
    vector<vector<string>> output(10);
    vector<vector<int>> accounts_int;

    unordered_map<int,string> m;
    int name_count = 0;

    for(int i=0; i<accounts.size(); i++){
        m[name_count] = accounts[i][0];
        name_count++;
    }

    int email_count = name_count;
    name_count = 0;


    unordered_map<string,int> email_map;
    for(int i=0; i<accounts.size(); i++){
        vector<int> mini;
        mini.push_back(name_count);
        name_count++;

        for(int j=1; j < accounts[i].size(); j++){
            string email = accounts[i][j];
            if(email_map.count(email) == 0){
                email_map[email] = email_count;
                email_count++;
            }
            
            mini.push_back(email_map[email]);
            
        }

        accounts_int.push_back(mini);
    }


    

    disjointSet ds(email_count-1);

    unordered_map<string,int> name_map;

    

    for(int i=0; i<n; i++){
        vector<string> mini;
        string name = accounts[i][0];
        int curr_node = i;
        mini.push_back(name);
        
        int final_push = 0;

        for(int j=1; j<accounts_int[i].size(); j++){
            
            string email = accounts[i][j];
            
            int adj_node = accounts_int[i][j];

            if(ds.findUltParent(curr_node) != ds.findUltParent(adj_node)){
                
                if(ds.findUltParent(adj_node) == adj_node){
                    mini.push_back(email);
                    ds.unionByRank(curr_node,adj_node);
                }
                else{
                    final_push = 1;
                    int ult_parent = ds.findUltParent(adj_node);
                    for(int s=1; s<accounts[i].size(); s++){
                        string adj_email = accounts[i][s];
                        output[ult_parent].push_back(adj_email);
                        ds.unionByRank(ult_parent , accounts_int[i][s]);
                    }
                }
            }
        }
        if(final_push == 0){
            output.push_back(mini);
        }

    }

    return output;


}