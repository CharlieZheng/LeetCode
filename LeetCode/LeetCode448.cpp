using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class LeetCode448 {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<int> result;
		for (int i = 0; i < nums.size(); i++) {
			if (i == 0) {
				for (int j = 1; j < nums[i]; j++) {
					result.push_back(j);
				}
			}
			if ((i + 1) < nums.size()) {
				if (nums[i + 1] - nums[i] > 1) {
					for (int j = 1; j < nums[i + 1] - nums[i]; j++) {
						result.push_back(nums[i] + j);
					}
				}
			}
			else if (i == nums.size() - 1) {
				for (int j = 1; j <= nums.size() - nums[i]; j++) {
					result.push_back(nums[i] + j);
				}
			}

		}
		return result;
	}
};
int main() {
	vector<int> array;
	array.push_back(27);
	array.push_back(40);
	array.push_back(6);
	array.push_back(21);
	array.push_back(14);
	array.push_back(36);
	array.push_back(10);
	array.push_back(19);
	array.push_back(44);
	array.push_back(10);
	array.push_back(41);
	array.push_back(26);
	array.push_back(39);
	array.push_back(20);
	array.push_back(25);
	array.push_back(19);
	array.push_back(14);
	array.push_back(7);
	array.push_back(29);
	array.push_back(27);
	array.push_back(40);
	array.push_back(38);
	array.push_back(11);
	array.push_back(44);
	array.push_back(4);
	array.push_back(6);
	array.push_back(48);
	array.push_back(39);
	array.push_back(9);
	array.push_back(13);
	array.push_back(7);
	array.push_back(45);
	array.push_back(41);
	array.push_back(23);
	array.push_back(31);
	array.push_back(8);
	array.push_back(24);
	array.push_back(1);
	array.push_back(3);
	array.push_back(5);
	array.push_back(28);
	array.push_back(11);
	array.push_back(49);
	array.push_back(29);
	array.push_back(18);
	array.push_back(4);
	array.push_back(38);
	array.push_back(32);
	array.push_back(24);
	array.push_back(15);
	//[27, 40, 6, 21, 14, 36, 10, 19, 44, 10, 41, 26, 39, 20, 25, 19, 14, 7, 29, 27, 40, 38, 11, 44, 4, 6, 48, 39, 9, 13, 7, 45, 41, 23, 31, 8, 24, 1, 3, 5, 28, 11, 49, 29, 18, 4, 38, 32, 24, 15]
	LeetCode448 leetCode448;
	vector<int> result = leetCode448.findDisappearedNumbers(array);
	vector<int>::iterator it;
	for (it = result.begin(); it != result.end(); it++) {
		cout << *it << ", ";
	}
	system("PAUSE");
	return 0;
}