# Good pythonicity.

def isValid(tree):
  prev = None
  for val in in_order_traversal(tree):
    if prev is not None and val < prev:
      return False
    prev = node
  return True

def in_order_traversal(tree):
  if tree is not None:
    yield from in_order_traversal(tree.left)
    yield value
    yield from in_order_traversal(tree.right)
