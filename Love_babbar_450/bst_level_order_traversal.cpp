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
    bstnode()
    {
    }
    bstnode(int k)
    {
        data = k;
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
int height(bstptr root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

void printLevel(bstptr root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        cout << root->data << " ";
        return;
    }
    printLevel(root->left, level - 1);
    printLevel(root->right, level - 1);
}
void levelOrderTraversal2(bstptr root)
{
    if (root == NULL)
        return;
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        printLevel(root, i);
        cout << endl;
    }
}

void levelOrderTraversalRec(queue<bstptr> q)
{
    if (q.empty())
        return;
    bstptr temp = q.front();
    q.pop();
    if (temp->right)
        q.push(temp->right);
    if (temp->left)
        q.push(temp->left);

    levelOrderTraversalRec(q);
    cout << temp->data << " ";
}

void levelOrderTraversal(bstptr root)
{
    if (root == NULL)
        return;

    bstptr temp;
    queue<bstptr> q;
    q.push(root);
    int n;
    while (!q.empty())
    {
        n = q.size();
        for (int i = 1; i <= n; i++)
        {
            temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout<<endl;
    }
}
void ReverselevelOrderTraversal(bstptr root)
{
    if (root == NULL)
        return;

    bstptr temp;
    queue<bstptr> q;
    q.push(root);
    stack<int> s;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        s.push(temp->data);
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int diameter(bstptr root, int &dia)
{
    if (root == NULL)
        return 0;
    int lh = diameter(root->left, dia);
    int rh = diameter(root->right, dia);
    dia = max(lh + rh + 1, dia);
    return max(lh, rh) + 1;
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
    // levelOrderTraversal(T);
    // cout << endl;
    // levelOrderTraversal2(T);
    // queue<bstptr> q;
    // q.push(T);
    // levelOrderTraversalRec(q);
    // ReverselevelOrderTraversal(T);
    // int dia = 0;
    // diameter(T, dia);
    // deb(dia);
    levelOrderTraversal(T);
}
