module Main (main) where
import DayOne
import DayTwo
import DayThree

main :: IO ()
main = do
    contentsDay1 <- readFile "input/day01.txt"
    print $ "Day01 part 1: " <> show (dayOnePart1 contentsDay1)
    print $ "Day01 part 2: " <> show (dayOnePart2 contentsDay1)

    contentsDay2 <- readFile "input/day02.txt"
    print $ "Day02 part 1: " <> show (dayTwoPart1 contentsDay2)
    print $ "Day03 part 2: " <> show (dayTwoPart2 contentsDay2)

    contentsDay3 <- readFile "input/day03.txt"
    print $ "Day03 part 1: " <> show (dayThreePart1 contentsDay3)
    print $ "Day03 part 2: " <> show (dayThreePart2 contentsDay3)