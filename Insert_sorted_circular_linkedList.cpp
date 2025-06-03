#include<iostream> 

using namespace std; 

class Node{
public: 
    int val; 
    Node* next; 
    Node(): val(0), next(NULL){}
    Node(int _val): val(_val), next(NULL){}
    Node(int _val, Node* _next): val(_val), next(_next){}    
};

class Solution{
public: 
     Node* insert(Node* head, int insertVal){
       Node* newNode = new Node(insertVal); 
       if(!head){
         newNode->next = newNode; 
         return newNode; 
       }
       Node* prev = head; 
       Node* tail = head->next; 
       while(tail!=head){
         if(prev->val <= insertVal && insertVal <=tail->val){
           prev->next= newNode; 
           newNode->next= tail; 
           return head; 
         }else if(prev->val > tail->val){
           if(prev->val <= insertVal || insertVal <= tail->val){
             prev->next = newNode; 
             newNode->next = tail; 
             return head; 
           }
         }
         prev = prev->next; 
         tail = tail->next; 
       }
       prev->next = newNode; 
       newNode->next = tail; 
       return head; 
     }
};
void print(Node* head){
  if(!head) cout << "the list is emopty" <<endl; 
  Node* temp = head; 
  do{
    cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main() {
    // Build circular sorted list: 3 → 4 → 1 → back to 3
    Node* n1 = new Node(3);
    Node* n2 = new Node(4);
    Node* n3 = new Node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;
    Node* head = n1;

    cout << "Original list: ";
    print(head);

    // Insert a new value
    Solution sol;
    int insertVal = 2;
    head = sol.insert(head, insertVal);

    cout << "After inserting " << insertVal << ": ";
    print(head);

    return 0;
}
