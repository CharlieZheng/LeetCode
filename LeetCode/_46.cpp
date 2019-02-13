#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class _46 {
private:
    void p(vector<vector<int>>& result, vector<int>& nums, vector<int>& cur, vector<bool>& added) {
        if (cur.size() >= nums.size()) {
            result.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (added[i]) continue;
            vector<int> newCur = vector<int>(cur);
            vector<bool> newAdded = vector<bool>(added);
            newCur.push_back(nums[i]);
            newAdded[i] = true;
            p(result, nums, newCur, newAdded);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> cur;
        vector<bool> added(nums.size(), false);
        p(result, nums, cur, added);
        return result;
    }

    void test() {
        vector<int> candidates;
        candidates.push_back(1);
        candidates.push_back(2);
        candidates.push_back(3);
        vector<vector<int>> list = permute(candidates);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list[i].size(); j++) {
                cout << list[i][j] << ", ";
            }
            cout << endl;
        }
    }
};
