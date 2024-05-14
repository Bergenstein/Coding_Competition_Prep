#include "challenges.h"
#include <iostream>
#include "data_structures.hh"

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
    std::cout<<"=============="<<std::endl;
    for (const int& v: ch.sort_arr(my_vec)){
        std::cout<<"sorted vector: "<<v<<std::endl;
    }

    ch.sort_arr_inplace(my_vec);
    for (int i {}; i< my_vec.size(); ++i)
        std::cout<<" : "<<my_vec[i];
        

    std::vector<int> my_vec_b{1,2,3,-2,3,5,6};
    std::cout<<"\n"<<std::endl;

    ch.bubble_sort(my_vec_b);
    
    for (int i {}; i< my_vec.size(); ++i)
        printf("%d\t", my_vec_b[i]);

    return 0;
}