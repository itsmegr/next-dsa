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
struct Info
{
	int sz; // Size of subtree
	int max; // Min value in subtree
	int min; // Max value in subtree
	int ans; // Size of largest BST which
	// is subtree of current node
	bool isBST; // If subtree is BST
};

// Returns Information about subtree. The
// Information also includes size of largest
// subtree which is a BST.
Info largestBSTBT(bstptr root)
{
	// Base cases : When tree is empty or it has
	// one child.
	if (root == NULL)
		return {0, INT_MIN, INT_MAX, 0, true};
	if (root->left == NULL && root->right == NULL)
		return {1, root->data, root->data, 1, true};

	// Recur for left subtree and right subtrees
	Info l = largestBSTBT(root->left);
	Info r = largestBSTBT(root->right);

	// Create a return variable and initialize its
	// size.
	Info ret;
	ret.sz = (1 + l.sz + r.sz);

	// If whole tree rooted under current root is
	// BST.
	if (l.isBST && r.isBST && l.max < root->data &&
			r.min > root->data)
	{
		ret.min = min(l.min, root->data);
		ret.max = max(r.max, root->data);

		// Update answer for tree rooted under
		// current 'root'
		ret.ans = ret.sz;
		ret.isBST = true;

		return ret;
	}

	// If whole tree is not BST, return maximum
	// of left and right subtrees
	ret.ans = max(l.ans, r.ans);
	ret.isBST = false;

	return ret;
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
