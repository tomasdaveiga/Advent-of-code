module Main (main) where
import DayOne

main :: IO ()
main = do
    contents <- readFile "input/day01.txt"
    print $ dayOnePart1 contents
    print $ dayOnePart2 contents