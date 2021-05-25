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
void inorder(bstptr root, vector<bstptr> &v)
{
    if (root)
    {
        //part1

          inorder(root->left,v);

          v.push_back(root);
        //part2

         inorder(root->right,v);

        //part3;
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
    vector<bstptr> v;
    inorder(T, v);
    T = v[0];
    bstptr prev = T;
    T->left = NULL;
    for(int i=1;i<v.size();i++){
        prev->right = v[i];
        v[i]->left = prev;
        v[i]->right = NULL;
        prev = v[i];
    }
    while(T!=NULL){
        cout<<T->data<<" ";
        T= T->right;
    }
}