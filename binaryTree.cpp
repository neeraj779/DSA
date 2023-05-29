/**
 * This is a C++ program that implements various tree traversal algorithms such as level order
 * traversal, reverse level order traversal, in-order traversal, pre-order traversal, and post-order
 * traversal.
 * 
 * @param root A pointer to the root node of a binary tree.
 * 
 * @return The main function is not returning anything. It has a return statement at the end, but it is
 * not returning any value. It is just returning 0 to indicate successful execution of the program.
 */
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data: ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter left child of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter right child of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void buildTreeFromLevelOrder(Node *&root)
{
    queue<Node *> q;
    cout << "Enter root data: ";
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left child of " << temp->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            temp->left = new Node(leftChildData);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            temp->right = new Node(rightChildData);
            q.push(temp->right);
        }
    }
}

// also called Breadth First Search
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root); // level 0 comes in queue
    // for printing on new line
    q.push(NULL); // to mark end of level 0

    while (!q.empty())
    {
        Node *temp = q.front();
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
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void reverseLevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    stack<Node *> s;
    q.push(root);

    while (!q.empty())
    {
        Node *currentLevelNode = q.front();
        q.pop();
        s.push(currentLevelNode);

        if (currentLevelNode->right)
        {
            q.push(currentLevelNode->right);
        }

        if (currentLevelNode->left)
        {
            q.push(currentLevelNode->left);
        }
    }

    while (!s.empty())
    {
        Node *topNode = s.top();
        cout << topNode->data << " ";
        s.pop();
    }
}

void inOrderTraversal(Node *root)
{
    if (!root)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (!root)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;
    // root = buildTree(root);
    buildTreeFromLevelOrder(root);

    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);

    // cout << "Reverse Level Order Traversal: " << endl;
    // reverseLevelOrderTraversal(root);

    // cout << "In-Order Traversal: " << endl;
    // inOrderTraversal(root);

    // cout << "Pre-Order Traversal: " << endl;
    // preOrderTraversal(root);

    // cout << "Post-Order Traversal: " << endl;
    // postOrderTraversal(root);
    return 0;
}