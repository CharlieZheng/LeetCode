using namespace std;
#include <vector>
#include <string>
#include <iostream>
class LeetCode500 {
public:
	bool detectCapitalUse(string word) {
		unsigned int smallNum = 0, bigNum = 0;
		for (unsigned int i = 0; i < word.length(); i++) {
			char item = word[i];
			if (i == 0) {
				if (item <= 90) {
					continue;
				}
			}
			if (item > 90) {
				smallNum++;
			}
			if (item <= 90) {
				bigNum++;
			}
		}
		if ((smallNum >= word.length() - 1 && bigNum == 0) || (bigNum == word.length() - 1 && smallNum == 0)) {
			return true;
		}
		else
		{
			return false;
		}
	}
};
//int main() {
//	LeetCode500 leetCode520;
//	cout << leetCode520.detectCapitalUse("mL") << endl;
//	system("PAUSE");
//	return 0;
//}