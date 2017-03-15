using namespace std;
#include <vector>
#include <string>
#include <iostream>

class LeetCode168 {
public:
	string convertToTitle(int n) {
		vector<int> temp;
		char item;
		while (n / 26 != 0) {
			item = n % 26;
			n = n / 26;
			temp.push_back(item);
		}
		item = n % 26;
		temp.push_back(item);
		vector<int>::reverse_iterator it;
		string result;
		int i = 0;
		for (it = temp.rbegin(); it != temp.rend(); it++) {
			if (*it == 0) {
				result.push_back(num2ABC(26));
			}
			else {
				result.push_back(num2ABC(*it));
			}
		}
		return result;
	}
	char num2ABC(int n) {
		return char(n + 64);
	}
};
//int main() {
//	LeetCode168 leetCode168;
//	cout << leetCode168.convertToTitle(26) << endl;
//	system("PAUSE");
//	return 0;
//}