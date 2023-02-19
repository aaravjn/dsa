#include <iostream>
#include <vector>
using namespace std;

/*
    Insert the node intially at the end of the tree. Then start comparing it 
    with it's parents. If bigger than it's parents, swap both of them, else terminate
*/


void insert(vector<int> &vec, int a) {
    vec.push_back(a);
    int l = vec.size()-1;
    int p = (l-1)/2;
    while(vec[l] < vec[p]) {
        swap(vec[l], vec[p]);
        l = p;
        p = (l-1)/2;
    }
}


/*
    The max-heapify function ensures that at a given node i, the property of max_heap
    is satisfied. If it is not, then it will swap the i.th element with it's largest child
    and then recursively call upon the largest element.
    if no element is swapped, it will stop.
*/

void max_heapify(vector<int> &vec, int i, int last) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    int mx;
    if(l > last) return ;
    else if(r > last) mx = l;
    else mx = vec[l] > vec[r] ? l : r;
    
    if(vec[mx] > vec[i]) {
        swap(vec[mx], vec[i]);
        max_heapify(vec, mx, last);
    }
}

/*
    build_max_heap function will convert a random array into a max heap by calling
    the heapify function from bottom of the tree upto the root. (n/2->1)
    @note if you call build_max_heap function from i->n/2 it will give incorrect results.
*/

void build_max_heap(vector<int> &vec) {
    int n = vec.size();
    for(int i = n/2;i>=0;i--) {
        max_heapify(vec, i, vec.size()-1);
    }
}

/*
    heap_sort function will use the heap reprersentation to sort the array. It will build a max-heap of
    the array. After that replace the last element of array with root, and discard the last element.
    call the max_heapify function on root and repeat the process. It sorts the array in increasing order.
    @note If you call build_heap function, it will take O(n/2 + logn) time.
*/

void heap_sort(vector<int> &vec) {
    int f = 0, l = vec.size()-1;
    build_max_heap(vec);
    while(f != l) {
        swap(vec[f], vec[l]);
        l--;
        max_heapify(vec, f, l);
    }
}

int main () {
    vector<int> vec = {1, 2, 6, 3, 2, 2, 2};
    heap_sort(vec);
    for(int i = 0;i<vec.size();i++) cout<<vec[i]<<' ';
}