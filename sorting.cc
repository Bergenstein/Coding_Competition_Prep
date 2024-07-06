#include <vector>
#include <iostream>
#include <cmath>

#include <algorithm> // for std::swap

/**
 * Partitions the array based on a selected pivot element midpoint for better
 * efficiency, higher likelihood of n log n.
 *
 * @param arr the vector to be partitioned
 * @param low the lower index of the array
 * @param high the higher index of the array
 *
 * @return the index where the pivot element is placed after partitioning
 *
 * @throws None
 */
int partition(std::vector<int>& arr, int low, int high) {
    int pivotIndex = low + (high - low) / 2; // Middle element as pivot
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[high]); // Move pivot to end
    int storeIndex = low;

    for (int i = low; i < high; i++) {
        if (arr[i] < pivotValue) {
            std::swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(arr[storeIndex], arr[high]); // Move pivot to its final place
    return storeIndex;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1); // Recursively sort elements before partition
        quickSort(arr, p + 1, high); // Recursively sort elements after partition
    }
}

// Public function to start quicksort on the entire vector
std::vector<int> qsort(std::vector<int>& unsorted_list) {
    quickSort(unsorted_list, 0, unsorted_list.size() - 1);
    return unsorted_list;
}

std::vector<int> insertion_sort(std::vector<int> arr){
    for (int i{}; i< arr.size(); ++i){
        int idx = i;
        while(arr[idx] < arr[idx-1] && idx > 0 ){
            int temp = arr[idx]; 
            arr[idx] = arr[idx-1];
            arr[idx-1] = temp;
            idx --;
        }
    }
    return arr;
}

std::vector<int> selection_sort(std::vector<int> &vec)
{
    for(int i{}; i < vec.size(); ++i){
        int min_idx = i; // pick any idx as min_idx 
        //iterate through the vector once 
        for(int j{i}; j < vec.size(); ++j){
            if (vec.at(min_idx) > vec.at(j))
                min_idx = j; //j is smaller so j is stored in min_idx now
        }
        //after this iteration we have the correct min_idx, 
        //now swap
        int temp {vec[i]};
        vec[i] = vec[min_idx]; 
        vec[min_idx] = temp;
    }
    return vec; 
}

std::vector<int> bubble_sort(std::vector<int> &vec)
{   
    //reverse iteration 
    for (int i=vec.size()-1; i>=0; --i){
        bool swapped = false; 
        for(int j{}; j < i; ++j){
            if(vec.at(j) > vec.at(j+1)){ //swap is needed
                int temp {vec[j]};
                vec[j] = vec[j+1];
                vec[j+1] = temp;
                swapped = true;
            } 
        }
        if (!swapped) return vec; 
    }
    return vec;
}

std::vector<int> merge_sort(std::vector<int> vec)
{
    std::vector<int> merged_vec{};
    int n = vec.size();
    //1. base case: 
    if (n <= 1) return vec; 

    //2. midpoint 
    int mid = floor(n/2);

    //3. make resursively sorting calls. The sorting step 
    std::vector<int> left_sub = merge_sort(std::vector<int>(vec.begin(), 
                                        vec.begin()+mid));
    std::vector<int> right_sub = merge_sort(std::vector<int> 
                                        (vec.begin()+mid, vec.end()));

    //4. The merging step:

    int right{}, left{}; //double pointers
    
    while(right < n - mid || left < mid){ // the pointers haven't exceeded the subarrs
        if(right == n-mid) { // empty subarr. So, just push back the merged left
            merged_vec.push_back(left_sub.at(left));
            left++;
        }
        else if (left == mid) { // empty left 
            //call merge sort on the right subarr
            merged_vec.push_back(right_sub.at(right));
            right++;
        }
        else if (right_sub[right] <= left_sub[left]) {//right elems are smaller.
            merged_vec.push_back(right_sub[right]);
            right++;
        }
        else if (right_sub[right] > left_sub[left]) {//left elems are smaller.
            merged_vec.push_back(left_sub.at(left));
            left++;
        }
    } 

    return merged_vec;

}

void quick_sort_inorder(std::vector<int> vec, int start, int end)
    {
        //base case 
        int size = vec.size();
        if (size <= 1) return;
        if (start - end <= 1) return;

        int pivot = vec[end-1];
        int left_ptr {start};
        int right_ptr{end - 1};

        while(left_ptr < right_ptr){
            while(vec[left_ptr] <= pivot){
                left_ptr++;
            }
            while(vec[right_ptr >= pivot]){
                right_ptr --;
            }
            if(left_ptr == right_ptr) break; 
            
            int temp = vec[left_ptr];
            vec[left_ptr] = vec[right_ptr];
            vec[right_ptr] = temp;  

        }
        int temp = pivot; 
        pivot = vec[left_ptr]; 
        vec[left_ptr] = temp;

        //recursion
        quick_sort_inorder(vec, start, left_ptr);
        quick_sort_inorder(vec, left_ptr+1, end);
        //pivot -> temp; left -> pivot; temp -> left 
    }

    std::vector<int> quick_sort(std::vector<int> vec){
        quick_sort_inorder(vec, 0, vec.size());
        return vec;
    }

// j -> temp ; j_p1 -> j ; temp -> j_p1

int main(void)
{
    std::vector<int> arr{2, 16, 5, 9, 1, 3, 1, 0, 7};
    
     std::cout<<"\n"<<std::endl;
    std::cout<<"SELECTION SORT RESULTS: "<<std::endl;

    std::vector<int> res = insertion_sort(arr);
    for (int i{}; i< res.size(); ++i){
        std::cout<<res.at(i)<<" ";
    }

     std::cout<<"\n"<<std::endl;

    std::cout<<"SELECTION SORT RESULTS: "<<std::endl;

    std::vector<int> res_2 = selection_sort(arr);
    for (int i{}; i< res_2.size(); ++i){
        std::cout<<res_2.at(i)<<" ";
    }
     std::cout<<"\n"<<std::endl;

    std::cout<<"BUBBLE SORT RESULTS: "<<std::endl;

    std::vector<int> res_bubble = bubble_sort(arr);
    for (int i{}; i < res_bubble.size(); ++i){
        std::cout<<res_bubble[i]<<" ";
    }
    
     std::cout<<"\n"<<std::endl;

    std::cout<<"MERGE SORT RESULTS: "<<std::endl;

    std::vector<int> res_mergesort = merge_sort(arr);
    for (int i{}; i < res_mergesort.size(); ++i){
        std::cout<<res_mergesort[i]<<" ";
    }

    std::cout<<"\n"<<std::endl;
    std::cout<<"QUICK SORT RESULTS: "<<std::endl;

    std::vector<int> res_quicksort=quick_sort(arr);
    for (int i{}; i < res_quicksort.size(); ++i){
        std::cout<<res_quicksort[i]<<" ";
    }

    std::cout<<"\n"<<std::endl;
    std::cout<<"QSORT RESULTS: "<<std::endl;
    
    std::vector<int> res_qsort=qsort(arr);
    for (int i{}; i < res_qsort.size(); ++i){
        std::cout<<res_qsort[i]<<" ";
    }


    return 0;
}

