class Solution:
    # The key idea is as follows:
    #   - preorder[0] gives us the current root.
    #   - Finding preorder[0] in inorder tells us where
    #     the left subtree of current root ends. This is because
    #     inorder traversal does (left -> root -> right), so it
    #     only gets to the current root after covering the entire
    #     left subtree.
    #   - Similar for right subtree.
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder: return None
        
        # Preorder[0] is our current root.
        root = TreeNode(preorder[0])
        
        # We find our current root in the inorder traversal.
        ind = inorder.index(root.val)
        
        # We now have two subproblems.
        #
        # First, we compare the preorder of the left subtree
        # of our current root to the inorder of the left subtree.
        # Up to and including ind is the left subtree in preorder.
        left_pre = preorder[1:ind + 1]
        left_in = inorder[:ind]
        root.left = self.buildTree(left_pre, left_in)
        
        # We proceed similarly for the right subtree.
        right_pre = preorder[ind+1:]
        right_in = inorder[ind+1:]
        root.right = self.buildTree(right_pre, right_in)
        return root