struct Node {
public:
	int data;
	Node *next;
};

/*
 * Reverses linked list in groups of size k and returns pointer to new head node
 */
Node *reverse (Node *head, int k) {
	Node *curr = head, *next = NULL, *prev = NULL;
	int cnt = 0;
	// Reverse first k nodes of linked list
	while (curr != NULL && cnt < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		cnt++;
	}
	// Recursively call for remaining nodes starting from the (k + 1)th one
	if (next != NULL) head->next = reverse(next, k);
	return prev;
}