#include<iostream>
using namespace std;
#include<vector>

int helper(vector<int> arr){
    int maxi = arr[0];
    int n = arr.size();
    int i = 1;
    int k = 2;

    while(i<n){
        int sum = 0;
        
        int k2 = k;
        while(k2 !=0 && i<n){
            if(arr[i] % 2 != 0){
                sum += arr[i];
            }
            i++;
            k2--;
        }

        maxi = max(sum , maxi);
        k = k * 2;
    }

    return maxi;
}

vector<int> vector_input(int n){
    vector<int> input(n);
    
    for(int i=0; i<n; i++){
        cin>>input[i];
    }

    return input;
}

int main(){
    int n;
    cout<<"enter n: "<<endl;
    cin >> n;
    cout<<"enter vector : "<<endl;
    vector<int> arr = vector_input(n);

    cout<<"ans: "<<endl;
    cout<<helper(arr);
    return 0;
}