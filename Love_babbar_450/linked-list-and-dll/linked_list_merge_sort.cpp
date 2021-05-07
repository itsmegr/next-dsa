#include <bits/stdc++.h>
using namespace std;
typedef struct llnode *lptr;
#define deb(x) cout << #x << "=" << x->data << endl
#define deb2(x, y) cout << #x << "=" << x->data << "," << #y << "=" << y->data << endl
struct llnode
{
    int data;
    llnode *next = NULL;
};
void insert(lptr &LL, int x)
{
    lptr temp;
    temp = new (llnode);
    temp->data = x;
    if (LL == NULL)
    {
        LL = temp;
        return;
    }
    lptr temp2 = LL;
    while (temp2->next != NULL)
        temp2 = temp2->next;
    temp2->next = temp;
}

void print(lptr LL)
{
    if (LL == NULL){
        cout<<endl;
        return;
    }
    cout << LL->data << " ";
    print(LL->next);
}

lptr merge(lptr head1, lptr head2)
{
    lptr newHead = NULL, temp;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (newHead == NULL)
            {
                newHead = head1;
                temp = head1;
                head1 = head1->next;
            }
            else
            {
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
            }
        }
        else
        {
            if (newHead == NULL)
            {
                newHead = head2;
                temp = head2;
                head2 = head2->next;
            }
            else
            {
                temp->next = head2;
                temp = temp->next;
                head2 = head2->next;
            }
        }
        temp->next = NULL;
    }

    if(head1==NULL) temp->next = head2;
    if(head2==NULL) temp->next = head1;
    // print(newHead);
    return newHead;
}

lptr merge_Sort(lptr head)
{
    if (head->next == NULL)
        return head;
    //splitting it in two head;
    lptr sp = head;
    lptr fp = head;
    lptr head1 = head;
    lptr head2 = NULL;
    while(fp->next!=NULL&&fp->next->next!=NULL){
        sp = sp->next;
        fp = fp->next->next;
    }

    lptr temp = sp->next;
    sp->next = NULL;
    head2 = temp;
    // deb2(head1, head2);
    head1 = merge_Sort(head1);
    head2 = merge_Sort(head2);

    return merge(head1, head2);
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

    lptr LL = NULL;
    int x;
    cin >> x;
    while (x != -1)
    {
        insert(LL, x);
        cin >> x;
    }
    print(merge_Sort(LL));
}