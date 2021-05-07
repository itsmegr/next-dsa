// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

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

void printAllDups(Node *root);

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
    struct Node *child;
    scanf("%d\n", &t);
    while (t--)
    {
        map<int, Node *> m;
        int n;
        scanf("%d\n", &n);
        struct Node *root = NULL;
        while (n--)
        {
            Node *parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        printAllDups(root);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line
void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
string serial(Node *root, unordered_map<string, int> &m)
{
    string s;
    if (root == NULL)
    {
        s = s + '$';
        return s;
    }
    s = s + to_string(root->data);
    s = s + '_';
    s = s + serial(root->left, m);
    s = s + '_';
    s = s + serial(root->right, m);
    m[s]++;
    return s;
}
void printAllDups(Node *root)
{
    unordered_map<string, int> m;
    serial(root, m);
    string s;
    int print=0;
    for(auto x:m){
        s = x.first;
        if(x.second<2) continue;
        print++;
        for(char c:s){
            if(c=='_') break;
            cout<<c;
        }
        cout<<" ";
    }
    if(print==0) cout<<-1;
}