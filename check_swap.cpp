#include <bits/stdc++.h>

using namespace std;
string s1, s2;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    getline(cin, s1);
    getline(cin, s2);
    // for(int i=0; i<s1.size(); i++) s1[i]=tolower(s1[i]);
    // for(int i=0; i<s2.size(); i++) s2[i]=tolower(s2[i]);
    // if(s1==s2){
    //     cout << "N";
    //     return 0;
    // }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    //cout << s1 << " " << s2;
    if(s1==s2) cout << "Y";
    else cout << "N";

    return 0;
}