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

lptr reverse_in_k(lptr ll, int k)
{
    lptr head;
    lptr prev = NULL;
    lptr curr = ll;
    int count;

    stack<lptr> st;

    while (curr != NULL)
    {
        count = 0;
        while (count < k && curr != NULL)
        {
            st.push(curr);
            curr = curr->next;
            count++;
        }
        while (!st.empty())
        {
            if (prev == NULL)
            {
                prev = st.top();
                head = prev;
                st.pop();
            }
            else
            {
                prev->next = st.top();
                prev = st.top();
                st.pop();
            }
        }
        prev->next = NULL;
    }
    return head;
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

    int k;
    cin >> k;
    lptr LL = NULL;
    int x;
    cin >> x;
    while (x != -1)
    {
        insert(LL, x);
        cin >> x;
    }
    print(reverse_in_k(LL, k));
}