#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class _451
{
private:
    struct TreeNode
    {
        pair<char, int> val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(pair<char, int> x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    // 二叉树堆
    TreeNode *binary_heap;
    void insert(TreeNode **root, pair<char, int> val)
    {
        if (*root == NULL)
        {
            *root = new TreeNode(val, NULL, NULL);
            return;
        }
        if (val.second > (*root)->val.second)
        {
            if ((*root)->right == NULL)
            {
                (*root)->right = new TreeNode(val, NULL, NULL);
                return;
            }
            else
            {
                return insert(&(*root)->right, val);
            }
        }
        else
        {
            return insert(&(*root)->left, val);
        }
    }
    string *read(TreeNode *root, string *last_result)
    {
        if (root == NULL)
            return last_result;
        if (root->right != NULL)
        {
            read(root->right, last_result);
        }
        int count = root->val.second;
        for (int i = 0; i < count; i++)
            *last_result += root->val.first;
        if (root->left != NULL)
        {
            read(root->left, last_result);
        }
        return last_result;
    }

public:
    string frequencySort(string s)
    {
        std::map<char, int>::iterator iter;
        std::map<char, int> count_map;
        for (size_t i = 0; i < s.size(); i++)
        {
            char c = s[i];
            iter = count_map.find(c);
            if (iter == count_map.end())
            {
                count_map.insert(map<char, int>::value_type(c, 1));
            }
            else
            {
                int second = iter->second + 1;
                // insert 操作会被丢弃需先 erase
                count_map.erase(iter);
                count_map.insert(map<char, int>::value_type(c, second));
            }
        }

        for (iter = count_map.begin(); iter != count_map.end(); iter++)
        {

            char key = iter->first;
            int count = iter->second;
            insert(&binary_heap, pair<char, int>(key, count));
        }

        string result = "";
        read(binary_heap, &result);
        return result;
    }
};
