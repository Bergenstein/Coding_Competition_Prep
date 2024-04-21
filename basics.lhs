> fact :: (Num a, Eq a) => a -> a 
> fact 0 = 1 
> fact 1 = 1
> fact n = n * fact (n-1)

> factorial :: Integral a => a -> a -> a
> factorial n m = foldl (\res i -> (res * i) `mod` m) 1 [2..n]
