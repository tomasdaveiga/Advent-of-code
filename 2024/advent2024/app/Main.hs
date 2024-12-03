module Main (main) where

import DayOne
import DayTwo
import DayThree

main :: IO ()
main = do
    dayOneInput <- readFile "input/day01.txt"
    print $ dayOnePart1 dayOneInput
    print $ dayOnePart2 dayOneInput

    dayTwoInput <- readFile "input/day02.txt"
    print $ dayTwoPart1 dayTwoInput
    print $ dayTwoPart2 dayTwoInput

    dayThreeInput <- readFile "input/day03.txt"
    print $ dayThreePart1 dayThreeInput
    print $ dayThreePart2 dayThreeInput