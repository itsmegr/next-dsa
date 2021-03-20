#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *temp)
{
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->bottom;
    }
    cout<<endl;
}

Node *flatten(Node *root);

int main(void)
{
// #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
// #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Node *root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *merge(Node *head1, Node *head2)
{
    Node *newHead = NULL;
    Node *temp;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (newHead == NULL)
            {
                newHead = head1;
                temp = head1;
                head1 = head1->bottom;
            }
            else
            {
                temp->bottom = head1;
                temp = temp->bottom;
                head1 = head1->bottom;
            }
        }
        else
        {
            if (newHead == NULL)
            {
                newHead = head2;
                temp = head2;
                head2 = head2->bottom;
            }
            else
            {
                temp->bottom = head2;
                temp = temp->bottom;
                head2 = head2->bottom;
            }
        }
        temp->bottom = NULL;
    }
    // printList(newHead);

    if(head1==NULL) temp->bottom = head2;
    if(head2==NULL) temp->bottom = head1;
    return newHead;
}
Node *flatten(Node *root)
{
    Node *first, *second;
    if (root == NULL || root->next == NULL)
        return root;
    first = root;
    second = root->next;
    while (second != NULL)
    {
        first = merge(first, second);
        second = second->next;
    }
    return first;
}