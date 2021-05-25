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

void delete_duplicates(lptr prev, lptr curr)
{
    if (curr == NULL)
        return;
    if (curr->data == prev->data)
    {
        prev->next = curr->next;
        curr = curr->next;
        delete_duplicates(prev, curr);
    }
    else
    {
        delete_duplicates(curr, curr->next);
    }
}

void delete_duplicates_unsorted(lptr prev, lptr curr, unordered_map<int, int> hash)
{
    if (curr == NULL)
        return;
    if (hash[curr->data] != 0)
    {
        //means present
        prev->next = curr->next;
        delete_duplicates_unsorted(prev, curr->next, hash);
    }
    else
    {
        hash[curr->data] = hash[curr->data] + 1;
        delete_duplicates_unsorted(curr, curr->next, hash);
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
    // delete_duplicates(LL, LL->next);
    // print(LL);
    // unordered_map<int, int> hash;
    // delete_duplicates_unsorted(NULL, LL, hash);
    // print(LL);
    // unordered_map<int, lptr> hash;
    // cout<<hash[2]<<endl;
}