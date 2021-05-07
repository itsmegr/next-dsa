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
bstptr findLca(bstptr root, int n1, int n2){
    if(root==NULL) return NULL;
    if(root->data==n1||root->data==n2){
        return root;
    }

    bstptr l = findLca(root->left, n1, n2);
    bstptr r = findLca(root->right, n1, n2);
    if(l&&r){
        return root;
    }
    return l==NULL?r:l;
}
int findHeight(bstptr root, int h, int k){
    if(root==NULL) return -1;

    if(root->data==k) return h;

    int lh = findHeight(root->left, h+1,k);
    int rh = findHeight(root->right, h+1,k);

    return lh==-1?rh:lh;
}
int findDist(bstptr root, int a, int b) {
    // Your code here
    if(root==NULL) return 0;
    bstptr lca  = findLca(root, a,b);
    int ah = findHeight(lca, 1, a);
    int bh = findHeight(lca, 1, b);
    return ah+bh-2;
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
    int a, b;
    cin>>a>>b;
    cout<<findDist(T, a, b)<<endl;

}