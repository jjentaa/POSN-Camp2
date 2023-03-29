#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int arr[n+1], arr1[n+1];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    for(int i=0; i<n-1; i++){
        int maxx=INT_MAX;
        for(int j=i+1; j<n; j++){
            if(arr[j]>arr[i]){
                maxx=min(maxx, arr[j]);
            }
        }
        if(maxx==INT_MAX){
            cout << -1 << " ";
        }
        else cout << maxx << " ";
    }

    cout << -1;

    return 0;
}