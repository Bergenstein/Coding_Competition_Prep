#include <algorithm> // copy
#include <iostream> // boolalpha, cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <map> // map
#include <sstream> // istringstream
#include <string> // getline, string
#include <unordered_map> // unordered_map

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}
int main(void)
{
    bool elem {true};
    std::vector<int> arr = get_words<int>();
    
    for(const int& v : arr) {
        std::cout<<v<<std::endl;
    }

    std::cout<<"the val is 1 without boolalpha: "<<elem<<std::endl;
    std::cout<<"the val using bool alpha is no longer 1 but: "<<std::boolalpha<<elem<<std::endl;
    return 0;
}