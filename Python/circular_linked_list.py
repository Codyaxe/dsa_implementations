class Node():
    def __init__(self, value = None, next = None):
        self.value = value
        self.next = next

class Linked_List():

    def __init__(self):
        self.head = None
        self.size = 0

    def insert(self, value, index):
        current = self.head
        if index == 0:
            self.prepend(value)
            return
        if index == self.size:
            self.append(value)
            return
        if index > self.size - 1:
            print("Index range out of bounds!")
        else:
            for i in range(index - 1):
                current = current.next
            new_node = Node(value, current.next)
            current.next = new_node
            self.size += 1

    def append(self, value):
        current = self.head
        if self.size == 0:
            new_node = Node(value)
            self.head = new_node
            new_node.next = self.head
            self.size += 1
        else:
            current = self.traverse(current)
            new_node = Node(value, self.head)
            current.next = new_node
            self.size += 1

    def prepend(self, value):
        current = self.head
        if self.size == 0:
            new_node = Node(value)
            self.head = new_node
            new_node.next = self.head
            self.size += 1
        else:
            current = self.traverse(current)
            new_node = Node(value, self.head)
            current.next = new_node
            self.head = new_node
            self.size += 1

    def delete(self, index):
        current = self.head
        if index == 0:
            self.head = current.next
            self.size -= 1
            return
        if index > self.size - 1:
            print("Index range out of bounds!")
        else:
            for i in range(index - 1):
                current = current.next
            if current.next is not self.head:
                current.next = current.next.next
                self.size -= 1
            else:
                current.next = self.head
                self.size -= 1

    def traverse(self, pointer):
        while pointer.next is not self.head:
            pointer = pointer.next
        return pointer
    
    def search(self, value):
        current = self.head
        for i in range(self.size):
            if current.value == value:
                print(f"{value} is at index {i}")
                return
            else:
                current = current.next
        print(f"{value} cannot be found!")

    def print(self):
        current = self.head
        for i in range(self.size):
            print(f"{current.value} -> ", end = "")
            current = current.next
        print(current.value, "< HEAD")

# test = Linked_List()
# test.append(2)
# test.append(4)
# test.append(5)
# test.print()
# test.delete(2)
# test.print()
# test.prepend(8)
# test.print()
# test.prepend(9)
# test.print()
# test.search(4)
# test.insert(20, 1)
# test.print()
# test.insert(20, 4)
# test.insert(99, 6)
# test.print()
