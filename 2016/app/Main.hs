module Main (main) where
import DayOne
import DayTwo

main :: IO ()
main = do
    contentsDay1 <- readFile "input/day01.txt"
    print $ dayOnePart1 contentsDay1
    print $ dayOnePart2 contentsDay1

    contentsDay2 <- readFile "input/day02.txt"
    print $ dayTwoPart1 contentsDay2
    print $ dayTwoPart2 contentsDay2