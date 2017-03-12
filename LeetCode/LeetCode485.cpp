using namespace std;
#include <vector>
#include <iostream>
class LeetCode485 {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		vector<int> maxVector;
		int max = 0;
		bool zero;
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end(); it++) {
			zero = false;
			if (*it == 0) {
				zero = true;
				maxVector.push_back(max);
				max = 0;
			}
			if (*it == 1 && !zero) {
				max++;
			}
		}
		for (it = maxVector.begin(); it != maxVector.end(); it++) {
			if (max < *it) {
				max = *it;
			}
		}
		return max;
	}
};
//int main() {
//	vector<int> nums;
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(0);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(1);
//	nums.push_back(1);
//	LeetCode485 leetCode485;
//	cout << leetCode485.findMaxConsecutiveOnes(nums) << endl;
//	system("PAUSE");
//	return 0;
//}