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


