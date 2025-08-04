class Node():
    def __init__(self, value = None, left = None, right = None):
        self.value = value
        self.left = left
        self.right = right
    
class BST():

    def __init__(self):
        self.root = None

    def insertion(self, value, root = None):
        root = self.root
        if root is None:
            return value
        if value > self.left:
            self.insertion(value, self.right)

        

    def search():
        pass
    def delete():
        pass
    def find_min():
        pass
    def find_max():
        pass
