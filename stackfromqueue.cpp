#include <bits/stdc++.h>

using namespace std;
class Stackie{
public:
    queue<int> q1;
    queue<int> q2;
    void pushh(int target){
        if(q1.empty() && q2.empty()) q1.push(target);
        else if(q1.empty()){
            q1.push(target);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
        else{
            q2.push(target);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    void popp(){
        if(q1.empty() && q2.empty()) return ;
        else if(q1.empty()){
            q2.pop();
        }
        else{
            q1.pop();
        }
    }

    void displayy(){
        if(q1.empty() && q2.empty()) return ;
        else if(q1.empty()){
            while(!q2.empty()){
                cout << q2.front() << " ";
                q2.pop();
            }
        }
        else{
            while(!q1.empty()){
                cout << q1.front() << " ";
                q1.pop();
            }
        }
    }

};
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    Stackie st;
    for(int i=1; i<=5; i++) st.pushh(i);
    //st.displayy();
    st.popp();
    st.popp();
    st.displayy();

    return 0;
}