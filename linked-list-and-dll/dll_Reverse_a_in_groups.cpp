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
dlptr reverseDLL(dlptr head)
{
    //Your code here
    dlptr curr = head;
    dlptr tprev, tnext;
    while (curr != NULL)
    {
        tnext = curr->next;
        curr->next = curr->prev;
        curr->prev = tnext;
        tprev = curr;
        curr = tnext;
    }
    return tprev;
}
dlptr give_in_reverse(dlptr curr, int k, int i, dlptr &new_list_last, dlptr &head){
    if(curr == NULL) return NULL;
    if(i>k) return curr;
    dlptr returnAns = give_in_reverse(curr->next, k, i+1, new_list_last, head);
    if(new_list_last==NULL){
        head = curr;
        head->next = NULL;
        head->prev = NULL;
        new_list_last = head;
    }
    else{
        new_list_last->next = curr;
        curr->prev = new_list_last;
        new_list_last = new_list_last -> next;
        new_list_last->next = NULL;
    }
    return returnAns;
}
void reverse_in_groups(dlptr head, int k){
    dlptr curr = head, new_list_last = NULL, new_Head = NULL;

    while (curr!=NULL)
    {
       curr = give_in_reverse(curr, k, 1,new_list_last, new_Head);
    }
    print(new_Head);
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
    int k;
    cin>>k;
    reverse_in_groups(dl, k);
}