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
int height(bstptr root){
    if(root == NULL) return 0;
    return max(height(root->left), height(root->right)) +1;
}
void preorderTra(bstptr node, vector<bool> &visitedHeight, int curHeight){
    if(node==NULL) return;
    if(visitedHeight[curHeight-1]==false){
        cout<<node->data<<" ";
        visitedHeight[curHeight-1]=true;
    }
    preorderTra(node->left,visitedHeight, curHeight+1);
    preorderTra(node->right,visitedHeight, curHeight+1);
}
//for right view just go to right first
//and thiis is done
//logic from every height only one element
void leftView(bstptr root){
    if(root==NULL) return;
    int h =  height((root));
    vector<bool> visitedHeight(h, false);
    preorderTra(root, visitedHeight,1);
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
    leftView(T);
}