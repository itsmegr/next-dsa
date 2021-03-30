#include <bits/stdc++.h>
using namespace std;
typedef struct bstnode *bstptr;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
struct bstnode
{
    struct bstnode *left = NULL;
    int val;
    struct bstnode *right = NULL;
};
void insert(bstptr &T, int k)
{
    if (T == NULL)
    {
        T = new (bstnode);
        T->val = k;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (k < T->val)
            insert(T->left, k);
        else
            insert(T->right, k);
    }
}
void inorder(bstptr root)
{
    if (root)
    {
        //part1

        inorder(root->left);

        //part2
        cout << root->val << " ";

        inorder(root->right);

        //part3;
    }
}

bstptr find(bstptr root, bstptr &prev, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val == key)
    {
        return root;
    }
    else if (key > root->val)
    {
        prev = root;
        return find(root->right, prev, key);
    }
    else
    {
        prev = root;
        return find(root->left, prev, key);
    }
}
void change(bstptr root)
{
    //1.find the max in lt with parent
    //   if(max==leaf) change and return
    bstptr left = root->left;
    bstptr right = root->right;
    bstptr parent = root;
    bstptr demptr = NULL;
    if (left)
    {
        demptr = left;
        //find the max in lt;
        while (demptr->right)
        {
            parent = demptr;
            demptr = demptr->right;
        }
        //if max is leaf;
        if (!demptr->left && !demptr->right)
        {
            root->val = demptr->val;
            if (parent == root)
                parent->left = NULL;
            else
                parent->right = NULL;
            return;
        }
        else
        {
            root->val = demptr->val;
            change(demptr);
            return;
        }
    }
    if (right)
    {
        demptr = right;
        //find the min in rt;
        while (demptr->left)
        {
            parent = demptr;
            demptr = demptr->left;
        }
        //if min is leaf;
        if (!demptr->left && !demptr->right)
        {
            root->val = demptr->val;
            if (parent == root)
                parent->right = NULL;
            else
                parent->left = NULL;
            return;
        }
        else
        {
            root->val = demptr->val;
            change(demptr);
            return;
        }
    }
}
bstptr deleteNode(bstptr root, int key)
{
    if(root==NULL) return root;
    bstptr pos = NULL;
    bstptr parent = NULL;
    pos = find(root, parent, key);
    if (!pos)
        return root;
    //if pos is leaf node
    if (!pos->left && !pos->right)
    {
        if (parent == NULL)
            return NULL;
        if (parent->left == pos)
        {
            parent->left = NULL;
            return root;
        }
        if (parent->right == pos)
        {
            parent->right = NULL;
            return root;
        }
    }
    change(pos);
    return root;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    bstptr T = NULL;
    cin >> n;
    while (n >= 0)
    {
        insert(T, n);
        cin >> n;
    }
    inorder(T);
    cout << endl;
    int key;
    cin >> key;
    deleteNode(T, key);
    inorder(T);
}