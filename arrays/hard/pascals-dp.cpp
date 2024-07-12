// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

void helper(vector<vector<int>> &output ,vector<int> dp, int n){
    vector<int> mini(n);
    if(n<0){
        return;
    }

    if(n==1){
        mini[0] = 1;
        mini[1] = 1;
        output.push_back(mini);
        return;
    }
    if(n==0){
        mini[0] = 1;
        output.push_back(mini);
        return;
    }

    int size = n+1;
    for(int j=1; j<size-1; j++){
        mini[j] = output[n-1][j-1] + output[n-1][j];
    }

    

}

vector<vector<int>> pascals(int numRows){
    int n = numRows;
    vector<vector<int>> output(numRows);
    vector<int> dp(numRows+1);

    helper(output,dp,n);


}

int main(){
    
}

