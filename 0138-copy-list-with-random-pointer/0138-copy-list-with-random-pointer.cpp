class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if (head == NULL) {
            return NULL;
        }

        // Map original node -> copied node
        unordered_map<Node*, Node*> mp;

        Node* temp = head;

        // Step 1: Create all new nodes
        while (temp != NULL) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Step 2: Connect next and random pointers
        temp = head;

        while (temp != NULL) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];

            temp = temp->next;
        }

        // Return copied head
        return mp[head];
    }
};