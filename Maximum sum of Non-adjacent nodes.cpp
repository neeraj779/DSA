class Solution
{
private:
    // Helper function to solve the problem recursively
    // Returns a pair of integers:
    // - first: maximum sum including the current node
    // - second: maximum sum excluding the current node
    pair<int, int> solve(Node *node)
    {
        // Base case: empty node
        if (!node)
        {
            // Return a pair of zeros
            return make_pair(0, 0);
        }

        // Recursively solve the left and right subtrees
        pair<int, int> left = solve(node->left);
        pair<int, int> right = solve(node->right);

        // Calculate the maximum sum including the current node
        int max_incl = node->data + left.second + right.second;

        // Calculate the maximum sum excluding the current node
        int max_excl = max(left.first, left.second) + max(right.first, right.second);

        // Return a pair of maximum sums
        return make_pair(max_incl, max_excl);
    }

public:
    int getMaxSum(Node *root)
    {
        pair<int, int> max_sums = solve(root);

        // Return the maximum of the two maximum sums
        return max(max_sums.first, max_sums.second);
    }
};