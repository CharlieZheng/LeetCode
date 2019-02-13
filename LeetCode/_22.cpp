#include <iostream>
#include <vector>

using namespace std;

class _22 {
private:
    void generateParenthesisHelper(vector<string> &result, int leftNum, int rightNum, string item, int n) {
        if (rightNum == n) {
            result.push_back(item);
            return;
        }
        if (leftNum < n) generateParenthesisHelper(result, leftNum + 1, rightNum, item + "(", n);
        if (rightNum < leftNum) generateParenthesisHelper(result, leftNum, rightNum + 1, item + ")", n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(result, 0, 0, "", n);
        return result;
    }
    void test()
    {
        vector<string> array = generateParenthesis(1);
        for (int i = 0; i < array.size(); i++) {
            cout<< array[i] << endl;
        }
        /*
         num: 1
         ()
         num: 2
         (->()->()(
         (->()->()(->()(())
         (->()->()(->()()()
         (->((->((()))
         (->((->(()
         (->((->(()->(()())
         (->((->(()->(())()
         */
    }
};
