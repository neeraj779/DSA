class Solution
{
private:
    // Helper function to traverse the right boundary of the tree
    void rightTraverse(Node *root, vector<int> &v)
    {
        // Base case: if the current node is null or it is a leaf node (no children)
        if ((!root) || (!root->left && !root->right))
            return;

        // Recursively traverse the right subtree if it exists, otherwise traverse the left subtree
        if (root->right)
            rightTraverse(root->right, v);
        else
            rightTraverse(root->left, v);

        // Add the value of the current node to the boundary vector
        v.push_back(root->data);
    }

    // Helper function to traverse and collect leaf nodes
    void leafTraverse(Node *root, vector<int> &v)
    {
        // Base case: if the current node is null, return
        if (!root)
            return;

        // If the current node is a leaf node (no children), add its value to the boundary vector
        if (!root->left && !root->right)
        {
            v.push_back(root->data);
            return;
        }

        // Recursively traverse the left and right subtrees
        leafTraverse(root->left, v);
        leafTraverse(root->right, v);
    }

    // Helper function to traverse the left boundary of the tree
    void leftTraverse(Node *root, vector<int> &v)
    {
        // Base case: if the current node is null or it is a leaf node (no children)
        if ((!root) || (!root->left && !root->right))
            return;

        // Add the value of the current node to the boundary vector
        v.push_back(root->data);

        // Recursively traverse the left subtree if it exists, otherwise traverse the right subtree
        if (root->left)
            leftTraverse(root->left, v);
        else
            leftTraverse(root->right, v);
    }

public:
    // Function to find the boundary nodes of a binary tree
    vector<int> boundary(Node *root)
    {
        // Create a vector to store the boundary nodes
        vector<int> v;

        // Add the value of the root node to the boundary vector
        v.push_back(root->data);

        // Traverse the left boundary nodes
        leftTraverse(root->left, v);

        // Traverse and collect the leaf nodes from the left and right subtrees
        leafTraverse(root->left, v);
        leafTraverse(root->right, v);

        // Traverse the right boundary nodes
        rightTraverse(root->right, v);

        // Return the boundary vector
        return v;
    }
};
