
#include <bits/stdc++.h>
using namespace std;
int eval(vector<string>& tokens)
{
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/"
            && tokens[i] != "*") {
            st.push(stoi(tokens[i]));
            continue;
        }
        else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (tokens[i] == "+")
                st.push(a + b);
            else if (tokens[i] == "-")
                st.push(a - b);
            else if (tokens[i] == "*")
                st.push(a * b);
            else
                st.push(a / b);
        }
    }
    return st.top();
}
int main(){
    int n;
    cin>>n;
    vector<string>tokens(n);

    for(int j=0;j<tokens.size();j++){
        cin>>tokens[j];
    }
    int res= eval(tokens);
    cout<<res<<endl;

    

}