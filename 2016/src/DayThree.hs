module DayThree (dayThreePart1, dayThreePart2) where

import Data.List.Split (splitOn)
import Data.List
import Data.Maybe

checkTriangle :: String -> Maybe Int
checkTriangle inputLine = if (x + y) > z then Just 1 else Nothing
  where
    numbers = sort $ map read (words inputLine)
    x = head numbers
    y = head $ tail numbers
    z = last numbers

dayThreePart1 :: String -> Int
dayThreePart1 input = sum $ mapMaybe checkTriangle (splitOn "\n" input)

dayThreePart2 :: String -> String
dayThreePart2 input = "aa"