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
void zigZag(bstptr root)
{
    if (root == NULL)
        return;
    queue<bstptr> q;
    q.push(root);
    bstptr t;
    int n, j = 0;
    stack<int> s;
    while (!q.empty())
    {
        n = q.size();
        j++;
        for (int i = 1; i <= n; i++)
        {
            t = q.front();

            q.pop();
            if (j % 2 == 1)
            {
                cout << t->data << " ";
            }
            else
            {
                s.push(t->data);
            }
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        if(j%2==0){
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
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
    zigZag(T);
}