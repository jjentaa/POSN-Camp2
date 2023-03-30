#include <bits/stdc++.h>

using namespace std;
int n, minn=INT_MAX, ans=0;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    int arr[n+1];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        minn=min(minn, arr[i]);
    }

    for(int i=0; i<n; i++){
        int j=i+1, counter=0;
        while(arr[j]>=arr[i]){
            counter++;
            j++;
        }
        ans=max(ans, counter*arr[i]);
    }

    cout << max(ans, minn);


    return 0;
}