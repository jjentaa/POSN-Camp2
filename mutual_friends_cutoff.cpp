#include <bits/stdc++.h>

using namespace std;
const int mxN=15;
map<int, string> mpp;
unordered_set<int> adj[mxN+1];
int cutoff=3;

void setIndex(){
    mpp[0]="Ichigo";
    mpp[1]="Den-o";
    mpp[2]="Kiva";
    mpp[3]="Kuuga";
    mpp[4]="Zero-one";
    mpp[5]="Zio";
    mpp[6]="Fourze";
    mpp[7]="Faiz";
    mpp[8]="Kabuto";
    mpp[9]="Agito";
    mpp[10]="Ryuki";
    mpp[11]="Gaim";
    mpp[12]="Saber";
    mpp[13]="Revice";
    mpp[14]="Wizard";
}

void setInit(){
    adj[0]={1, 2, 3, 4, 5, 12};
    adj[1]={5, 6, 7, 8, 10, 0, 2};
    adj[2]={3, 4, 8, 11, 0, 1};
    adj[3]={2, 9, 12, 13, 14, 2, 0};
    adj[4]={5, 0, 10, 11, 2};
    adj[5]={1, 4, 0};
    adj[6]={1, 14, 11};
    adj[7]={1, 8};
    adj[8]={1, 10, 7, 2};
    adj[9]={3};
    adj[10]={14, 1, 8, 4};
    adj[11]={2, 14, 4, 6};
    adj[12]={3, 0};
    adj[13]={3};
    adj[14]={3, 6, 10, 11};
}

int findmutual(int a, int b){
    set<int> ans;
    for(auto it=adj[a].begin(); it!=adj[a].end(); it++){
        if(adj[b].find(*it)!=adj[b].end())ans.emplace(*it);
    }
    return ans.size();

}

void recommend(){
    for(int i=0; i<15; i++){
        set<string> recomf;
        for(int j=0; j<15; j++){
            if(adj[i].find(j)!=adj[i].end()) continue;
            if(j==i) continue;
            for(auto u=adj[j].begin(); u!=adj[j].end(); u++){
                if(*u==i || *u==j) continue;
                int f=findmutual(i, *u);
                if(f>=cutoff) recomf.emplace(mpp[*u]);
                //if(i==2 && *u==5) cout << f;
            }
        }
        cout << "Recommended friend of " << mpp[i] << " : ";
        for(auto it=recomf.begin(); it!=recomf.end(); it++){
            cout << *it << " ";
        } 
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    setIndex();
    setInit();
    recommend();

    return 0;
}