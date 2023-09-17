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

    void min_heapify(int i,int n) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;
        if (left <= n && arr[left] < arr[smallest])
            smallest = left;
        if (right <= n && arr[right] < arr[smallest])
            smallest = right;
        if (smallest != i) {
            swap(arr[smallest], arr[i]);
            min_heapify(smallest,n);
        }
    }

    //heap sort : ascending
    void heapsort(){
        build_min_heap();
        int i=size;
        while(i>1){
            swap(arr[i],arr[1]);
            i--;
            min_heapify(1,i);
        }
    }

    void print() {
    
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
    }

    void build_min_heap() {
        for (int i = size / 2; i >= 1; i--)
            min_heapify(i,size);
    }
    //heap minimum
    int Heap_Minimum(){
        return arr[1];
    }
    // removes the min element and returns it
    int Heap_extract_min(){
        int value=arr[1];
        //swap last value and min value
        swap(arr[1],arr[size]);
        size--;
        min_heapify(1,size);
        return value;
    }
    void Min_heap_insert(int val){
        size++;
        arr[size]=val;
        int i=size;
        int parent=i/2;
        //beacuse min heap
        while(arr[i]<arr[parent] and i>1){
            swap(arr[i],arr[parent]);
            i/=2;
        }
    }
    void Heap_decrease_key(int i,int val){
        arr[i]-=val;
        min_heapify(i,size);

    }
    void Heap_increase_key(int i,int val){
        arr[i]+=val;
        min_heapify(i,size);
        
    }
};

int main() {
    int x;
    Heap h(10000);
    while (cin >> x && x != -1)
        h.insert(x);
    h.build_min_heap();
    cout << "Max Heap: ";
    h.print();
    //h.heapsort();
  //  cout << "Sorted: ";
   // h.print();

    return 0;
}
