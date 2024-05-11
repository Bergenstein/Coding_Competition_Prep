from typing import List 
from collections import deque

def stack(program: List[str]) -> List[int]:
    stack = []
    for instruction in program:
        if instruction == "peek":
            print(stack[-1])
        elif instruction == "pop":
            if len(stack) > 0:
                stack.pop()
        else:
            data = int(instruction[5:])
            stack.append(data)
    return stack 

def queue(program: List [str]) -> List[int]:
    queue = deque()
    for instruction in program:
        if instruction == "peek":
            print(queue[0]) if queue else print("Queue is empty")
        elif instruction == "pop":
            if queue:
                queue.popleft()
            else:
                print("Queue Empty")
        else:
            data = int(instruction[5:])
            queue.append(data)