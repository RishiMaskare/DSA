# LFU Cache (Least Frequently Used)

## Problem Statement

Design a data structure that follows the constraints of an **LFU (Least Frequently Used) Cache**.

Implement the `LFUCache` class:

- `LFUCache(int capacity)` initializes the cache with the given capacity.
- `int get(int key)` returns the value if the key exists; otherwise returns `-1`.
- `void put(int key, int value)` inserts or updates the key-value pair. If the cache exceeds its capacity, remove the **Least Frequently Used (LFU)** item.

### Tie Breaking Rule

If multiple keys have the same minimum frequency, remove the **Least Recently Used (LRU)** among them.

### Constraints

- `get()` → **O(1)**
- `put()` → **O(1)**

---

# Intuition

Unlike an LRU Cache, simply knowing the order of usage is not enough.

For every key, we must know:

- Its value
- How many times it has been accessed (frequency)
- Among keys with the same frequency, which one was used least recently

Therefore, one linked list is no longer sufficient.

We maintain **one doubly linked list for every frequency**.

Example:

```
Frequency 1

Head <-> 8 <-> 4 <-> Tail

Frequency 2

Head <-> 5 <-> 1 <-> Tail

Frequency 3

Head <-> 7 <-> Tail
```

When a key is accessed:

```
Frequency 1

Head <-> 8 <-> 4 <-> Tail

get(4)

↓

Frequency 1

Head <-> 8 <-> Tail

Frequency 2

Head <-> 4 <-> 5 <-> 1 <-> Tail
```

The frequency increases by one.

---

# Data Structures Used

## 1. Node

Each node stores:

- key
- value
- frequency

```cpp
Node
{
    key
    value
    freq
}
```

---

## 2. Key Table

```cpp
unordered_map<int, list<Node>::iterator>
```

Maps

```
key → node iterator
```

Allows direct access to any node in **O(1)**.

---

## 3. Frequency Table

```cpp
unordered_map<int, list<Node>>
```

Maps

```
frequency → doubly linked list
```

Each frequency has its own LRU list.

Example

```
1 → [8,4]

2 → [5,1]

3 → [7]
```

---

## 4. Minimum Frequency

```
minFreq
```

Stores the minimum frequency currently present in the cache.

This lets us know immediately which list to evict from.

---

# Approach

## get(key)

If key doesn't exist

```
return -1
```

Otherwise

- Find the node.
- Remove it from its current frequency list.
- Increase its frequency.
- Insert it at the front of the next frequency list.
- Update `minFreq` if necessary.
- Return the value.

---

## put(key,value)

### Case 1

Capacity is zero

```
Do nothing.
```

---

### Case 2

Key already exists

- Update value.
- Increase its frequency using `get(key)`.

---

### Case 3

New key

If cache is full

- Go to the list corresponding to `minFreq`.
- Remove the **last** node.
- Delete it from the key table.

Insert the new node into

```
Frequency = 1
```

Update

```
minFreq = 1
```

---

# Dry Run

Capacity = 2

```
put(1,1)

Freq1

1
```

---

```
put(2,2)

Freq1

2 1
```

---

```
get(1)

Freq1

2

Freq2

1
```

---

```
put(3,3)

Cache Full

Minimum Frequency = 1

Remove 2

Insert 3

Freq1

3

Freq2

1
```

---

# Time Complexity

| Operation | Complexity |
|-----------|------------|
| get() | O(1) |
| put() | O(1) |

---

# Space Complexity

- Key Table → **O(capacity)**
- Frequency Lists → **O(capacity)**

Overall

```
O(capacity)
```

---

# C++ Solution

```cpp
class LFUCache {
public:
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    int cap;
    int minFreq;

    unordered_map<int, list<Node>::iterator> keyTable;
    unordered_map<int, list<Node>> freqTable;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {

        if (keyTable.find(key) == keyTable.end())
            return -1;

        auto it = keyTable[key];

        int k = it->key;
        int val = it->value;
        int freq = it->freq;

        freqTable[freq].erase(it);

        if (freqTable[freq].empty()) {
            freqTable.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        freq++;

        freqTable[freq].push_front(Node(k, val, freq));
        keyTable[k] = freqTable[freq].begin();

        return val;
    }

    void put(int key, int value) {

        if (cap == 0)
            return;

        if (keyTable.find(key) != keyTable.end()) {

            keyTable[key]->value = value;
            get(key);
            return;
        }

        if (keyTable.size() == cap) {

            auto node = freqTable[minFreq].back();

            keyTable.erase(node.key);
            freqTable[minFreq].pop_back();

            if (freqTable[minFreq].empty())
                freqTable.erase(minFreq);
        }

        minFreq = 1;

        freqTable[1].push_front(Node(key, value, 1));
        keyTable[key] = freqTable[1].begin();
    }
};
```

---

# Key Interview Takeaways

- LFU Cache is an extension of LRU Cache.
- Every key maintains its access frequency.
- Maintain a separate LRU list for each frequency.
- `minFreq` enables O(1) identification of the eviction list.
- On every `get()`, move the node from frequency `f` to `f + 1`.
- When multiple keys have the same frequency, evict the Least Recently Used (back of that frequency list).

---

**Difficulty:** Hard  
**Pattern:** Design + Hash Map + Doubly Linked List + Frequency Counting  
**Time Complexity:** `O(1)` for both `get()` and `put()`  
**Space Complexity:** `O(capacity)`
