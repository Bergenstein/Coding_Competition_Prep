#include <vector>
#include <iostream>
#include <cmath>

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
// j -> temp ; j_p1 -> j ; temp -> j_p1

int main(void)
{
    std::vector<int> arr{2,5,3,1,0};
    
    std::vector<int> res = insertion_sort(arr);
    for (int i{}; i< res.size(); ++i){
        std::cout<<res.at(i)<<std::endl;
    }

    std::vector<int> res_2 = selection_sort(arr);
    for (int i{}; i< res_2.size(); ++i){
        std::cout<<res_2.at(i)<<std::endl;
    }

    std::vector<int> res_bubble = bubble_sort(arr);
    for (int i{}; i < res_bubble.size(); ++i){
        std::cout<<res_bubble[i]<<"\t";
    }

    std::vector<int> res_mergesort = merge_sort(arr);
    for (int i{}; i < res_mergesort.size(); ++i){
        std::cout<<res_mergesort[i]<<" ";
    }
    return 0;
}