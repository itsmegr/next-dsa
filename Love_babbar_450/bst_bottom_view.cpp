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
    int hd;
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
void hdinsert(bstptr root, int hd)
{
    if (root == NULL)
        return;
    root->hd = hd;
    hdinsert(root->left, hd - 1);
    hdinsert(root->right, hd + 1);
}
void bottomViewPrintRec(queue<bstptr> &q, unordered_map<int, int> &vis)
{
    if (q.empty())
        return;
    bstptr temp = q.front();
    q.pop();
    if (temp->right)
        q.push(temp->right);
    if (temp->left)
        q.push(temp->left);
    bottomViewPrintRec(q, vis);
    if (vis[temp->hd] == 0)
    {
        cout << temp->data << " ";
        vis[temp->hd] = temp->data;
    }
}
void bottomViewSecond(bstptr root, int height, int hd, map<int, pair<int, int>> &ans)
{
    if (root == NULL)
        return;
    if (ans.find(hd) == ans.end())
    {
        // cout << "added at hd " << hd << "and data is " << root->data << endl;
        ans[hd] = make_pair(root->data, height);
    }
    else
    {
        if (height >= ans[hd].second)
        {
            // cout << "updated at hd " << hd << "and data is " << root->data << endl;
            ans[hd].first = root->data;
            ans[hd].second = height;
        }
    }
    bottomViewSecond(root->left, height + 1, hd - 1, ans);
    bottomViewSecond(root->right, height + 1, hd + 1, ans);
}

void bottomView(bstptr root)
{
    hdinsert(root, 0);
    queue<bstptr> q;
    unordered_map<int, int> vis;
    q.push(root);
    bottomViewPrintRec(q, vis);
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
    bottomView(T);
    cout << endl;
    map<int, pair<int, int>> ans;
    bottomViewSecond(T, 1, 0, ans);

    auto x = ans.begin();
    for (auto x = ans.begin(); x != ans.end(); x++)
    {
        cout << x->first << " " << x->second.second << " " << x->second.first << " " << endl;
    }
}