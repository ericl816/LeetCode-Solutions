def is_encoded(root1, root2):
  '''
  BST Properties:
    - left subtree is less than root value
    - right subtree is greater than root value
  '''
  if root1 != root2:
  	return False
  if not root1 and not root2:
  	return True
  return is_encoded(root1.left, root2.left) and is_encoded(root1.right, root2.right)