/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity. */  


 /************************ approach 1 ************************************ */ 
  /* the intution is that we will follow the  pattern the question say to d othe get and push function we will
    use the  map for stroing the freq and the list or set in  pair  for get and push in  O(1).*/ 
     
     /* time complexity O(1)
        space complexity O(n) 
        leetcode link =   https://leetcode.com/problems/lru-cache/?envType=study-plan-v2&envId=top-interview-150 */ 
          class LRUCache {
    int capacity;
    list<pair<int, int>> dll; // Doubly Linked List: {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> cache; // key -> iterator in dll

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // Move accessed node to front
        dll.splice(dll.begin(), dll, cache[key]);
        return cache[key]->second;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update value and move to front
            cache[key]->second = value;
            dll.splice(dll.begin(), dll, cache[key]);
        } else {
            // Insert new node
            if (dll.size() == capacity) {
                // Remove LRU from both list and map
                int lruKey = dll.back().first;
                dll.pop_back();
                cache.erase(lruKey);
            }
            dll.emplace_front(key, value);
            cache[key] = dll.begin();
        }
    }
};
