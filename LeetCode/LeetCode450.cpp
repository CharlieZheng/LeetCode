#include <iostream>
#include <vector>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    void change(TreeNode *parent, TreeNode *node)
    {
        TreeNode *root = parent;
        bool mLeft = false;
        while (node->left != NULL)
        {
            mLeft = true;
            parent = node;
            node = node->left;
        }
        if (node->right != NULL)
        {
            if (mLeft)
            {
                parent->left = node->right;
                root->val = node->val;
                node->right = NULL;
                node = NULL;
            }
            else
            {
                parent->right = node->right;
                root->val = node->val;
                node->right = NULL;
                node = NULL;
            }
        }
        else
        {
            parent->right = NULL;
            root->val = node->val;
            node->right = NULL;
            node = NULL;
        }
    }
    void print(TreeNode *root)
    {
        if (root->left != NULL)
        {
            print(root->left);
        }
        std::cout << root->val << ", ";
        if (root->right != NULL)
        {
            print(root->right);
        }
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (key == root->val)
            return NULL;
        vector<TreeNode *> list;
        vector<bool> leftList;
        vector<TreeNode *> parentList;
        list.push_back(root);
        leftList.push_back(false);
        parentList.push_back(NULL);
        while (!list.empty())
        {
            TreeNode *node = list.back();
            bool left = leftList.back();
            TreeNode *parent = parentList.back();
            list.pop_back();
            leftList.pop_back();
            parentList.pop_back();
            if (node->left != NULL)
            {
                list.push_back(node->left);
                leftList.push_back(true);
                parentList.push_back(node);
            }
            if (node->right != NULL)
            {
                list.push_back(node->right);
                leftList.push_back(false);
                parentList.push_back(node);
            }
            if (key == node->val)
            {
                // 双子节点
                if (node->left != NULL && node->right != NULL)
                {
                    change(node, node->right);
                    return root;
                    // 单子节点
                }
                else if (node->left != NULL && node->right == NULL)
                {
                    if (parent == NULL)
                        return node->left;
                    else if (left)
                    {
                        parent->left = node->left;
                        node->left = NULL;
                        return root;
                    }
                    else
                    {
                        parent->right = node->left;
                        node->left = NULL;
                        return root;
                    }
                }
                else if (node->left == NULL && node->right != NULL)
                {
                    if (parent == NULL)
                        return node->right;
                    else if (left)
                    {
                        parent->left = node->right;
                        node->right = NULL;
                        return root;
                    }
                    else
                    {
                        parent->right = node->right;
                        node->right = NULL;
                        return root;
                    }
                }
                // 叶子节点
                else if (left)
                {
                    if (parent == NULL)
                        return NULL;
                    parent->left = NULL;
                }
                else
                {
                    if (parent == NULL)
                        return NULL;
                    parent->right = NULL;
                }
                return root;
            }
        }
    }

    int test()
    {

        TreeNode *t_2 = new TreeNode(2, NULL, NULL);
        TreeNode *t_4 = new TreeNode(4, NULL, NULL);
        TreeNode *t_7 = new TreeNode(7, NULL, NULL);
        TreeNode *t_3 = new TreeNode(3, t_2, t_4);
        TreeNode *t_6 = new TreeNode(6, NULL, t_7);
        TreeNode *t_5 = new TreeNode(5, t_3, t_6);
        print(t_5);
        std::cout << '\n';
        TreeNode *result = deleteNode(t_5, 3);
        print(result);
        std::cout << '\n';
        system("echo  \"任意键退出\" && read");
        return 0;
    }
};