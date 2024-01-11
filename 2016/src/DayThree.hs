module DayThree (dayThreePart1, dayThreePart2) where

import Data.List.Split (splitOn)
import Data.List
import Data.Maybe
import Debug.Trace
debug = flip trace

parseInput :: String -> [[Int]]
parseInput input = map (map read . words) (lines input)

parseFile :: String -> [[Int]]
parseFile input = arrangeLists $ chunksOf 3 $ parseInput input

arrangeLists :: [[[Int]]] -> [[Int]]
arrangeLists [] = []
arrangeLists ([[x1, y1, z1],[x2, y2, z2],[x3, y3, z3]] : xs) = [x1, x2, x3] : [y1, y2, y3] : [z1, z2, z3] : arrangeLists xs

chunksOf :: Int -> [a] -> [[a]]
chunksOf _ [] = []
chunksOf n xs = take n xs : chunksOf n (drop n xs)

checkTriangle :: [Int] -> Maybe Int
checkTriangle inputLine = if (x + y) > z then Just 1 else Nothing
  where
    x = head $ sort inputLine
    y = head $ tail $ sort inputLine
    z = last $ sort inputLine

dayThreePart1 :: String -> Int
dayThreePart1 input = sum $ mapMaybe checkTriangle (parseInput input)

dayThreePart2 :: String -> Int
dayThreePart2 input = sum $ mapMaybe checkTriangle (parseFile input)