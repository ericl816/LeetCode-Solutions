struct Node {
	int data;
	Node *left, *right;
};

void helper (Node *root, Node **ref) {
	if (root == NULL) return;
	helper(root->right, ref);
	root->right = *ref;
	if (*ref != NULL) (*ref)->left = root;
	*ref = root;
	helper(root->left, ref);
}

void convertToDLL (Node *root) {
	Node *head = NULL;
	helper(root, &head);
}