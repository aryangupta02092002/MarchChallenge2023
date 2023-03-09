//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        // code here
        vector<Node*> ans;
        map<char, int> m1, m2;
        
        for(int i=0; i<s.size(); i++){
            m1[s[i]]++;
        }
        
        Node* previ = NULL, *i = head, *prevj = NULL, *j = head;
        int curr = 0;
        
        while(j != NULL){
            if(curr < s.size()){
                if(j){
                    m2[j->data]++;
                }
                prevj = j;
                if(j){
                    j = j->next;
                }
                curr++;
            }
            else{
                previ = i;
                if(i){
                    i = i->next;
                }
                m2[previ->data]--;
                if(m2[previ->data] == 0){
                    m2.erase(previ->data);
                }
                m2[j->data]++;
                prevj = j;
                if(j){
                    j = j->next;
                }
            }
            
            if(m1 == m2){
                if(previ){
                    previ->next = NULL;
                }
                if(prevj){
                    prevj->next = NULL;
                }
                ans.push_back(i);
                i = j;
                m2.clear();
                curr = 0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends
