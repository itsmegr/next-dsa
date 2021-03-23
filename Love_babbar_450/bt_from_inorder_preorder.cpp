// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];

        Node *root = buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
int findPos(int ele, int in[], int l, int h)
{
    int ans;
    for (int i = l; i <= h; i++)
    {
        if (in[i] == ele)
            return i;
    }
    return -1;
}
Node *makeTree(int in[], int pre[], int &ipre, int l, int h, int n)
{
    if (ipre >= n)
        return NULL;

    Node *root = new Node(pre[ipre]);
    // root->data = pre[ipre];

    int pos = findPos(pre[ipre], in, l, h);
    // deb2(pre[ipre], pos);
    // deb2(l, h);

    if (pos - l > 0)
    {
        //left is there
        ipre = ipre + 1;
        root->left = makeTree(in, pre, ipre, l, pos - 1, n);
    }
    else
    {
        root->left = NULL;
    }
    // cout << "came again for right of" << pre[ipre] << endl;
    if (h - pos > 0)
    {
        ipre = ipre + 1;
         root->right = makeTree(in, pre, ipre, pos + 1, h, n);
    }
    else
    {
        root->right = NULL;
    }
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int ipre = 0;
    return makeTree(in, pre, ipre, 0, n - 1, n);
}