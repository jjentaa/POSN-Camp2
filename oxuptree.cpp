#include <bits/stdc++.h>

using namespace std;

struct Data{
    vector<int> now;
    vector<vector<int>> past;
};

int checkResult(vector<int> t){
    if((t[0]==t[1]&&t[1]==t[2]&&t[1]==1) || (t[3]==t[4]&&t[4]==t[5]&&t[4]==1) || (t[6]==t[7]&&t[7]==t[8]&&t[8]==1)) return 1;
    if((t[0]==t[1]&&t[1]==t[2]&&t[1]==-1) || (t[3]==t[4]&&t[4]==t[5]&&t[5]==-1) || (t[6]==t[7]&&t[7]==t[8]&&t[8]==-1)) return -1;
    if((t[0]==t[3]&&t[6]==t[3]&&t[6]==1) || (t[1]==t[4]&&t[4]==t[7]&&t[7]==1) || (t[2]==t[5]&&t[5]==t[8]&&t[8]==1)) return 1;
    if((t[0]==t[3]&&t[6]==t[3]&&t[6]==-1) || (t[1]==t[4]&&t[4]==t[7]&&t[7]==-1) || (t[2]==t[5]&&t[5]==t[8]&&t[8]==-1)) return -1;
    if((t[0]==t[4]&&t[4]==t[8]&&t[4]==1) || (t[2]==t[4]&&t[4]==t[6]&&t[4]==1)) return 1;
    if((t[0]==t[4]&&t[4]==t[8]&&t[4]==-1) || (t[2]==t[4]&&t[4]==t[6]&&t[4]==-1)) return -1;
    if(t[0]!=0 && t[1]!=0 && t[2]!=0 && t[3]!=0 && t[4]!=0 && t[5]!=0 && t[6]!=0 && t[7]!=0 && t[8]!=0) return 2;
    return 0;
}

void display(vector<vector<int>> t){
    for(int i=1; i<t.size(); i++){
        for(int j=0; j<3; j++){
            if(t[i][j]==1) cout << "X";
            else if(t[i][j]==-1) cout << "O";
            else cout << "_";
        }
        cout << " | ";
    }
    cout << "\n";

    for(int i=1; i<t.size(); i++){
        for(int j=3; j<6; j++){
            if(t[i][j]==1) cout << "X";
            else if(t[i][j]==-1) cout << "O";
            else cout << "_";
        }
        cout << " | ";
    }
    cout << "\n";

    for(int i=1; i<t.size(); i++){
        for(int j=6; j<9; j++){
            if(t[i][j]==1) cout << "X";
            else if(t[i][j]==-1) cout << "O";
            else cout << "_";
        }
        cout << " | ";
    }
    cout << "\n";
}

queue<Data> q;
int ans;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    vector<vector<int>> v;
    vector<int> t0{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i<9; i++){
        vector<int> t1=t0;
        Data dt;
        t1[i]=1;
        t1[9]=1;
        dt.now=t1;
        dt.past.push_back(t0);
        q.push(dt);
    }

    while(!q.empty()){
        Data dta=q.front();
        q.pop();

        int result=checkResult(dta.now);
        if(result!=0){
            ans++;
            //cout << ans << "\n";
            cout << "\n" << ans << " ";
            if(result==1) cout << "X win" << "\n";
            else if(result==-1) cout << "O win" << "\n";
            else cout << "TIE" << "\n";
            vector<vector<int>> result=dta.past;
            result.push_back(dta.now);
            display(result);
            continue;
        }

        for(int i=0; i<9; i++){
            vector<int> next=dta.now;
            Data dtt;
            if(next[i]!=0) continue;
            if(next[9]%2) next[i]=-1;
            else next[i]=1;
            next[9]+=1;
            dtt.now=next;
            dtt.past=dta.past;
            dtt.past.push_back(dta.now);
            q.push(dtt);
        }
    }

    //cout << ans;

    return 0;
}