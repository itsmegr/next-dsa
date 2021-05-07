#include <bits/stdc++.h>
using namespace std;
typedef struct dllnode *dlptr;
#define deb(x) cout << #x << "=" << x->data << endl
#define deb2(x, y) cout << #x << "=" << x->data << "," << #y << "=" << y->data << endl
struct dllnode
{
    int data;
    dllnode *prev;
    dllnode *next;
    dllnode(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
dlptr create()
{
    int n;
    cin >> n;
    dlptr head = NULL;
    while (n > 0)
    {
        if (head == NULL)
        {
            head = new dllnode(n);
        }
        else
        {
            dlptr temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            dlptr newNode = new dllnode(n);
            newNode->prev = temp;
            temp->next = newNode;
        }
        cin >> n;
    }
    return head;
}
void print(dlptr curr)
{
    if (curr == NULL)
    {
        cout << endl;
        return;
    }
    cout << curr->data << " ";
    print(curr->next);
}
dlptr reverseDLL(dlptr  head)
{
    //Your code here
    dlptr curr = head;
    dlptr tprev, tnext;
    while(curr!=NULL){
        tnext = curr->next;
        curr->next = curr->prev;
        curr->prev = tnext;
        tprev = curr;
        curr = tnext;
    }
    return tprev;
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
    dlptr dl = create();
    print(dl);
    print(reverseDLL(dl));
}