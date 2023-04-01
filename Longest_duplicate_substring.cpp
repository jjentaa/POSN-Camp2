#include <bits/stdc++.h>

using namespace std;
string s, ans;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> s;
    unordered_map<char, vector<int>> hash;
    int n = s.size();
        
    for(int i=0; i<n; i++)
        hash[s[i]].push_back(i);
        int Max = 0, index = -1;
        
        for(int i=0; i<n; i++){
            char f = s[i];
            hash[f].erase(hash[f].begin());
            
            for(int it : hash[f]){
                int j = 0;
                while(i+j < n && it+j < n && s[i+j] == s[it+j]) j++;
                if(j > Max){
                    Max = j;
                    index = i;
                }
                if(Max == n-i-1){
                    cout << s.substr(index, Max);
                    return ;
                }
            }
        }
        
        if(Max == 0) cout << "NO";
        
        else cout << s.substr(index, Max);
    return 0;
}
//slicing window