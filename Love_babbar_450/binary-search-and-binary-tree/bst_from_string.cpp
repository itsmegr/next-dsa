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
    bstnode(int k)
    {
        data = k;
    }
};
void insert(bstptr &T, int k)
{
    if (T == NULL)
    {
        T = new bstnode(k);
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

void makeTree(string s, int &i, int l, bstptr root)
{
    if (i >= l)
        return;

    if (s[i] == '(')
    {
        if (s[i + 1] != ')')
        {
            deb2(i, int(s[i + 1]));
            root->left = new bstnode(s[i + 1] - '0');
            i = i + 2;
            makeTree(s, i, l, root->left);
        }
        else
        {
            i = i + 2;
        }

        if (i >= l)
            return;

        if (s[i] == '(')
        {
            deb2(i, int(s[i + 1]));
            root->right = new bstnode(s[i + 1] - '0');
            i = i + 2;
            makeTree(s, i, l, root->right);
        }
    }

    if (s[i] == ')')
    {
        if (i >= l)
            return;
        else
        {
            i = i + 1;
            return;
        }
    }
    return;
}
void converSt(bstptr root)
{
    if (root == NULL)
        return;
    cout << root->data;
    if (root->left == NULL && root->right == NULL)
    {
        return;
    }
    if (root->left == NULL)
    {
        cout << "()";
    }
    else
    {
        cout << "(";
        converSt(root->left);
        cout << ")";
    }
    if (root->right == NULL)
    {
        // cout << ")";
    }
    else
    {
        cout << "(";
        converSt(root->right);
        cout << ")";
    }
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
    // int n;
    // bstptr T = NULL;
    // cin >> n;
    // while (n >= 0)
    // {
    //     insert(T, n);
    //     cin >> n;
    // }
    // inorder(T);
    string s;
    cin >> s;

    bstptr root = new bstnode(s[0] - '0');

    if (s.length() > 1)
    {
        int i = 1;
        int l = s.length() - 1;
        makeTree(s, i, l, root);
    }
    inorder(root);
    cout<<endl;
    converSt(root);
}