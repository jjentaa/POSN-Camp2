#include <bits/stdc++.h>

using namespace std;
double calculate(string post){
    stack<string> st;
    string sth="";
    for(int i=0; i<post.size(); i++){
        if(post[i]!='*' &&  post[i]!='/' && post[i]!='+' && post[i]!='-' && post[i]!=' '){
            sth="";
            st.push(""+post[i]);
        }
        else if(post[i]==' ') continue;
        else{
            double num1, num2;
            num1=stod(st.top());
            st.pop();
            num2=stod(st.top());
            st.pop();
            if(post[i]=='*'){
                st.push(to_string(num1*num2));
            }
            if(post[i]=='/'){
                st.push(to_string(num2/num1));
            }
            if(post[i]=='+'){
                st.push(to_string(num1+num2));
            }
            if(post[i]=='-'){
                st.push(to_string(num2-num1));
            }
        }
    }
    return stod(st.top());
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    //string postf="1 2 * 3 + ";
    //string postf="1 2 + 3 4 / *";
    //string postf="1 2 3 * 4 5 * + * 6 +";
    string postf="1 2 + 3 * 4 5 - 6 / + 7 +";
    cout << calculate(postf);

    return 0;
}