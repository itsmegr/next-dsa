#include <bits/stdc++.h>
using namespace std;
typedef struct llnode *lptr;

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

void reverse(lptr &LL)
{
    lptr prev = NULL, curr = LL, next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    LL = prev;
}

void reverseRec(lptr &LL, lptr prev, lptr curr)
{
    if (curr == NULL)
    {
        LL = prev;
        return;
    }
    lptr next = curr->next;
    curr->next = prev;
    reverseRec(LL, curr, next);
}


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
    return 0;
}