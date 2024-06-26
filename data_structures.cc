#include "data_structures.hh"
#include <iostream>



std::stack<int> DataStructure::stack_exec(std::vector<std::string> program)
{
    //initialize the stack
    std::stack<int> stack;
    for(std::string instruction : program){
        if(instruction == "peak"){
            std::cout<<stack.top()<<std::endl;
        } else if (instruction == "pop"){
            if (!stack.empty()){
                stack.pop();
            }
            else throw std::exception{}; 
        }
        else{
            try {
                int data{std::stoi(instruction.substr(5))};
                stack.push(data);
            } catch(std::invalid_argument& inval){
                std::cout<<"the error is: "<<inval.what()<<std::endl;
            } catch(std::out_of_range& outrng){
                std::cout<<"out of range: "<<outrng.what()<<std::endl;
            }
        }
    }
    return stack;
}

std::deque<int> DataStructure::process_queue(std::vector<std::string> program_instructions){
    std::deque<int> queue;
    for(std::string& s : program_instructions){
        if (s == "peak" && !queue.empty())
            std::cout<<queue.front()<<std::endl;
        else if (s == "pop" && queue.empty())
            throw std::exception{};
        else if (s == "pop" && !queue.empty())
            queue.pop_front();
        else if (s.substr(0, 5) == "push "){
            int data = std::stoi(s.substr(5));
            queue.push_back(data);
        }
        else throw std::exception{}; 
    }
    return queue;
}

void DataStructure::ignore_line(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template<typename T>
void DataStructure::put_words(const std::vector<T>& v){
    if(!v.empty()){
        //std::copy copies a range of elems from one container to the other. Here we are copying from the vector to the output stream. Using std::prev(v.end()) we are copying all the way up to but excluding the last element
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout<< v.back();
    }
    std::cout<< '\n';
}