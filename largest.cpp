#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> computeSubsets(vector<int> &arr){
    vector<vector<int>> subsets;
    
    int N= arr.size();
    for(int i=0; i<(1<<N); ++i){
        vector<int> v; 
        int j = 0; 
        while((1<<j)<=i){    
            if(((1<<j)&i)>0){ 
                v.push_back(arr[j]); 
            }
            j++;      
        }
        if(v.size()>0)      
            subsets.push_back(v); 
    }
    
    return subsets;
}
 
bool isDivisibleSubset(vector<int> arr){
    sort(arr.begin(), arr.end());  
    for(int i=arr.size()-1;i>=1;--i){ 
        if(arr[i]%arr[i-1]!=0){
            return 0;   
        }
    }
    return 1; 
}

vector<int> LargestDivisibleSubset(vector<int> &arr){
    vector<vector<int>> Subsets = computeSubsets(arr);  
    vector<int> largest_subset; 
    for(vector<int> subset : Subsets){  
        
        if(isDivisibleSubset(subset) and largest_subset.size() < subset.size()){
            largest_subset = subset; 
        }
    }
    return largest_subset;  
}
int main() {
    int n;
    cin>>n;
    vector<int> arr[n]; 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> LargestSubset = LargestDivisibleSubset(arr);  
    
    for(int j:LargestSubset){
        cout<<j<<" ";
    }
    return 0;
}