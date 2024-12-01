module Main (main) where

import DayOne

main :: IO ()
main = do
    dayOneInput <- readFile "input/day01.txt"
    print $ dayOnePart1 dayOneInput
    print $ dayOnePart2 dayOneInput