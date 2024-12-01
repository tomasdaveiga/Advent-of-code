module DayOne
    ( dayOnePart1
    , dayOnePart2
    ) where

import Data.List (sort)

splitList :: String -> ([Int], [Int])
splitList input = foldr (\a (x,y)-> ((read a :: Int):y, x)) ([],[]) $ words input

dayOnePart1 :: String -> Int
dayOnePart1 input = sum $ zipWith (\x y-> abs (x-y)) (sort left) (sort right)
  where
    (left, right) = splitList input

dayOnePart2 :: String -> Int
dayOnePart2 input = sum similarityScores
    where
      (left, right) = splitList input
      similarityScores = map (\x -> x* (length (filter (==x) right))) left
    