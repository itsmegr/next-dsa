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


void reverse_from_half(lptr ll){
    lptr sp = ll;
    lptr fp = ll;
    lptr prev_to_sp = NULL;

    while(fp!=NULL){
        prev_to_sp = sp;
        sp = sp->next;
        fp = fp->next;
        if(fp==NULL) break;
        fp = fp->next;
    }
    lptr join1 = prev_to_sp;
    lptr joi2 = sp;
    lptr curr = sp, prev = prev_to_sp, next;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    joi2->next = NULL;
    join1->next = NULL;
    // cout<<prev->data<<endl;
    // print(ll);
    // cout<<endl;
    // print(prev);

    lptr curr1 = ll, next1;
    lptr curr2 = prev, next2; //in the half

    while(curr2!=NULL){
        next1 = curr1->next;
        next2 = curr2->next;

        deb2(curr1, curr2);
        curr1->next = curr2;
        curr2->next = next1;
        curr1 = next1;
        curr2 = next2;
    }
    print(ll);
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
    reverse_from_half(LL);
    // print(LL);
}