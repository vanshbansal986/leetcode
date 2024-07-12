#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;



string isPalindrome(string s){
    int n = s.size();
    string output = "";
    int maxLength = 0;
    
    int i = 0;
    while(i<n){
        int len = 0;

        int low = i;
        int high = i;
        

        if(s[high] == s[i]){
            while(s[high] == s[i]){
                high++;
                len++;
                

                if(high>=n){
                    break;
                }
            }
        }
        if(len > maxLength){
            maxLength = len;
            output = s.substr(i , high);
        }


        high = i+1;
        while(high<n && low>=0){
            if(s[high] == s[low]){
                high++;
                low--;
                len++;
                
                
            }
            else{
                break;
            }
        }

        if(len > maxLength){
            maxLength = len;
            output = s.substr(low+1,high);
        }

    }
    i++;
    return output;
    
}

int main(){
    return 0;
}