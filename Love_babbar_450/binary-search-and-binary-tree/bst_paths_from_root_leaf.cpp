#include <bits/stdc++.h>
using namespace std;
typedef struct bstnode *bstptr;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
struct bstnode
{
    struct bstnode *left = NULL;
    int data;
    struct bstnode *right = NULL;
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
void prints(stack<int> s)
{
    if (s.empty())
    {
        return;
    }
    int x = s.top();
    s.pop();
    prints(s);
    cout << x << " ";
}
void paths(bstptr root, stack<int> s)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        s.push(root->data);
        //print stack;
        prints(s);
        cout << endl;
        return;
    }

    s.push(root->data);
    paths(root->left, s);
    paths(root->right, s);
}
void maxPaths(bstptr root, stack<int> s, pair<int, int> &p, int sum, int n)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        sum = sum + root->data;
        if (n > p.first)
        {
            p.first=n;
            p.second = sum;
        }
        else if (n == p.first && sum > p.second)
        {
            p.second = sum;
        }
        s.push(root->data);
        //print stack;
        prints(s);
        cout << endl;
        return;
    }

    s.push(root->data);
    maxPaths(root->left, s, p, sum + root->data, n + 1);
    maxPaths(root->right, s, p, sum + root->data, n + 1);
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
    stack<int> s;
    paths(T, s);
    pair<int, int> p = make_pair(0, 0);
    maxPaths(T, s, p, 0, 1);
    deb2(p.first, p.second);
}