module DayFour
    ( dayFourPart1
    , dayFourPart2
    ) where

import Data.List ( isPrefixOf, tails, transpose)
import Data.Universe.Helpers (diagonals)
import Debug.Trace
debug = flip trace

countXMAS :: String -> Int
countXMAS input = 
    let subs = tails input
    in length (filter (isPrefixOf "XMAS") subs) + length (filter (isPrefixOf "SAMX") subs)

dayFourPart1 :: String -> Int
dayFourPart1 input = sum (map countXMAS cols) + sum (map countXMAS lins) + sum (map countXMAS diags) + sum (map countXMAS anti_diags)
  where
    lins = lines input
    cols = transpose lins
    diags = diagonals lins
    anti_diags = diagonals (map reverse lins)

dayFourPart2 :: String -> Int
dayFourPart2 input = 0