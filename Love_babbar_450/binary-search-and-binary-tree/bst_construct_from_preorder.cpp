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
    bstnode(int x){
        data=x;
    }
    bstnode(){
    }
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
bstptr constructFromPreorder(vector<int> pre, int &i, int min, int max){
    if(i>=pre.size()) return NULL;
    if(pre[i]>=min&&pre[i]<=max){
        bstptr root = new bstnode(pre[i]);
        i++;
        root->left = constructFromPreorder(pre, i, min, root->data-1);
        root->right  = constructFromPreorder(pre, i, root->data+1, max);
        return root;
    }
    else return NULL;

}
bool find(bstptr root, int k){
    if(root==NULL) return false;
    if(root->data==k) return true;
    if(root->data<k){
        return find(root->left, k);
    }
    
    else {
        return find(root->right, k);
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
    int n;
    cin>>n;
    vector<int> pre(n,0);
    for(int i=0;i<n;i++){
        cin>>pre[i];
    }
    int i=0;
    bstptr root = constructFromPreorder(pre, i, INT_MIN, INT_MAX);
    inorder(root);

}