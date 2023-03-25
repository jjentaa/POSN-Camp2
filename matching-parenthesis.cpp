#include <bits/stdc++.h>

using namespace std;

int solve(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
        else if(s[i]==')' && st.top()==')') st.pop();
        else if(s[i]==']' && st.top()==']') st.pop();
        else if(s[i]=='}' && st.top()=='}') st.pop();
        else return 0;
    }
    if(st.empty()) return 1;
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    // string ex="5+)]-3";
    // string ex="8+(5-7)";
    string ex="[(3+2]*[5-4]]";
    if(solve(ex)){
        cout << ex << " is balanced";
    }
    else cout << ex << " is not balance";

    return 0;
}