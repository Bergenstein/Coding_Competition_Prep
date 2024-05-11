#pragma once 
#include <algorithm>
#include <iterator>
#include <limits>
#include <stack>
#include <string>
#include <vector>
#include <utility>

class DataStructure {
    public:
        std::stack<int> execute(std::vector<std::string> program);

        /** Ignores the rest of the current line in the input stream.
        * @throws None
        */
        void ignore_line();
        template<typename T>
        void put_words(const std::vector<T>& v);
};