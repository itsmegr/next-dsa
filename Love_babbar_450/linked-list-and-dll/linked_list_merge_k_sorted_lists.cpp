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
lptr mergeKLists(lptr arr[], int K)
{
    lptr first = arr[0];
    lptr second = NULL;
    for(int i=1;i<K;i++){
        second  = arr[i];
        first  = merge(first, second);
    }
    return first;
}
// Node *merge(Node *head1, Node *head2)
// {
//     Node *newHead = NULL, temp;

//     while (head1 != NULL && head2 != NULL)
//     {
//         if (head1->data < head2->data)
//         {
//             if (newHead == NULL)
//             {
//                 newHead = head1;
//                 temp = head1;
//                 head1 = head1->next;
//             }
//             else
//             {
//                 temp->next = head1;
//                 temp = temp->next;
//                 head1 = head1->next;
//             }
//         }
//         else
//         {
//             if (newHead == NULL)
//             {
//                 newHead = head2;
//                 temp = head2;
//                 head2 = head2->next;
//             }
//             else
//             {
//                 temp->next = head2;
//                 temp = temp->next;
//                 head2 = head2->next;
//             }
//         }
//         temp->next = NULL;
//     }

//     if(head1==NULL) temp->next = head2;
//     if(head2==NULL) temp->next = head1;
//     // print(newHead);
//     return newHead;
// }
// Node *mergeKLists(Node *arr[], int K)
// {
//     Node *first = arr[0];
//     Node *second = NULL;
//     for(int i=1;i<K;i++){
//         second  = arr[i];
//         first  = merge(first, second);
//     }
//     return first;
// }

void print(lptr LL)
{
    if (LL == NULL)
        return;
    cout << LL->data << " ";
    print(LL->next);
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
}