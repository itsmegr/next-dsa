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
void path(bstptr root, vector<bstptr> &a, bool &found, int k)
{
    if (root == NULL)
        return;
    a.push_back(root);
    //  cout <<"came2"<<endl;
    // cout << root->data << " ";
    if (root->data == k)
    {
        found = true;
        return;
    }
    path(root->left, a, found, k);
    if (found)
    {
        return;
    }
    path(root->right, a, found, k);
    if (found)
    {
        return;
    }
    a.pop_back();
}
bstptr lca(bstptr root, int n1, int n2)
{
    //Your code here
    vector<bstptr> a;
    bool found = false;
    path(root, a, found, n1);
    vector<bstptr> b;
    found = false;
    path(root, b, found, n2);
    bstptr last;
    for(int i=0;i<min(a.size(), b.size());i++){
        if(a[i]!=b[i]){
            break;
        }
        last = a[i];
    }
    cout<<last->data<<endl;
    return last;
    
}
bstptr findLCA( bstptr root, int n1, int n2)
{
    // Base case
    if (root == NULL) return NULL;

    // If either n1 or n2 matches with root's key, report
    // the presence by returning root (Note that if a key is
    // ancestor of other, then the ancestor key becomes LCA
    if (root->data == n1 || root->data == n2)
        return root;

    // Look for keys in left and right subtrees
    bstptr left_lca  = findLCA(root->left, n1, n2);
    bstptr right_lca = findLCA(root->right, n1, n2);

    // If both of the above calls return Non-NULL, then one key
    // is present in once subtree and other is present in other,
    // So this node is the LCA
    if (left_lca && right_lca)  return root;

    // Otherwise check if left subtree or right subtree is LCA
    return (left_lca != NULL)? left_lca: right_lca;
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
    int n1, n2;
    cin>>n1>>n2;
    lca(T, n1, n2);
}