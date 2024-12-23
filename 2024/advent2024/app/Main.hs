module Main (main) where

import DayOne
import DayTwo
import DayThree
import DayFour

main :: IO ()
main = do
    dayOneInput <- readFile "input/day01.txt"
    print $ dayOnePart1 dayOneInput
    print $ dayOnePart2 dayOneInput

    dayTwoInput <- readFile "input/day02.txt"
    print $ dayTwoPart1 dayTwoInput
    print $ dayTwoPart2 dayTwoInput

    dayThreeInput <- readFile "input/day03.txt"
    print ("Day Three part1: " ++ show(dayThreePart1 dayThreeInput))
    print ("Day Three part2: " ++ show(dayThreePart2 dayThreeInput))

    dayFourInput <- readFile "input/day04.txt"
    print ("Day Four part1: " ++ show(dayFourPart1 dayFourInput))
    print ("Day Four part2: " ++ show(dayFourPart2 dayFourInput))