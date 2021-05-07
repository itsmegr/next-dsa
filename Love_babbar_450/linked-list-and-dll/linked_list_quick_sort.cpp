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
    if (LL == NULL)
    {
        cout << endl;
        return;
    }
    cout << LL->data << " ";
    print(LL->next);
}

lptr partition(lptr head, lptr &head1, lptr &head2)
{
    lptr pivot = head;
    lptr curr = head->next;
    lptr temp1 = NULL;
    lptr temp2 = NULL;
    while (curr != NULL)
    {
        if (curr->data <= pivot->data)
        {
            if (head1 == NULL)
            {
                head1 = curr;
                temp1 = curr;
                curr = curr->next;
                temp1->next = NULL;
            }
            else
            {
                temp1->next = curr;
                temp1 = temp1->next;
                curr = curr->next;
                temp1->next = NULL;
            }
        }
        else
        {
            if (head2 == NULL)
            {
                head2 = curr;
                temp2 = curr;
                curr = curr->next;
                temp2->next = NULL;
            }
            else
            {
                temp2->next = curr;
                temp2 = temp2->next;
                curr = curr->next;
                temp2->next = NULL;
            }
        }
    }
    pivot->next = NULL;
    // cout << "pivot is ";
    // print(pivot)
    // print(head1);
    // print(head2);
    return pivot;
}

lptr quickSort(lptr head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    lptr head1 = NULL;
    lptr head2 = NULL;
    lptr newHead = NULL;

    lptr pivot = partition(head, head1, head2);
    if (head1 == NULL)
    {
        newHead = pivot;
        head2 = quickSort(head2);
        pivot->next = head2;
    }
    else if (head2 == NULL)
    {
        head1 = quickSort(head1);
        newHead = head1;
        lptr temp = head1;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = pivot;
        pivot->next = NULL;
    }
    else
    {
        head1 = quickSort(head1);
        newHead = head1;
        lptr temp = head1;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = pivot;
        head2 = quickSort(head2);
        pivot->next = head2;
    }
    return newHead;
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
    print(quickSort(LL));
    // partition(LL, NULL, NULL);
}