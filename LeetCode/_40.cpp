#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class _40 {
private:
    void p(vector<vector<int>>& list, vector<int>& candidates, int target, vector<int>& cur, int curIndex) {
        if (!cur.empty()) {
            int sum = 0;
            for (int i = 0; i < cur.size(); i++) {
                sum += cur[i];
            }
            if (sum > target) return;
            if (sum == target) {
                list.push_back(cur);
                return;
            }
        }
        for (int i = curIndex; i < candidates.size(); i++) {
            if (i > curIndex && candidates[i] == candidates[i - 1]) continue;
            vector<int> newCur = vector<int>(cur);
            newCur.push_back(candidates[i]);
            p(list, candidates, target, newCur, i + 1);
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        p(result, candidates, target, cur, 0);
        return result;
    }
    void test() {
        vector<int> candidates;
        candidates.push_back(10);
        candidates.push_back(1);
        candidates.push_back(2);
        candidates.push_back(7);
        candidates.push_back(6);
        candidates.push_back(1);
        candidates.push_back(5);
        int target = 8;
        vector<vector<int>> list = combinationSum2(candidates, target);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list[i].size(); j++) {
                cout << list[i][j] << ", ";
            }
            cout << endl;
        }
    }
};
