#include <bits/stdc++.h>
using namespace std;

    vector<vector<int>> ans;

    

    vector<int> temp;

    void solve(int k,int n,int order){

        

        if(n==0 && k==0){

            ans.push_back(temp);

            return;

        }

         

        if(n<0) return;

         

        for(int i=order;i<=9;i++){

            

            temp.push_back(i);

            

            solve(k-1,n-i,i+1);

             

            temp.pop_back();

        }

    }

    vector<vector<int>> combinationSum3(int k, int n) {

        solve(k,n,1);

        return ans;

 

    }
int main(){
    int k,n;
    cin>>k>>n;
    
    vector<vector<int>> an=combinationSum3(k,n);
    for(auto &arr: ans){
        for(auto it:arr){
            cout<<it<<" ";
        }
        cout<<endl;
        
    }
    
}
