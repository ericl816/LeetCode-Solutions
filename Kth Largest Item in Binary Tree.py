def kth_largest_item_helper(root, lst):
  '''
  BST Properties:
    - left subtree is less than root value
    - right subtree is greater than root value
  '''
  if not root:
  	return
  kth_largest_item_helper(root.right, items)
  items.append(root.val)
  kth_largest_item_helper(root.left, items)

def kth_largest_item(root, k):
	items = []
	kth_largest_item_helper(root, items)
	return items[k]