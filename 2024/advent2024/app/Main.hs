module Main (main) where

import DayOne
import DayTwo
import DayThree
import DayFour
import DayFive
import DaySix

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

    dayFiveInput <- readFile "input/day05.txt"
    print ("Day Five part1: " ++ show (dayFivePart1 dayFiveInput))
    print ("Day Five part2: " ++ show (dayFivePart2 dayFiveInput))

    daySixInput <- readFile "input/day06.txt"
    print ("Day Six part1: " ++ show (daySixPart1 daySixInput))
    print ("Day Six part2: " ++ show (daySixPart2 daySixInput))