#include <bits/stdc++.h>
using namespace std;
typedef struct bstnode *bstptr;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
struct bstnode
{
    struct bstnode *left;
    int data;
    struct bstnode *right;
};
void insert(bstptr &T, int k)
{
    if (T == NULL)
    {
        T = new (bstnode);
        T->data = k;
        T->left = NULL;
        T->right = NULL;
    }
    else
    {
        if (k < T->data)
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
        cout << root->data << " ";

        inorder(root->right);

        //part3;
    }
}
void mirror(bstptr old, bstptr neww)
{
    if (old == NULL)
        return;
    if (neww == NULL)
        return;

    if (old->left)
    {
        bstptr newRight = new bstnode;
        newRight->data = old->left->data;
        neww->right = newRight;
    }
    if (old->right)
    {
        bstptr newLeft = new bstnode;
        newLeft->data = old->right->data;
        neww->left = newLeft;
    }
    mirror(old->left, neww->right);
    mirror(old->right, neww->left);
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

    bstptr neww =  new bstnode;
    neww->data = T->data;
    mirror(T, neww);
    inorder(T);
    cout<<endl;
    inorder(neww);
}