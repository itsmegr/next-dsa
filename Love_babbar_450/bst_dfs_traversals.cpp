#include <bits/stdc++.h>
using namespace std;
typedef struct bstnode *bstptr;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
struct bstnode
{
    struct bstnode *lchild;
    int data;
    struct bstnode *rchild;
};
void insert(bstptr &T, int k)
{
    if (T == NULL)
    {
        T = new (bstnode);
        T->data = k;
        T->lchild = NULL;
        T->rchild = NULL;
    }
    else
    {
        if (k < T->data)
            insert(T->lchild, k);
        else
            insert(T->rchild, k);
    }
}
struct trnode
{
    bstptr node;
    int come_back_postion;
    trnode(bstptr a, int b)
    {
        node = a;
        come_back_postion = b;
    }
};
void preorder(bstptr root)
{
    if (root)
    {
        //part1
        cout << root->data << " ";

        preorder(root->lchild);

        //part2

        preorder(root->rchild);

        //part3;
    }
}
void inorder(bstptr root)
{
    if (root)
    {
        //part1

        inorder(root->lchild);

        //part2
        cout << root->data << " ";

        inorder(root->rchild);

        //part3;
    }
}
void postorder(bstptr root)
{
    if (root)
    {
        //part1

        postorder(root->lchild);

        //part2

        postorder(root->rchild);

        cout << root->data << " ";
        //part3;
    }
}

void preorder_iter(bstptr root)
{
    stack<trnode *> st;

    trnode *temptrnode;
    bstptr tempbstnode;
    int position;

    st.push(new trnode(root, 1));

    while (!st.empty())
    {
        temptrnode = st.top();
        tempbstnode = temptrnode->node;
        position = temptrnode->come_back_postion;
        st.pop();

        switch (position)
        {
        case 1:
            //part1
            cout << tempbstnode->data << " ";
            st.push(new trnode(tempbstnode, 2));
            if (tempbstnode->lchild)
                st.push(new trnode(tempbstnode->lchild, 1));
            break;
        case 2:
            //part2
            st.push(new trnode(tempbstnode, 3));
            if (tempbstnode->rchild)
                st.push(new trnode(tempbstnode->rchild, 1));
            break;
        case 3:
            //part3

            break;
        }
    }
}
void inorder_iter(bstptr root)
{
    stack<trnode *> st;

    trnode *temptrnode;
    bstptr tempbstnode;
    int position;

    st.push(new trnode(root, 1));

    while (!st.empty())
    {
        temptrnode = st.top();
        tempbstnode = temptrnode->node;
        position = temptrnode->come_back_postion;
        st.pop();

        switch (position)
        {
        case 1:
            //part1
            st.push(new trnode(tempbstnode, 2));
            if (tempbstnode->lchild)
                st.push(new trnode(tempbstnode->lchild, 1));
            break;
        case 2:
            //part2
            cout << tempbstnode->data << " ";
            st.push(new trnode(tempbstnode, 3));
            if (tempbstnode->rchild)
                st.push(new trnode(tempbstnode->rchild, 1));
            break;
        case 3:
            //part3

            break;
        }
    }
}
void postorder_iter(bstptr root)
{
    stack<trnode *> st;

    trnode *temptrnode;
    bstptr tempbstnode;
    int position;

    st.push(new trnode(root, 1));

    while (!st.empty())
    {
        temptrnode = st.top();
        tempbstnode = temptrnode->node;
        position = temptrnode->come_back_postion;
        st.pop();

        switch (position)
        {
        case 1:
            //part1

            st.push(new trnode(tempbstnode, 2));
            if (tempbstnode->lchild)
                st.push(new trnode(tempbstnode->lchild, 1));
            break;
        case 2:
            //part2
            st.push(new trnode(tempbstnode, 3));
            if (tempbstnode->rchild)
                st.push(new trnode(tempbstnode->rchild, 1));
            break;
        case 3:
            //part3
            cout << tempbstnode->data << " ";
            break;
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
    preorder(T);
    cout << endl;
    preorder_iter(T);
    cout << endl;
    inorder(T);
    cout << endl;
    inorder_iter(T);
    cout << endl;
    postorder(T);
    cout << endl;
    postorder_iter(T);
    cout << endl;
}
