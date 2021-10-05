#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node index which is
// an index in arr[]. n is size of heap
void heapify(vector<int>&arr,int n , int index){

    // Initialize largest as root.
    int largest = index; 
    int l = 2 * index + 1; 
    int r = 2 * index + 2;

    // If left child is larger than root
    if(l<n and arr[l] > arr[largest]){
        largest = l;
    }

    // If right child is larger than root
    if(r<n and arr[r] > arr[largest]){
        largest = r;
    }

    // If largest is not root.
    if(largest != index){
        swap(arr[largest], arr[index]);

         // Recursively heapify the affected sub-tree.
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>&arr, int n){
   
    // Build heap (rearrange array).
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap.
    for (int i = n - 1; i > 0; i--) {

         // Move current root to end.
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap.
        heapify(arr, i, 0);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;

    for (int i = 0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    heapSort(arr,n);
    
    for(auto it:arr){
        cout << it << " ";
    }

}