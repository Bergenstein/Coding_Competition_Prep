#pragma once 
#include <vector>

class challenges
{
    public: 
        signed int max_subarr_a(std::vector<int> vect);
        signed int max_subarr_b(std::vector<int> vect);
        signed int max_subarr_c(std::vector<int> vect);
        /*this returns the vector, causin overhead*/
        std::vector<int> sort_arr(std::vector<int> vect);
        /*this sorts in place*/
        void sort_arr_inplace(std::vector<int>& vect);
        /*time complexity: O(n^2). It has two loops*/
        void bubble_sort(std::vector<int>& vect);
        
};




