#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string line;
	getline(cin, line);
	stringstream ss;
	ss << line;
	string s;
	int num_words = 0;
	while(ss >> s) {
		num_words++;
	}
	int n;
	cin >> n;
	string kids[n];
	int used[n];
	int used_cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> kids[i];
		used[i] = 0;
	}
	int last = 0;
	int team = 0;
	vector<string> teams[2];
	while (used_cnt < n) {
		int num_words_cpy = num_words;
		while (1) {
			if (!used[last]) num_words_cpy--;
			if (!num_words_cpy) break;
			last++;
			last %= n;
		}
		//cout << last << endl;
		teams[team].push_back(kids[last]);
		used[last] = 1;
		used_cnt++;
		team ^= 1;
	}
	for (int i = 0; i < 2; i++) {
		cout << teams[i].size() << '\n';
		for (int j = 0; j < teams[i].size(); j++) {
			cout << teams[i][j] << '\n';
		}
	}
	return 0;
}