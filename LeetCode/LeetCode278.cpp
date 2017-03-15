using namespace std;
#include <vector>
#include <string>
#include <iostream>
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

bool isBadVersion(int version) {
	return version > 2;
}
class LeetCode278 {
public:
	int firstBadVersion(int n) {
		int left = 0;
		int right = n;
		int center = left + (right - left) / 2;
		if (center == 0) {
			return 1;
		}
		bool b;
		while ((b = isBadVersion(center)) == isBadVersion(center - 1)) {
			if (b) {
				right = center;
				center = left + (center - left) / 2;
			}
			else {
				left = center;
				center = center + (right - center) / 2;
			}
			if (right - left == 1) {
				return (!isBadVersion(left) && isBadVersion(right)) ? right : -1;
			}
		}
		return center;
	}
};
//int main() {
//	LeetCode278 leetCode278;
//	cout << leetCode278.firstBadVersion(4) << endl;
//	system("PAUSE");
//	return 0;
//}