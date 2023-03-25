#include <bits/stdc++.h>

using namespace std;

struct Data{
    int ID;
    string name;
    int age;
    char sex;
    int incomeRange;
    string segment;
};

struct DatabyAge{
    int ID;
    string name;
    int age;
    char sex;
    int incomeRange;
    string segment;

    bool operator < (const DatabyAge &rhs) const{
        return age>rhs.age;
    }

};

struct DatabyIncome{
    int ID;
    string name;
    int age;
    char sex;
    int incomeRange;
    string segment;

    bool operator < (const DatabyIncome &rhs) const{
        return incomeRange>rhs.incomeRange;
    }

};

priority_queue<DatabyAge> pqA;
priority_queue<DatabyIncome> pqI;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    Data dt[5]={
        {1, "Kiva", 58, 'F', 20000, "target"},
        {2, "RYU", 20, 'M', 18000, "nontarget"},
        {3, "Ken", 18, 'M', 30000, "nontarget"},
        {4, "ZIO", 19, 'F', 16000, "nontarget"},
        {5, "Fourze", 40, 'M', 40000, "target"}
    };

    for(int i=0; i<5; i++){
        pqA.push({dt[i].ID, dt[i].name, dt[i].age, dt[i].sex, dt[i].incomeRange, dt[i].segment});
        pqI.push({dt[i].ID, dt[i].name, dt[i].age, dt[i].sex, dt[i].incomeRange, dt[i].segment});
    }
    cout << "Sort by age\n";
    while(!pqA.empty()){
        cout << pqA.top().ID << " " << pqA.top().name << " " << pqA.top().age << " " << pqA.top().sex << " " << pqA.top().incomeRange << " " << pqA.top().segment << "\n";
        pqA.pop();
    }

    cout << "\nSort by income\n";
    while(!pqI.empty()){
        cout << pqI.top().ID << " " << pqI.top().name << " " << pqI.top().age << " " << pqI.top().sex << " " << pqI.top().incomeRange << " " << pqI.top().segment << "\n";
        pqI.pop();
    }
    cout << "\n\n";

    for(int i=0; i<5; i++){
        pqA.push({dt[i].ID, dt[i].name, dt[i].age, dt[i].sex, dt[i].incomeRange, dt[i].segment});
        pqI.push({dt[i].ID, dt[i].name, dt[i].age, dt[i].sex, dt[i].incomeRange, dt[i].segment});
    }

    pqA.push({6, "Gaim", 22, 'F', 25000, "target"});
    pqI.push({6, "Gaim", 22, 'F', 25000, "target"});

    cout << "Sort by age\n";
    while(!pqA.empty()){
        cout << pqA.top().ID << " " << pqA.top().name << " " << pqA.top().age << " " << pqA.top().sex << " " << pqA.top().incomeRange << " " << pqA.top().segment << "\n";
        pqA.pop();
    }

    cout << "\nSort by income\n";
    while(!pqI.empty()){
        cout << pqI.top().ID << " " << pqI.top().name << " " << pqI.top().age << " " << pqI.top().sex << " " << pqI.top().incomeRange << " " << pqI.top().segment << "\n";
        pqI.pop();
    }

    return 0;
}