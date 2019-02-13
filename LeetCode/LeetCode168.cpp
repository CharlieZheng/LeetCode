#include <vector>
#include <string>
#include <iostream>
using namespace std;

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
    int test()
    {
        cout << convertToTitle(26) << endl;
        system("PAUSE");
        return 0;
    }
};
