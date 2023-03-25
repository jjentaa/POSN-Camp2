#include <bits/stdc++.h>

using namespace std;
void rabinKarp(string pattern, string text){
    int q=29;
    int m=pattern.size(), n=text.size();
    int p=0, t=0, h=1, d=10;
    int i, j;

    for(i=0; i<m-1; i++) 
        h=(h*d)%q;

    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for(i=0; i<=n-m; i++){
        if(p==t){
            for(j=0; j<m; j++){
                if(text[i+j]!=pattern[j]) break;
            }
            if(j==m) 
                cout << "pattern found at " << i+1 << "\n";
        }
        if(i<n-m){
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0) t=t+q;
        }
    }

    
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    string pattern="mad", text="madmmadNess";
    rabinKarp(pattern, text);

    return 0;
}