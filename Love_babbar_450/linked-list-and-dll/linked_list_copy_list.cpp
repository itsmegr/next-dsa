#include <bits/stdc++.h>
using namespace std;
typedef struct llnode *lptr;
#define deb(x) cout << #x << "=" << x->data << endl
#define deb2(x, y) cout << #x << "=" << x->data << "," << #y << "=" << y->data << endl
struct llnode
{
    int data;
    llnode *next = NULL;
    llnode *arb = NULL;
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
    if (LL == NULL){
        cout<<endl;
        return;
    }
        
    cout << LL->data << " ";
    print(LL->next);
}

lptr copyList(lptr head) {
    // Your code here
    lptr curr = head;
    lptr temp;
    lptr next;
    while(curr!=NULL){
        temp = new llnode;
        temp->arb = curr->arb;
        temp->data = curr->data;
        next = curr->next;
        curr->next = temp;
        temp->next = next;
        curr = next;
    }
    // curr = head;
    // while(curr!=NULL){
    //     curr->next->arb = curr->arb->next;
    //     curr = curr->next->next;
    // }

    curr = head;
    temp=NULL;
    lptr newList = NULL;
    while(curr!=NULL){
        if(newList==NULL){
            temp = curr->next;
            curr->next = curr->next->next;
            temp->next=NULL;
            curr = curr->next;
            newList = temp;
            deb2(temp, curr);
        }
        else{
            deb2(temp, curr);
            temp->next = curr->next;
            temp  = temp->next;
            curr->next = curr->next->next;
            temp->next=NULL;
            curr = curr->next;
        }
    }
    print(head);
    print(newList);
    return newList;
}

// Node *copyList(Node *head) {
//     // Your code here
//     Node *curr = head;
//     Node *temp;
//     Node *next;
//     while(curr!=NULL){
//         temp = new llnode;
//         temp->arb = curr->arb;
//         temp->data = curr->data;
//         next = curr->next;
//         curr->next = temp;
//         temp->next = next;
//         curr = next;
//     }
//     curr = head;
//     while(curr!=NULL){
//         curr->next->arb = curr->arb->next;
//         curr = curr->next->next;
//     }

//     curr = head;
//     temp=NULL;
//     Node *newList = NULL;
//     while(curr!=NULL){
//         if(newList==NULL){
//             temp = curr->next;
//             curr->next = curr->next->next;
//             temp->next=NULL;
//             // temp->arb = temp->arb->next;
//             curr = curr->next;
//             newList = temp;
//             deb2(temp, curr);
//         }
//         else{
//             deb2(temp, curr);
//             temp->next = curr->next;
//             temp  = temp->next;
//             curr->next = curr->next->next;
//             temp->next=NULL;
//             // temp->arb = temp->arb->next;
//             curr = curr->next;
//         }
//     }
//     // print(head);
//     // print(newList);
//     return newList;
// }
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
    copyList(LL);
}