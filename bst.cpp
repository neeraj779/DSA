#include <iostream>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors using initializer list
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *minValueNode(TreeNode *root)
{
    TreeNode *current = root;
    while (current && current->left != nullptr) // we are using && because if current is null then we don't want to check current->left
    {
        current = current->left;
    }
    return current;
}

TreeNode *maxValueNode(TreeNode *root)
{
    TreeNode *current = root;
    while (current && current->right != nullptr) // we are using && because if current is null then we don't want to check current->right
    {
        current = current->right;
    }
    return current;
}

void insertToBst(TreeNode *&root, int data)
{
    if (root == nullptr)
    {
        root = new TreeNode(data);
        return;
    }
    if (data < root->val)
    {
        insertToBst(root->left, data);
    }
    else
    {
        insertToBst(root->right, data);
    }
}

TreeNode *deletionInBst(TreeNode *root, int x)
{
    if (!root)
        return root;

    if (root->val == x)
    {

        // if node is leaf node
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }

        // if node has only one left child
        if (root->left && !root->right)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // if node has only one right child
        if (!root->left && root->right)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }

        // if node has both left and right child
        int minValueFromLeft = minValueNode(root->right)->val; // or we can use maxValueFromRight
        root->val = minValueFromLeft;
        root->right = deletionInBst(root->right, minValueFromLeft);
        return root;
    }

    else if (root->val > x)
    {
        root->left = deletionInBst(root->left, x);
        return root; // this is important to return root here because we are assigning root->left to deletionInBst(root->left, x)
    }
    else
    {
        root->right = deletionInBst(root->right, x);
        return root; // this is important to return root here because we are assigning root->right to deletionInBst(root->right, x)
    }
}

void takeInput(TreeNode *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertToBst(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root); // level 0 comes in queue
    // for printing on new line
    q.push(NULL); // to mark end of level 0

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL)
        { // prev level is completed

            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->val << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    TreeNode *root = nullptr;
    cout << "Enter data to create a BST: ";
    takeInput(root);
    cout << "Level Order Traversal of BST: " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "Enter data to delete from BST: ";
    int x;
    cin >> x;
    deletionInBst(root, x);
    cout << "Level Order Traversal of BST after deletion: " << endl;
    levelOrderTraversal(root);
    cout << endl;
    return 0;
}