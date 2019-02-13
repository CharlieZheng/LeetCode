//
//  _39.cpp
//  LeetCode
//
//  Created by 郑汉荣 on 2019/2/13.
//  Copyright © 2019 郑汉荣. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class _39 {
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
            vector<int> newCur = vector<int>(cur);
            newCur.push_back(candidates[i]);
            p(list, candidates, target, newCur, i);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> cur;
        p(result, candidates, target, cur, 0);
        return result;
    }
    void test() {
        vector<int> candidates;
        candidates.push_back(2);
        candidates.push_back(3);
        candidates.push_back(5);
        //candidates.push_back(7);
        int target = 8;
        vector<vector<int>> list = combinationSum(candidates, target);
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list[i].size(); j++) {
                cout << list[i][j] << ", ";
            }
            cout << endl;
        }
    }
};
