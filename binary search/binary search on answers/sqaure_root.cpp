#include<iostream>
#include<vector>
#include <cmath>
using namespace std;



int helper(int n , int start , int end){
    
    if(start > end){
        return start;
    }

    int mid = start + (end - start)/2;
    
    int sqaure = mid * mid;

    if(sqaure < n){
        return helper(n , mid+1 , end);
    }
    else if(sqaure > n){
        return helper(n , start , mid-1);
    }
    else{
        return mid;
    }
    
}

int binary_search(int n){

    if(n==1){
        return 1;
    }
    
    int low = 1;
    int high = n/2;


    return helper(n,low,high);


}


int main(){
    // shipWithinDays
    return 0;
}