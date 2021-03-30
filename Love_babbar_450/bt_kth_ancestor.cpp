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
bstptr kthAncestor(bstptr root, int &k, int n, bool &found)
{
    if (root == NULL)
        return NULL;
    if (root->data == n)
    {
        found=true;
        k = k - 1;
        if(k==0) return root;
        else return NULL;
    }
    bstptr l = kthAncestor(root->left, k, n, found);
    bstptr r=NULL;
    if(!found)
    r = kthAncestor(root->right, k, n, found);

    if(found) k=k-1;

    if(k==0&&found) return root;

    return l==NULL?r:l;
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
    int a,k;
    cin>>a>>k;
    bool found = false;
    bstptr ans =kthAncestor(T,k,a, found);
    if(ans){
        deb(ans->data);
    }
    else{
        cout<<-1<<endl;
    }
}