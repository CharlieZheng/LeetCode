using namespace std;
#include <vector>
#include <string>
#include <iostream>

class LeetCode168 {
public:
	string convertToTitle(int n) {
		vector<char> temp;
		char item;
		while (n / 27 > 27) {
			item = n % 27;
			temp.push_back(item);
		}
		vector<char>::iterator it;
		for (it = temp.begin(); it != temp.end(); it++) {

		}
	}
};
int main() {
	LeetCode168 leetCode168;
	cout << leetCode168.convertToTitle(4) << endl;
	system("PAUSE");
	return 0;
}