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

void segreagate(lptr &ll){
    lptr prev, curr,last;
    if(ll->data%2==0){
        last =ll;
        curr = ll->next;
        prev = ll;
    }
    else last = NULL, curr = ll->next, prev = ll;
    while(curr!=NULL){
        if(curr->data%2==0&&last==prev){
            last = curr;
            prev = curr;
            curr  = curr->next;
            continue;
        }
        if(curr->data%2==0&&last==NULL){
            prev->next = curr->next;
            last = curr;
            last->next = ll;
            ll = last;
            curr = curr->next;
            continue;
        }
        if(curr->data%2==0){
            prev->next = curr->next;
            lptr next = last->next;
            last->next = curr;
            last = last->next;
            curr = curr->next;
            last->next = next;
            continue;
        }
        prev = curr;
        curr = curr->next;
    }
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
    segreagate(LL);
    print(LL);
}