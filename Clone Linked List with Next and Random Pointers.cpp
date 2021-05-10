/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
public:
    Node* copyRandomList(Node* start) {
        if (start == NULL) return NULL;
        Node *curr = start, *temp = NULL;
        // Insert new node after each original node
        while (curr) {
            temp = curr->next;
            // Insert new node
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = start;
        // Adjust random pointers of new nodes
        while (curr) {
            if (curr->next) {
                curr->next->random = curr->random ? curr->random->next : curr->random;
            }
            // Move to next new node by skipping an original node
            curr = curr->next ? curr->next->next : curr->next;
        }
        Node *original = start, *copy = start->next;
        // Save start of copied linked list
        temp = copy;
        // Separate original and copied linked lists
        while (original && copy) {
            original->next = original->next ? original->next->next : original->next;
            copy->next = copy->next ? copy->next->next : copy->next;
            original = original->next;
            copy = copy->next;
        }
        return temp;
    }
};