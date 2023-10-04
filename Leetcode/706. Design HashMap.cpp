#define EMPTY -1
#define BUF_SIZE 1000001

class MyHashMap {
private:
    int buf[BUF_SIZE];

public:
    MyHashMap() {
        memset(buf, EMPTY, BUF_SIZE * sizeof(int));
    }
    
    void put(int key, int value) {
        buf[key] = value;
    }
    
    int get(int key) {
        return buf[key];
    }
    
    void remove(int key) {
        buf[key] = EMPTY;
    }
};