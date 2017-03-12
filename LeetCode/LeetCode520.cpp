using namespace std;
#include <vector>
#include <string>
#include <iostream>
class LeetCode500 {
public:
	bool detectCapitalUse(string word) {
		int smallNum = 0, bigNum = 0;
		for (unsigned int i = 0; i < word.length(); i++) {
			char item = word[i];
			if (i == 0) {
				if (item <= 90) {
					continue;
				}
				else {
					break;
				}
			}
			if (i > 0 && item > 90) {
				smallNum++;
			}
			if (i > 0 && item <= 90) {
				bigNum++;
			}
		}
		if (smallNum == word.length() - 1 || bigNum == word.length() - 1) {
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main() {
	LeetCode500 leetCode520;
	cout << leetCode520.detectCapitalUse("leetcode") << endl;
	system("PAUSE");
	return 0;
}