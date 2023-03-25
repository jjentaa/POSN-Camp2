#include <bits/stdc++.h>

using namespace std;

struct MBTI{
    double ne, ni, te, ti, se, si, fe, fi;
    string name, label;
};
vector<pair<double, MBTI>> vec;

void bruteforce(MBTI target, MBTI mbti[15]){

    for(int i=0; i<15; i++){
        double dis=0;
        dis+=(mbti[i].ne-target.ne)*(mbti[i].ne-target.ne)+(mbti[i].ni-target.ni)*(mbti[i].ni-target.ni);
        dis+=(mbti[i].te-target.te)*(mbti[i].te-target.te)+(mbti[i].ti-target.ti)*(mbti[i].ti-target.ti);
        dis+=(mbti[i].se-target.se)*(mbti[i].se-target.se)+(mbti[i].si-target.si)*(mbti[i].si-target.si);
        dis+=(mbti[i].fe-target.fe)*(mbti[i].fe-target.fe)+(mbti[i].fi-target.fi)*(mbti[i].fi-target.fi);
        dis=sqrt(dis);
        vec.push_back({dis, mbti[i]});
    }
}

int partition(int low, int high)
{
    int pivot = vec[high].first;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (vec[j].first < pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quicksort( int low, int high, int k)
{
    if (low < high) {
        int pi = partition(low, high);
        if (pi >= k) {
            quicksort(low, pi - 1, k);
        } else {
            quicksort(low, pi - 1, k);
            quicksort(pi + 1, high, k);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    MBTI mbti[15]={
        {35.4, 31, 33, 30, 38, 31, 34, 31, "Kuuga", "ENTP"},
        {26, 31, 33, 30, 26, 33, 30, 24, "Agito", "INTJ"},
        {24.4, 30.2, 31, 34, 28, 36, 22, 17, "Ryuki", "ISTJ"},
        {22.2, 25.8, 36, 37, 29, 36, 34, 22, "Blade", "ENTJ"},
        {43.2, 34, 36, 36, 39, 38, 40, 35, "Hibiki", "INTP"},
        {32.4, 27, 35, 34, 27, 23, 31, 19, "Kabuto", "ENFP"},
        {28.4, 25.6, 33, 35, 32, 30, 24, 26, "Den-O", "ESTP"},
        {30.2, 31.4, 35, 33, 36, 33, 36, 34, "Kiva", "ENTJ"},
        {19.4, 12, 25, 28, 25, 23, 23, 22, "Decade", "ESTJ"},
        {33.4, 38.6, 29, 29, 26, 37, 24, 25, "Fouze", "INTJ"},
        {30, 29.6, 34, 32, 38, 28, 33, 22, "Gaim", "ENTP"},
        {29, 22.8, 40, 28, 27, 31, 29, 19, "Ex-Aid", "ENTJ"},
        {25.5, 33, 28, 34, 37, 27, 28, 24, "Zi-o", "INFJ"},
        {29.8, 26.4, 28, 36, 29, 30, 33, 28, "Saber", "INTJ"},
        {18.4, 15, 30, 33, 33, 31, 26, 23, "Revice", "ESTJ"}
    };
    MBTI target={32, 32, 27, 36, 29, 31, 28, 23, "Query", "UNKNOWN"};
    bruteforce(target, mbti);
    int n=15;
    int k=5;
    quicksort(0, n - 1, k);

    cout << vec[0].second.label << "\n";
    for(int u=0; u<5 ; u++){
        cout << vec[u].first << " " << vec[u].second.name << " " << vec[u].second.label << "\n";
    }

    return 0;
}