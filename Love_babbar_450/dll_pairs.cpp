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

void pairs_ans(dlptr head, int x){
    dlptr first = head;
    dlptr second = head;
    while(second->next!=NULL) second =  second->next;
    int sum;
    // cout<<x<<endl;

    while(first!=NULL&&second!=NULL&&first!=second&&second->next!=first){
        sum = first->data+second->data;
        // deb2(first, second);
        if(sum==x){
            cout<<first->data<<" "<<second->data<<endl;
            first = first->next;
            second= second->prev;
        }
        else{
            if(sum>x){
                second= second->prev;
            }
            else first = first->next;
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
    dlptr dl = create();
    int x;
    cin>>x;
    pairs_ans(dl, x);
}