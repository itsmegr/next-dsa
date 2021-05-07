#include <bits/stdc++.h>
using namespace std;
typedef struct llnode *lptr;

struct llnode
{
    int data, power;
    llnode *next = NULL;
};
void insert(lptr &LL, int x, int y)
{
    lptr temp;
    temp = new (llnode);
    temp->data = x;
    temp->power = y;
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
    cout << LL->data << " "<<LL->power<<" ";
    print(LL->next);
}

lptr polynomila_add(lptr l1, lptr l2)
{
    lptr l3 = NULL, templ3=NULL;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->power > l2->power)
        {
            if (l3 == NULL)
            {
                l3 = l1;
                templ3 = l3;
                l1 = l1->next;
            }
            else
            {
                templ3->next = l1;
                templ3 = templ3->next;
                l1 = l1->next;
            }
            templ3->next = NULL;
        }
        else if (l1->power < l2->power)
        {
            if (l3 == NULL)
            {
                l3 = l2;
                templ3 = l3;
                l2 = l2->next;
            }
            else
            {
                templ3->next = l2;
                templ3 = templ3->next;
                l2 = l2->next;
            }
            templ3->next = NULL;
        }
        else
        {
            if (l3 == NULL)
            {
                l3 = l2;
                templ3 = l3;
                templ3->data = l1->data + l2->data;
                l1 = l1->next;
                l2 = l2->next;
            }
            else
            {
                templ3->next = l2;
                templ3 = templ3->next;
                templ3->data = templ3->data + l1->data;
                l1 = l1->next;
                l2 = l2->next;
            }
            templ3->next = NULL;
        }
    }
    if (l2 == NULL)
        templ3->next = l1;
    else
        templ3->next = l2;
    return l3;
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
    int x, y;
    cin >> x >> y;
    while (x != -1)
    {
        insert(LL, x, y);
        cin >> x >> y;
    }

    lptr LL2 = NULL;
    cin >> x >> y;
    while (x != -1)
    {
        insert(LL2, x, y);
        cin >> x >> y;
    }
    // polynomila_add(LL, LL2);
    print( polynomila_add(LL, LL2));
}