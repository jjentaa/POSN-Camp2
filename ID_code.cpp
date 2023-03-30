#include <bits/stdc++.h>

using namespace std;
string seq, ans, final;
char arr[8];
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> seq;
    int n=seq.size();
    for(int i=1; i<=n+1; i++) arr[i-1]=i+48;

    do {
        string sth="";
        for(int i=0; i<n+1; i++) sth+=arr[i];
        //cout << sth << "\n";

        int isCheck=1;
        for(int i=0; i<n; i++){
            if(seq[i]=='I' && sth[i]>sth[i+1]){
                isCheck=0;
                break;
            }
            if(seq[i]=='D' && sth[i]<sth[i+1]){
                isCheck=0;
                break;
            }
        }

        // //if(isCheck==1) cout << sth << " " << isCheck << "\n";

        if(isCheck){
            cout << sth;
            return 0;
        }

    } while (next_permutation(arr, arr+n+1));

    return 0;
}