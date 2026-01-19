module DayFour
    ( dayFourPart1
    , dayFourPart2
    ) where

import Data.List ( isPrefixOf, tails, transpose)
import Data.Universe.Helpers (diagonals)

submatrix :: [String] -> Int -> Int -> [String]
submatrix matrix i j =
  [take 3 (drop j row) | row <- take 3 (drop i matrix)]


allSubmatrices :: [String] -> [[String]]
allSubmatrices matrix =
  [submatrix matrix i j | i <- [0..rows-3], j <- [0..cols-3]]
  where
    rows = length matrix
    cols = if null matrix then 0 else length (head matrix)

countXMAS :: String -> Int
countXMAS input = 
    let subs = tails input
    in length (filter (isPrefixOf "XMAS") subs) + length (filter (isPrefixOf "SAMX") subs)

countMAS :: [String] -> Int
countMAS array = 
    let diags = filter ((==3) . length) (diagonals array ++ diagonals (map reverse array))
    in if length (filter (\d -> isPrefixOf "MAS" d || isPrefixOf "SAM" d) diags) == 2 then 1 else 0


dayFourPart1 :: String -> Int
dayFourPart1 input = sum (map countXMAS cols) + sum (map countXMAS lins) + sum (map countXMAS diags) + sum (map countXMAS anti_diags)
  where
    lins = lines input
    cols = transpose lins
    diags = diagonals lins
    anti_diags = diagonals (map reverse lins)

dayFourPart2 :: String -> Int
dayFourPart2 input = sum $ map countMAS subs
  where
    subs = allSubmatrices $ lines input
