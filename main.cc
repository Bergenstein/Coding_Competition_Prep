#include "challenges.h"
#include <iostream>

int main(void)
{
    challenges ch{};
    std::vector<int> my_vec{1,2,3,-2,3,5,6};
    unsigned int res_c=ch.max_subarr_c(my_vec);
    unsigned int res_b=ch.max_subarr_b(my_vec);
    unsigned int res_a=ch.max_subarr_a(my_vec);
    
    std::cout<<"time complexity is O(n): "<<res_c<<std::endl;
    std::cout<<"time complexity is O(n^2):: "<<res_b<<std::endl;
    std::cout<<"time complexity is O(n^3): "<<res_a<<std::endl;

    return 0;
}