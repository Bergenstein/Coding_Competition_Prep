#pragma once 
#include <algorithm>
#include <iterator>
#include <limits>
#include <stack>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <utility>

class DataStructure {
    public:
        std::stack<int> stack_exec(std::vector<std::string> program);

        std::deque<int> process_queue(std::vector<std::string> program_instructions);
        
        /** Ignores the rest of the current line in the input stream.
        * @throws None
        */
        void ignore_line();
        template<typename T>
        void put_words(const std::vector<T>& v);
};