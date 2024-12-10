module DayFour
    ( dayFourPart1
    , dayFourPart2
    ) where

import Data.List ( isPrefixOf, tails, transpose)
import Debug.Trace
debug = flip trace

countXMAS :: String -> Int
countXMAS input = 
    let subs = tails input
    in length (filter (isPrefixOf "XMAS") subs) + length (filter (isPrefixOf "SAMX") subs)

dayFourPart1 :: String -> Int
dayFourPart1 input = sum (map countXMAS (transpose $ lines input)) + sum (map countXMAS (lines input))

dayFourPart2 :: String -> Int
dayFourPart2 input = 0