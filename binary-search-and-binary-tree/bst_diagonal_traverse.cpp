#include <bits/stdc++.h>
using namespace std;
typedef struct bstnode *bstptr;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
struct bstnode
{
    struct bstnode *left=NULL;
    int data;
    struct bstnode *right=NULL;
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
void traverseNow(bstptr node, int verticalDis ,map<int, vector<int>> &ans){
    if(node==NULL) return;
    ans[verticalDis].push_back(node->data);
    traverseNow(node->left, verticalDis+1, ans);
    traverseNow(node->right, verticalDis, ans);
}
void diagonalTraverse(bstptr root){
    map<int, vector<int>> ans;
    traverseNow(root, 1, ans);

    for(auto x:ans){
        for(int x : x.second){
            cout<<x<<" ";
        }
        cout<<endl;
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
    int n;
    bstptr T = NULL;
    cin >> n;
    while (n >= 0)
    {
        insert(T, n);
        cin >> n;
    }
    diagonalTraverse(T);
}