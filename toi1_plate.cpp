#include<bits/stdc++.h>

using namespace std;
// id, class
unordered_map<int, int> umpp;
// class, id
vector<pair<int,int>> que;
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int n, t; 
    cin >> n >> t;
	int nc, nn;

	while (t--) {
		cin >> nc >> nn; 
		umpp[nn] = nc;
	}

	char cmd; 
    cin >> cmd;
	while (cmd != 'X') {
        //ass
		if (cmd == 'E') {
			cin >> nn;
            // no one in que
			if(que.empty()) que.push_back({umpp[nn], nn});
			else{
				int cnt = 0;
				for (int i = que.size() - 1; i >= 0; i--) {
                    //มีห้องนั้นในแถวแล้ว ใส่ไปหลังแถวห้องนั้น
					if (umpp[nn] == que[i].first) {
						que.insert(que.begin() + i + 1, {umpp[nn], nn});
						cnt++;
						break;
					}
					
				}
                // ไม่มีห้องนั้นเลย
				if(cnt == 0) que.push_back({umpp[nn], nn});
			}
		}
		if (cmd == 'D') {
			if (que.empty()) {
				cout << "empty\n";
			}
			if(!que.empty()){
				cout << que[0].second << '\n';
				que.erase(que.begin());
			}
		}
		//if (cmd == 'X')cout << 0;
		cin >> cmd; 
	}

	cout << 0;
    
	return 0;
}