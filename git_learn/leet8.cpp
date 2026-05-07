#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
	vector<int> res;
	if (s.size() < p.size()) return res;
	vector<int> cnt_p(26, 0), cnt_s(26, 0);
	for (char c : p) cnt_p[c - 'a']++;
	for (int i = 0; i < p.size(); ++i) cnt_s[s[i] - 'a']++;
	if (cnt_s == cnt_p) res.push_back(0);
	for (int i = p.size(); i < s.size(); ++i) {
		cnt_s[s[i] - 'a']++;
		cnt_s[s[i - p.size()] - 'a']--;
		if (cnt_s == cnt_p) res.push_back(i - p.size() + 1);
	}
	return res;
}

int main() {
	string s, p;
	cout << "请输入原字符串s：";
	cin >> s;
	cout << "请输入目标字符串p：";
	cin >> p;
	vector<int> res = findAnagrams(s, p);
	cout << "所有异位词的起始索引：";
	for (int idx : res) {
		cout << idx << " ";
	}
	cout << endl;
	return 0;
}