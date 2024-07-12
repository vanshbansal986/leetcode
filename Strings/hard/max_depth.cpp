#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;



int maxDepth(string s){
    int n = s.size();
    int max = 0;
    int mini = 0;

    for(int i=0; i<n; i++){
        if(s[i] == '('){
            mini++;
        }
        else if(s[i] == ')'){
            mini--;
        }
        else{
            if(mini > max){
                max = mini;
            }
        }
    }

    return max;
    

}

int main(){
    return 0;
}