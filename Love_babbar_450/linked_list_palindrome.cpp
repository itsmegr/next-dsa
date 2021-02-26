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


void print(lptr LL)
{
    if (LL == NULL)
        return;
    cout << LL->data << " ";
    print(LL->next);
}
void printst(stack<int> st){
    if(st.empty()) return;
    int x = st.top();
    st.pop();
    cout<<x<<" ";
    printst(st);
    st.push(x);
}
bool is_palindrome(lptr ll){
    stack<int> st;
    lptr sp=ll, fp=ll;
    while(fp!=NULL){
        st.push(sp->data);
        sp = sp->next;
        if(fp->next==NULL||fp->next->next==NULL){
            fp = fp->next;
            break;
        }
        fp = fp->next->next;
    }
    printst(st);
    cout<<endl;
    if(fp==NULL) st.pop();
    while(sp!=NULL&&!st.empty()){
        if(sp->data!=st.top()) return false;
        sp = sp->next;
        st.pop();
    }
    return true;
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
    cout<<is_palindrome(LL)<<endl;
}