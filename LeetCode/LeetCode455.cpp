using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
class LeetCode455 {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		vector<int>::iterator git, sit;
		bool found = false;
		int result = 0;
		for (git = g.begin(); git != g.end(); git++) {
			for (sit = s.begin(); sit != s.end(); sit++) {
				if (*sit >= *git) {
					found = true;
					s.erase(sit);
					break;
				}
			}
			if (found) {
				found = false;
				result++;
			}
		}
		return result;
	}
};
//int main() {
//	LeetCode455 leetCode455;
//	vector<int> g, s;
//	g.push_back(1);
//	g.push_back(2);
//	g.push_back(3);
//	s.push_back(1);
//	s.push_back(2);
//	s.push_back(3);
//	cout << leetCode455.findContentChildren(g, s) << endl;
//	system("PAUSE");
//	return 0;
//}