
> maxSubArr :: [Int] -> Int 
> maxSubArr xs = sum xs

And using recursive definition on lists 

> maxSubArr' :: [Int] -> Int 
> maxSubArr' []     = 0
> maxSubArr' (x:xs) = x + maxSubArr' xs

ghci> maxSubArr [1,2,3,-2,3,5,6]
18
ghci> maxSubArr' [1,2,3,-2,3,5,6]
18