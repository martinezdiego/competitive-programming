 
class MyHashMap {
private:
    struct Node
    {
        int key;
        int val;
        
        bool operator == (const Node & rhs) const {
            return key == rhs.key;
        }
        
        bool operator < (const Node & rhs) const {
            return key < rhs.key;
        }
    };
    
    set<Node> t;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto found = t.find({key, value});
        if (found != t.end()) {
            t.erase(found);
            
        }
        t.insert({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto found = t.find({key, 0});
        if (found != t.end()) {
            return (*found).val;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto found = t.find({key, 0});
        if (found != t.end()) {
            t.erase(found);
            
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
