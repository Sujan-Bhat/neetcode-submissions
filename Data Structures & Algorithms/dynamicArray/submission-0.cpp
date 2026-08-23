class DynamicArray {
private:
    int *arr;
    int size = 0;
    int capacity = 0;
public:

    DynamicArray(int initCapacity) {
        arr = new int[initCapacity];
        capacity = initCapacity;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(size == capacity){
            resize();
        }
        arr[size] = n;
        size += 1;
    }

    int popback() {
        int ele = arr[size-1];
        size -= 1;
        return ele;
    }

    void resize() {
        int newCapacity = (capacity == 0) ? 1 : (capacity * 2);
        int* newArray = new int[newCapacity];
        for(int i = 0; i < size; i++){
            newArray[i] = arr[i];
        }
        delete[] arr;
        arr = newArray;
        capacity = newCapacity;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
