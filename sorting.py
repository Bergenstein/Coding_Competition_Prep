from typing import List 
import numpy as np 

def insertion_sort(arr: List[int]) -> List[int]:
    for i in range (1, len(arr)):
        j = i 
        while(arr[j]< arr[j-1] and j > 0):
            arr[j], arr[j-1] = arr[j-1], arr[j] 
            j-=1 
    return arr 

def insertion_sort_v2(arr: List[int]) -> List[int]:
    for i in range(len(arr)):
        idx = i
        while(arr[idx] < arr[idx-1] and idx > 0):
            temp = arr[idx] 
            arr[idx] = arr[idx - 1]
            arr[idx - 1] = temp 
            idx -= 1 
    return arr 
 
def selection_sort(arr: List[int]) -> List[int]:
    for i in range(len(arr)):
        min_idx = i 
        for j in range(i, len(arr)):
            if (arr[min_idx] > arr[j]):
                min_idx = j 
        arr[min_idx], arr[i] = arr[i], arr[min_idx]
    return arr 

def selection_sort_v2(arr: List[int]) -> List[int]:
    for i in range(len(arr)):
        min_idx = i 
        for j in range(i, len(arr)):
            if arr[min_idx] > arr[j]:
                #swap indices 
                j = min_idx 
        temp: int = arr[i]
        arr[i] = arr[min_idx] 
        arr[min_idx] = temp 
    return arr 

def bubble_sort(arr: List[int]) -> List[int]:

    for i in reversed(range(len(arr))):
        print(f"the value of i = {i}")
        
        swapped = False 
        for j in range (i):
            print("\n")
            print(f"the value of j = {j}")
            if (arr[j] < arr[j+1]):
                arr[j+1], arr[j] = arr[j], arr[j+1]
                swapped = True 
        if swapped == False:
            return arr 
    return arr 


def merge_sort(arr: List[int]) -> List[int]:
    n: int = len(arr)
    mid: int = np.floor(n/2).astype(int)
    #base case
    if n <= 1: return arr 

    #recursive sorting 
    left_arr: List[int] = merge_sort(arr[:mid])
    right_arr: List[int] = merge_sort(arr[mid:])

    #two pointers 
    left : int = 0 ; right : int = 0
    # resulting array
    sorted_arr: List[int] = []

    while(left < mid or right < n - mid):
        if (left == mid): # empty left-> call mergesort on right and append
            sorted_arr.append(right_arr[right])
            right +=1 
        elif right == n - mid : 
            sorted_arr.append(left_arr[left])
            left+=1
        elif right_arr[right]>= left_arr[left]:
            sorted_arr.append(left_arr[left])
            left+=1 
        else: 
            sorted_arr.append(right_arr[right])
            right +=1 
    return sorted_arr

test_arr = [2,5,3,1,0]

print(insertion_sort(test_arr))

print(insertion_sort_v2(test_arr))

print(selection_sort(test_arr))

print(selection_sort_v2(test_arr))

print(bubble_sort(test_arr))

print(f"merge sort res = {merge_sort(test_arr)}")