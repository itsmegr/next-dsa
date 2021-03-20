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
int diameter(bstptr root, int &dia)
{
    if (root == NULL)
        return 0;
    int lh = diameter(root->left, dia);
    int rh = diameter(root->right, dia);
    dia = max(lh + rh + 1, dia);
    return max(lh, rh) + 1;
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
    //logic is the node whose left tree and right subtree's height 
    //sum will be max
    int dia = 0;
    diameter(T, dia);
    deb(dia);
}