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

lptr reverse(lptr ll)
{

    lptr prev = NULL, next;
    lptr curr = ll;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

lptr reverse_m_n(lptr ll, int m, int n)
{
    lptr prev = NULL, next;
    lptr curr = ll;
    int k = 1;
    while (k < m)
    {
        prev = curr;
        curr = curr->next;
        k++;
    }
    lptr join1 = prev;
    lptr join2 = curr;

    while (k <= n)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        k++;
    }
    join1->next = prev;
    join2->next = curr;
    return ll;
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
    // print(reverse(LL));
    print(reverse_m_n(LL, 2, 6));
}