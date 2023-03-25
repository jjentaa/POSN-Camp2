#include <bits/stdc++.h>

using namespace std;

struct Data{ // A->B->C
    int no;
    int a, b, c;

    bool operator <(const Data &rhs) const{
        if(a!=rhs.a) return a>rhs.a;
        else{
            if(b!=rhs.b) return b>rhs.b;
            else return c>rhs.c;
        }
    }

};

struct Data1{ // B->C->A
    int no;
    int a, b, c;

    bool operator <(const Data1 &rhs) const{
        if(b!=rhs.b) return b>rhs.b;
        else{
            if(c!=rhs.c) return c>rhs.c;
            else return a>rhs.a;
        }
    }

};

priority_queue<Data> pq;
priority_queue<Data1> pq1;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int arr[14][3]={{1, 1, 4}, {3, 1, 1}, {4, 4, 4}, {2, 4, 4}, {3, 5, 3}, {4, 3, 3}, {1, 3, 3}, {2, 4, 3}, {3, 3, 5}, {1, 5, 3}, {1, 1, 4}, {4, 1, 1}, {5, 2, 3}, {3, 5, 2}}; 
    int n=14;
    for(int i=0; i<n; i++){
        pq.push({i+1, arr[i][0], arr[i][1], arr[i][2]});
        pq1.push({i+1, arr[i][0], arr[i][1], arr[i][2]});
    }

    cout << "NO. A B C\n";
    while(!pq.empty()){
        cout << pq.top().no << "  " << pq.top().a << " " << pq.top().b << " " << pq.top().c << "\n";
        pq.pop();
        //cout << pq1.top().no << "  " << pq1.top().a << " " << pq1.top().b << " " << pq1.top().c << "\n";
        //pq1.pop();
    }

    return 0;
}