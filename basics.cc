#include <iostream>
#include <vector>
#include <string> 

/**
 * Calculates the factorial of a number modulo a given modulus.
 *
 * @param n the number to calculate the factorial of
 * @param m the modulus to apply to the factorial
 *
 * @return the factorial of n modulo m
 *
 * @throws None
 */
long long factorial(long long n, int m){
    long long res {1}; //give n = 4, m =10
    //i = 2 => res = (1 * 2)% 10 = 2
    //i = 3 => res = (2 * 3)% 10 = 6
    //i = 4 => res = (6 * 4)% 10 = 4 => res = 4
    for (int i{2}; i <= n; ++i) res=(res*i)%m;
    res = res%m; // => res = 4%10 = 4

    if(res<0) res+=m; // this prevents negative remainders. But make sure that res%m is stored inside of res before that (line above)
    return res;
}

int main(void)
{
    long long res = factorial(4,10);
    std::cout<<res<<"\n";

    double x = 0.4 * 4 + 0.0001 * 2.2;

    std::cout<<"the value is x using cout is: "<<x<<std::endl; 
    std::cout<<"==================="<<std::endl;

    double y = x;

    printf("%.20f\n", y); //this is using c 

    if (abs(x-y)<1e-9) std::cout<<"equal"<<std::endl;

    return 0;

}
