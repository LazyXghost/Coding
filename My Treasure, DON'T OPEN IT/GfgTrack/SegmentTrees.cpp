#include<bits/stdc++.h>
using namespace std;

struct SegmentTree
{
    int leafNodes;
    int stSize;
    int leafStartingInd;
    int levels;
    vector<int> tree;
    void buildTree()
    {
        int x = levels - 1;
        while (x > 0)
        {
            int n = pow(2, x - 1);
            int sti = n;
            for (int i = 0; i < n; i++)
            {
                int ind = sti + i;
                tree[ind] = max(tree[ind * 2], tree[ind * 2 + 1]);
            }
            x--;
        }
    }
    void update(int ind, int x)
    {
        int i = leafStartingInd + ind;
        tree[i] = x;
        i = i / 2;
        while (i != 0)
        {
            tree[i] = max(tree[2 * i], tree[2 * i + 1]);
            i = i / 2;
        }
    }
    int getMax()
    {
        return tree[1];
    }
    SegmentTree(const vector<int> &A, int x)
    {
        if (x == 1)
            levels = 1;
        else
            levels = log2(x - 1) + 2;
        leafNodes = pow(2, levels - 1);
        stSize = 2 * leafNodes;
        leafStartingInd = leafNodes;

        tree.resize(stSize, INT_MIN);
        for (int i = 0; i < x; i++)
            tree[leafStartingInd + i] = A[i];

        buildTree();
    }
};
// SegmentTree st({1,2,3,5,6,7...}, 3);