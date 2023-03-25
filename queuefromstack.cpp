#include <bits/stdc++.h>

using namespace std;

class Que{
public:
    stack<int> st1, st2;
    
    void pushh(int target){
        if(st1.empty() && st2.empty()) st1.push(target);
        else if(st1.empty()){
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
            st2.push(target);
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(target);
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
    }

    void popp(){
        if(st1.empty() && st2.empty()) return ;
        else if(st1.empty()) st2.pop();
        else st1.pop();
    }

    void display(){
        if(st1.empty() && st2.empty()) return ;
        else if(st1.empty()){
            while(!st2.empty()){
                cout << st2.top() << " ";
                st2.pop();
            }
        }
        else{
            while(!st1.empty()){
                cout << st1.top() << " ";
                st1.pop();
            }
        }
    }

};

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    Que q;
    for(int i=1; i<=5; i++) q.pushh(i);
    q.popp();
    q.popp();
    q.display();

    return 0;
}