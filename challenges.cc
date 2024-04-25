#include "challenges.h"

signed int challenges::max_subarr_a(std::vector<int> vect)
{
    signed int best{};
    for(int i{}; i < vect.size(); ++i){
        int sum = 0; 
        for (int j=i; j< vect.size(); ++j){
            sum += vect[j];
        }
        best = std::max(best, sum);
    }
    return best;
}

signed int challenges::max_subarr_b(std::vector<int> vect)
{
    signed int best{};
    for (int i{}; i < vect.size(); ++i){
        int sum =0;
        for (int j = i; j< vect.size(); ++j){
            sum+=vect[j];
            best=std::max(best, sum);
        }
    }
    return best;
}

signed int challenges::max_subarr_c(std::vector<int> vect)
{
    signed int best{}, sum{};
    for (int i{}; i< vect.size(); ++i){
        sum=std::max(vect[i], sum+vect[i]);
        best=std::max(best, sum);
    }
    return best;
}

std::vector<int> challenges::sort_arr(std::vector<int> vect)
{
    std::sort(vect.begin(), vect.end());
    return vect;
}

void challenges::sort_arr_inplace(std::vector<int>& vect) {
    std::sort(vect.begin(), vect.end());
}

void challenges::bubble_sort(std::vector<int>& vect) 
{
    int size = vect.size();
    for (int i {}; i< size; ++i){
        for (int j{}; j<size-1; ++j){
            if(vect[j]> vect[j+1]) std::swap(vect[j], vect[j+1]);
        }
    }
}
