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
bool binarySearch(bstptr root, int x){
    if(root==NULL) return false;
    if(root->data==x) return true;
    else if(x>root->data){
        return binarySearch(root->right,x);
    }
    else{
        return binarySearch(root->left,x);
    }
}
int countPairs(bstptr root1, bstptr root2, int x)
{
    // Code here
    int ans = 0;
    if(root1==NULL) return 0;
    if(binarySearch(root2, x-root1->data)){
        ans = ans+1;
    }
    return ans + countPairs(root1->left, root2, x) + countPairs(root1->right, root2, x);
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
}

