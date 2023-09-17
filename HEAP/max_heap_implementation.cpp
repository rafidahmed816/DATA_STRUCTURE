#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Heap {
private:
    int *arr;
    int maxSize;
    int size;

public:
    Heap(int heapSize) {
        size = 0;
        maxSize = heapSize;
        arr = new int[heapSize];
        arr[0]=-1;
    }

    void insert(int val) {
        size++;
        int index = size;
        arr[index] = val;

       
    }

    void max_heapify(int i,int n) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;
        if (left <= n && arr[left] > arr[largest])
            largest = left;
        if (right <= n && arr[right] > arr[largest])
            largest = right;
        if (largest != i) {
            swap(arr[largest], arr[i]);
            max_heapify(largest,n);
        }
    }

    //heap sort : ascending
    void heapsort(){
        build_max_heap();
        int i=size;
        while(i>1){
            swap(arr[i],arr[1]);
            i--;
            max_heapify(1,i);
        }

    }

    void print() {
    
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }

    void build_max_heap() {
        for (int i = size / 2; i >= 1; i--)
            max_heapify(i,size);
    }
};

int main() {
    int x;
    Heap h(10000);
    while (cin >> x && x != -1)
        h.insert(x);
    h.build_max_heap();
    cout << "Max Heap: ";
    h.print();
    h.heapsort();
    cout << "Sorted: ";
    h.print();

    return 0;
}
