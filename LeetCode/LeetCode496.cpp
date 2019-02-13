using namespace std;
#include <vector>
#include <iostream>
class LeetCode496 {
public:
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
		vector<int>::iterator it1;
		vector<int>::iterator it2;
		vector<int> result;
		for (it1 = findNums.begin(); it1 != findNums.end(); it1++) {
			bool found = false;
			bool add = false;
			for (it2 = nums.begin(); it2 != nums.end(); it2++) {
				if (found && *it2 > *it1) {
					result.push_back(*it2);
					add = true;
					break;
				}
				if (*it1 == *it2) {
					found = true;
				}


			}
			if (found && !add) {
				result.push_back(-1);
			}
		}
		vector<int>::iterator it3;
		for (it3 = result.begin(); it3 != result.end(); it3++) {
			cout << *it3 << endl;
		}
		return result;
	}
};