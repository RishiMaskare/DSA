# LRU Cache (Least Recently Used)

## Problem Statement

Design a data structure that follows the constraints of an **LRU (Least Recently Used) Cache**.

Implement the `LRUCache` class:

- `LRUCache(int capacity)` initializes the cache with a positive size.
- `int get(int key)` returns the value of the key if it exists; otherwise returns `-1`.
- `void put(int key, int value)` inserts or updates the value. If the cache exceeds its capacity, remove the **Least Recently Used (LRU)** item.

### Constraints
- `get()` → **O(1)**
- `put()` → **O(1)**

---

# Intuition

The cache should always know:

1. Whether a key exists.
2. Which key was used most recently.
3. Which key was used least recently.

Using only an array or vector would make moving elements expensive (`O(n)`).

To achieve **O(1)** operations, we combine:

- **Hash Map (`unordered_map`)**
  - Stores `key → node address`
  - Provides constant-time lookup.

- **Doubly Linked List**
  - Maintains the order of usage.
  - Front → Most Recently Used (MRU)
  - Back → Least Recently Used (LRU)

Whenever a key is accessed or updated, move it to the front.

When the cache is full, remove the node at the back.

---

# Data Structures Used

## 1. Doubly Linked List

Each node stores:

- key
- value
- previous pointer
- next pointer

```
Head <-> Node1 <-> Node2 <-> Node3 <-> Tail
```

Dummy head and tail nodes are used to simplify insertion and deletion.

---

## 2. Hash Map

```
unordered_map<int, Node*>
```

Maps every key to its corresponding node in the linked list.

This allows locating any node in **O(1)** time.

---

# Approach

### Helper Function: Add Node

Insert a node immediately after the head.

This makes the node the **Most Recently Used (MRU)**.

```
Head <-> Tail

Insert X

Head <-> X <-> Tail
```

---

### Helper Function: Delete Node

Remove a node from its current position.

```
A <-> B <-> C

Delete B

A <-> C
```

---

### get(key)

- If key is absent, return `-1`.
- Otherwise:
  - Find the node using the hash map.
  - Remove it from its current position.
  - Insert it at the front.
  - Return its value.

---

### put(key, value)

#### Case 1: Key already exists

- Update its value.
- Move it to the front.

---

#### Case 2: Key doesn't exist

If cache is full:

- Remove the node just before the tail.
- Delete it from the hash map.

Create a new node.

Insert it at the front.

Store it in the hash map.

---

# Dry Run

Capacity = 2

```
put(1,1)

Head <-> 1 <-> Tail
```

```
put(2,2)

Head <-> 2 <-> 1 <-> Tail
```

```
get(1)

Head <-> 1 <-> 2 <-> Tail
```

```
put(3,3)

Cache Full

Remove 2

Head <-> 3 <-> 1 <-> Tail
```

---

# Time Complexity

| Operation | Complexity |
|-----------|------------|
| get() | O(1) |
| put() | O(1) |
| addNode() | O(1) |
| deleteNode() | O(1) |

---

# Space Complexity

- Hash Map: **O(capacity)**
- Doubly Linked List: **O(capacity)**

Overall:

```
O(capacity)
```

---

# C++ Solution

```cpp
class Node {
public:
    int key, value;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {

            Node* existing = mp[key];

            existing->value = value;

            deleteNode(existing);
            addNode(existing);

            return;
        }

        if (mp.size() == capacity) {

            Node* lru = tail->prev;

            deleteNode(lru);

            mp.erase(lru->key);

            delete lru;
        }

        Node* node = new Node(key, value);

        addNode(node);

        mp[key] = node;
    }
};
```

---

# Key Interview Takeaways

- Use a **Hash Map** for constant-time lookup.
- Use a **Doubly Linked List** for constant-time insertion and deletion.
- Keep the **Most Recently Used** node at the front.
- Evict the **Least Recently Used** node from the back when capacity is exceeded.
- Dummy head and tail nodes eliminate edge cases during insertion and deletion.

---
**Difficulty:** Hard  
**Pattern:** Design + Hashing + Doubly Linked List  
**Time Complexity:** `O(1)` for both `get()` and `put()`  
**Space Complexity:** `O(capacity)`
