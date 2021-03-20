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
    bool topView = false;
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
        deb2(root->data, root->hd);

        inorder(root->left);

        //part2

        inorder(root->right);

        //part3;
    }
}
void hdinsert(bstptr root, int hd, unordered_map<int, bool> &vis)
{
    if (root == NULL)
        return;
    root->hd = hd;
    vis[hd] = false;
    hdinsert(root->left, hd - 1, vis);
    hdinsert(root->right, hd + 1, vis);
}
void printTopView(bstptr root)
{
    if (root)
    {
        //part1
        printTopView(root->left);

        //part2
        if (root->topView)
            cout << root->data << " ";

        printTopView(root->right);

        //part3;
    }
}
void topView(bstptr root)
{
    unordered_map<int, bool> vis;
    hdinsert(root, 0, vis);
    queue<bstptr> q;
    q.push(root);
    bstptr temp;
    int n;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (vis[temp->hd] == false)
        {
            temp->topView = true;
            vis[temp->hd] = true;
        }
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    printTopView(root);
}
void topViewSecond(bstptr root, int height, int hd, map<int, pair<int, int>> &ans)
{
    if (root == NULL)
        return;
    if (ans.find(hd) == ans.end())
    {
        cout << "added at hd " << hd << "and data is " << root->data << endl;
        ans[hd] = make_pair(root->data, height);
    }
    else
    {
        if (height < ans[hd].second)
        {
            cout << "updated at hd " << hd << "and data is " << root->data << endl;
            ans[hd].first = root->data;
            ans[hd].second = height;
        }
    }
    topViewSecond(root->left, height + 1, hd - 1, ans);
    topViewSecond(root->right, height + 1, hd + 1, ans);
}
//logic :- element of the unique horizontal distanse, if two nodes have same hd
//than node with lower level or height will be in top view
//first :- using queue and moving height wise
//second :- go preorder and push for newew hd and if already with hd that node with less
//height
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
    unordered_map<int, bool> vis;
    hdinsert(T, 0, vis);
    inorder(T);
    // for (auto x : vis)
    // {
    //     cout << x.first << " " << x.second << endl;
    // }
    topView(T);
    cout << endl;
    map<int, pair<int, int>> ans;
    // sort(ans.begin(), ans.end());
    topViewSecond(T, 1, 0, ans);
    // for (auto x : ans)
    // {

    //     cout << x.first << " " << x.second.second << " " << x.second.first << " " << endl;
    // }
    auto x = ans.begin();
    for (auto x = ans.begin(); x != ans.end(); x++)
    {
        cout << x->first << " " << x->second.second << " " << x->second.first << " " << endl;
    }
}