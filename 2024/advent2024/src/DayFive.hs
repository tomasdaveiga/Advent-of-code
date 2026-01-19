module DayFive
    ( dayFivePart1
    , dayFivePart2
    ) where

import Data.IntMap (IntMap)
import qualified Data.IntMap as M
import Data.List.Split (splitOn)

import Debug.Trace
debug = flip trace

type Rules = IntMap [Int]


parseInput :: [String] -> (Rules, [[Int]])
parseInput ls =
    let parseRule line = case splitOn "|" line of
            [a, b] -> (read a, [read b])
            _ -> error "Malformed input."
        parsePages line = map read $ splitOn "," line
        (rs, rest) = span (/= "") ls
    in (M.fromListWith (++) $ map parseRule rs, map parsePages $ tail rest)


checkSequence :: Rules -> [Int] -> Bool
checkSequence rules seq =
    let go _ [] = True
        go prevPages (a : rest) =
            let shouldBeAfter = M.findWithDefault [] a rules
                violated = any (`elem` prevPages) shouldBeAfter
            in not violated && go (a : prevPages) rest
    in go [] seq

calcMiddlePageSum :: [[Int]] -> Int
calcMiddlePageSum ps =
    let middlePage pages = let n = length pages in pages !! (n `div` 2)
    in sum $ map middlePage ps


fixOrder :: Rules -> [Int] -> [Int]
fixOrder rules seq =
  let go prevPages [] = prevPages
      go prevPages (a : rest) =
        let shouldBeAfter = M.findWithDefault [] a rules
            violated = [(x, i) | (i, x) <- zip [0..] prevPages, x `elem` shouldBeAfter]
            (before, after) = if length violated > 0 then splitAt (snd $ head violated) prevPages else (prevPages, [])
        in go (before ++ [a] ++ after) rest
  in go [] seq

dayFivePart1 :: String -> Int
dayFivePart1 input = calcMiddlePageSum $ filter (checkSequence rules) sequences
  where
    (rules, sequences) = parseInput $ lines input

dayFivePart2 :: String -> Int
dayFivePart2 input = calcMiddlePageSum $ map (fixOrder rules) $ filter (not . checkSequence rules) sequences
  where
    (rules, sequences) = parseInput $ lines input