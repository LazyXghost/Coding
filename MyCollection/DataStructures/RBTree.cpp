#include <bits/stdc++.h>
using namespace std;

class RBTree
{
    struct TreeNode
    {
        int val;
        char color;
        TreeNode *par, *left, *right;
        TreeNode(int x)
        {
            val = x;
            par = NULL;
            left = NULL;
            right = NULL;
            color = 'R';
        }
    };
    TreeNode *root = NULL;

    pair<char, char> getConfiguration(TreeNode *child)
    {
        pair<char, char> configuration;
        TreeNode *par = child->par;
        if (par->left == child)
            configuration.first = 'L';
        else
            configuration.first = 'R';

        TreeNode *gpar = par->par;
        if (gpar->left == par)
            configuration.second = 'L';
        else
            configuration.second = 'R';

        return configuration;
    }
    TreeNode *getUncle(TreeNode *child)
    {
        TreeNode *par = child->par;
        TreeNode *gpar = par->par;
        if (gpar->left == NULL || gpar->right == NULL)
            return NULL;

        if (gpar->left == par)
            return gpar->right;
        return gpar->left;
    }
    void insertInBSTree(TreeNode *child)
    {
        TreeNode *curr = root;
        TreeNode *next = ((root->val <= child->val) ? root->right : root->left);
        while (next != NULL)
        {
            curr = next;
            next = ((curr->val <= child->val) ? curr->right : curr->left);
        }
        if (curr->val <= child->val)
            curr->right = child;
        else
            curr->left = child;
        child->par = curr;
    }
    void leftRotation(TreeNode *child)
    {
        TreeNode *par = child->par;
        TreeNode *gpar = par->par;

        if (gpar != NULL)
        {
            if (gpar->right == par)
                gpar->right = child;
            else
                gpar->left = child;
            child->par = gpar;
        }
        else{
            child->par = NULL;
            root = child;
        }

        par->right = child->left;
        if (child->left != NULL)
            child->left->par = par;

        child->left = par;
        par->par = child;
    }
    void rightRotation(TreeNode *child)
    {
        TreeNode *par = child->par;
        TreeNode *gpar = par->par;

        if (gpar != NULL)
        {
            if (gpar->left == par)
                gpar->left = child;
            else
                gpar->right = child;
            child->par = gpar;
        }
        else{
            root = child;
            child->par = NULL;
        }

        par->left = child->right;
        if (child->right != NULL)
            child->right->par = par;

        child->right = par;
        par->par = child;
    }
    void rotateAndRecolor(TreeNode *child)
    {
        pair<char, char> configuration = getConfiguration(child);
        TreeNode *par = child->par;
        TreeNode *gpar = par->par;

        if (configuration.first != configuration.second)
        {
            if (configuration.second == 'L')
                leftRotation(child);
            else
                rightRotation(child);

            TreeNode *temp = par;
            par = child;
            child = temp;
        }

        if (configuration.second == 'L')
            rightRotation(par);
        else
            leftRotation(par);

        par->color = 'B';
        gpar->color = 'R';
    }
    void correctTree(TreeNode *child)
    {
        if (child->par == NULL)
            child->color = 'B';
        else if (child->par->color == 'R')
        {
            TreeNode *uncle = getUncle(child);
            if (uncle == NULL || uncle->color == 'B')
                rotateAndRecolor(child);
            else
            {
                uncle->color = 'B';
                child->par->color = 'B';
                child->par->par->color = 'R';
                correctTree(child->par->par);
            }
        }
    }

    void inorder(vector<TreeNode *> &trav, TreeNode *node)
    {
        if (node == NULL)
            return;

        inorder(trav, node->left);
        trav.push_back(node);
        inorder(trav, node->right);
    }
    void display()
    {
        vector<TreeNode *> trav;
        inorder(trav, root);
        map<TreeNode *, int> mp;
        int extras = 0;
        for (int i = 0; i < trav.size(); i++)
        {
            mp[trav[i]] = extras;
            extras += (log10(trav[i]->val) + 1) + 3;
        }
        cout << "==========================\n";
        queue<TreeNode *> qu;
        qu.push(root);
        while (qu.size())
        {
            int once = qu.size();
            int spaces = 0;
            while (once--)
            {
                TreeNode *node = qu.front();
                qu.pop();

                while (spaces < mp[node])
                {
                    spaces++;
                    cout << " ";
                }

                spaces += (log10(node->val) + 1) + 3;
                cout << node->val << "[" << node->color << "]";

                if (node->left != NULL)
                    qu.push(node->left);
                if (node->right != NULL)
                    qu.push(node->right);
            }
            cout << "\n";
        }
        cout << "==========================\n";
    }

public:
    void insert(int x)
    {
        TreeNode *child = new TreeNode(x);
        if (root == NULL)
            root = child;
        else
            insertInBSTree(child);
        correctTree(child);

        display();
    }

};

int main()
{
    RBTree tree;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        tree.insert(x);

        cout << endl;
    }
    return 0;
}
