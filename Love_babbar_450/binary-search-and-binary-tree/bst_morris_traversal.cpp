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
void MorrisTraversal(bstptr root){
    bstptr curr, pre;
    curr = root;
    if(root==NULL) return;
    
    while(curr!=NULL){
       if(!curr->left){
           cout<<curr->data<<" ";
           curr= curr->right;
       }
       else{
           //finding the predecessor
           //or predecessor is already pointing to the node(cam second time on node)
           pre = curr->left;
           while(pre->right!=NULL&&pre->right!=curr){
               
           }pre = pre->right;
           //point right of the predecoessor to curr and now go to the left
           if(pre->right==NULL){
               pre->right = curr;
               curr = curr->left;
           }
          //now predecessor is alaready point to curr
          //remove it and go to the right of the node because youo have already 
          //treaverse the left part
           else{
               pre->right = NULL;
               cout<<curr->data<<" ";
               curr = curr->right;
           }
       }
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
    MorrisTraversal(T);
}