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
bool loop_detection(lptr ll)
{
    lptr sp = ll;
    lptr fp = ll;
    while (true)
    {
        sp = sp->next;
        fp = fp->next;
        if (fp == NULL)
            return false;
        fp = fp->next;
        if (fp == NULL)
            return false;
        if (sp == fp)
            return true;
    }
}
// bool loop_detection(ListNode * ll)
// {
//     ListNode * sp = ll;
//     ListNode * fp = ll;
//     while (true)
//     {
//         sp = sp->next;
//         fp = fp->next;
//         if (fp == NULL)
//             return false;
//         fp = fp->next;
//         if (fp == NULL)
//             return false;
//         if (sp == fp)
//             return true;
//     }
// }

void removeLoop(lptr ll)
{
    lptr sp = ll;
    lptr fp = ll;
    lptr prev = NULL;
    while (true)
    {
        prev = sp;
        sp = sp->next;
        fp = fp->next;
        if (fp == NULL)
            return;
        fp = fp->next;
        if (fp == NULL)
            return;
        if (sp == fp)
            break;
    }

    fp = ll;
    while(sp!=fp){
        prev = sp;
        sp = sp->next;
        fp = fp->next;
    }

    prev->next = NULL;

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
}