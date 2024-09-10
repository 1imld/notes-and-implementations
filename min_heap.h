#include <stdexcept>

using namespace std;

template<typename T>
class minHeap{
private:
	size_t size = 0, capacity = 1;
	T* arr = nullptr;
	int p(int i){ return ((i - 1) >> 1); }
	int l(int i){ return (i << 1 | 1); }
	int r(int i){ return ((i << 1) + 2); }
	void bubbleUp(int i){
		if(i <= 0 || arr[i] >= arr[p(i)])
			return;
		swap(arr[i], arr[p(i)]);
		bubbleUp(p(i));
	}
	void heapify(int i){
		int left = l(i);
		int right = r(i);
		int mn = i;
		if(left < size && arr[left] < arr[i])
			mn = left;
		if(right < size && arr[right] < arr[mn])
			mn = right;
		if(mn != i){
			swap(arr[mn], arr[i]);
			heapify(mn);
		}
	}

public:
	minHeap(){ arr = new T[capacity]; }
	size_t len(){ return size; }
	bool empty(){ return size == 0; }
	T peek(){
		if(this->empty())
		    throw runtime_error("Heap is empty");;
		return arr[0];
	}
	T extract(){
		if(this->empty())
			throw runtime_error("Heap is empty");;
	    T ret = arr[0];
		swap(arr[0], arr[--size]);
		heapify(0);
		return ret;
	}
	void insert(const T& k){
		if(size == capacity){
			capacity <<= 1;
		    T* dummy = new T[capacity];
			for(int i = 0; i < size; i++)
				dummy[i] = arr[i];
			delete[] arr;
			arr = dummy;
		}
		arr[size++] = k;
		bubbleUp(size - 1);
	}
};
