#include <bits/stdc++.h>

using namespace std;
vector<pair<int, pair<char, char>>> vec;
int n;
string str;
bool visitt[100001];
bool isCheck=false;
int counters;

void dfs(int idx, int counter){
    if(counter==n){
        isCheck=true;
        counters++;
        return ;
    }
    visitt[idx]=true;
    for(auto [k, v]: vec){
        if(visitt[k]) continue;
        if(v.first==vec[idx].second.second){
            visitt[k]=true;
            dfs(k, counter+1);
            visitt[k]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        vec.push_back({i, {str[0], str[str.size()-1]}});
    }

    for(int i=0; i<n; i++){
        visitt[i]=true;
        dfs(i, 1);
        visitt[i]=false;
        if(isCheck){
            cout << "The given words can be rearranged";
            return 0;
        }
    }

    cout << "The given words cannot be rearranged";

    return 0;
}