#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;//data to store
    ListNode *next; //poinrt to next node in list
    ListNode() : val(0), next(nullptr) {} //default constructor
    /*Similar to
    ListNode(){
      val =0;
      next = nullptr;
    }
    */
    ListNode(int x) : val(x), next(nullptr) {}
    /*Similar to
    ListNode(int x){
      val =x;
      next = nullptr;
    }
    */
    
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    /*Similar to
    ListNode(int x, ListNode *next){
      val =x;
      next = next;
    }
    */
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tail = new ListNode(0);  // Creates a dummy node to simplify the code
        ListNode* head = tail;  // Pointer to the tail
        int carry = 0;

        // Continue processing while there are nodes or carry to handle
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;  // Move to next node in l1
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;  // Move to next node in l2
            }
            carry = sum / 10;  // Update carry for the next iteration
            head->next = new ListNode(sum % 10);  // Create a new node with the sum
            head = head->next;  // Move the head to the new node
        }
        return tail->next;  // Return the next node of the dummy node
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(vector<int> vals) {
    ListNode* dummy = new ListNode(0);  // Dummy node to simplify list creation
    ListNode* current = dummy;
    for (int v : vals) {
        current->next = new ListNode(v);  // Create a new node for each value
        current = current->next;  // Move to the next node
    }
    return dummy->next;  // Return the head of the new list (skip the dummy node)
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";  // Print "->" if there is a next node
        head = head->next;  // Move to the next node
    }
    cout << endl;  // End the output with a newline
}

int main() {
    Solution solution;

    // Create sample inputs: (9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9) + (9 -> 9 -> 9 -> 9)
    ListNode* l1 = createList({9, 9, 9, 9, 9, 9, 9});
    ListNode* l2 = createList({9, 9, 9, 9});

    // Add the two numbers
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Output the result: Expected output should be 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1
    printList(result);

    return 0;
}
