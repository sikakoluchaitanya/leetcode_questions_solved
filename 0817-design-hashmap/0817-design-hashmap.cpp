class MyHashMap {
private:
    vector<int> x;

public:
    MyHashMap() : x(1000001, -1) {
    }

    void put(int key, int value) {
        if (key >= 0 && key < 1000001) {
            x[key] = value;
        }
    }

    int get(int key) {
        if (key >= 0 && key < 1000001) {
            return x[key];
        }
        return -1; // Key is out of range.
    }

    void remove(int key) {
        if (key >= 0 && key < 1000001) {
            x[key] = -1;
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