
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

> sort :: Ord a => [a] -> [a]
> sort [] = []
> sort (x:xs) = sort smaller ++ [x] ++ sort bigger where 
>    smaller = [a | a <- xs , a <= x]
>    bigger  = [b | b <- xs , b > x]

ghci> let myArr = [1,2,3,-2,3,5,6]
ghci> sort myArr 
[-2,1,2,3,3,5,6]