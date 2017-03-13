using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
class LeetCode389 {
public:
	char findTheDifference(string s, string t) {
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		for (unsigned int i = 0; i < t.length(); i++) {
			if (i == t.length() - 1) {
				return t[i];
			}
			if (s[i] != t[i]) {
				return t[i];
			}
		}

	}
};
//int main() {
//	LeetCode389 leetCode389;
//	cout << leetCode389.findTheDifference("ae", "aea") << endl;
//	system("PAUSE");
//	return 0;
//}