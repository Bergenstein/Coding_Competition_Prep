> import qualified Data.Map as Map

-- This function takes a list and returns a Map with counts of each element

> getCounter :: (Ord a) => [a] -> Map.Map a Int
> getCounter arr = foldl (\acc x -> Map.insertWith (+) x 1 acc) Map.empty arr

> data Result = Result Int deriving Show

> processList :: [Int] -> Result
> processList lst = Result $ sum lst



> main :: IO ()
> main = do
>     putStrLn "Enter a list of integers separated by space:"
>     input <- getLine
>     let numbers = map read $ words input :: [Int]
>     let counter = getCounter numbers
>     print counter