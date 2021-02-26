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
        return;
    cout << LL->data << " ";
    print(LL->next);
}

lptr add_two(lptr l1, lptr l2)
{
    lptr l3 = NULL, l3prt = NULL;
    int curry = 0, newData, l1data, l2data;
    while (l1 != NULL || l2 != NULL)
    {
        l1data = l1 != NULL ? l1->data : 0;
        l2data = l2 != NULL ? l2->data : 0;
        newData = l1data + l2data + curry;
        curry = newData / 10;

        lptr temp = new llnode;
        temp->data = newData % 10;
        if (l3 == NULL)
        {
            l3 = temp;
            l3prt = temp;
        }
        else
        {
            l3prt->next = temp;
            l3prt = l3prt->next;
        }
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }
    if (curry != 0)
    {
        lptr temp = new llnode;
        temp->data = curry;
        l3prt->next = temp;
        l3prt = l3prt->next;
    }
    print(l3);
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

    lptr LL2 = NULL;
    cin >> x;
    while (x != -1)
    {
        insert(LL2, x);
        cin >> x;
    }

    add_two(LL, LL2);
}