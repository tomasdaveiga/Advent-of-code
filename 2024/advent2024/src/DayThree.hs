module DayThree
    ( dayThreePart1
    , dayThreePart2
    ) where

import Text.Regex.TDFA
import Text.Regex.TDFA.Text()
import Data.List (isInfixOf)
import Data.Maybe (mapMaybe, fromJust)
import Debug.Trace
debug = flip trace

getMults :: String -> [(Int,Int)]
getMults input = mapMaybe getTuples cases
  where
    cases = getAllTextMatches (input =~ "mul\\([0-9]+,[0-9]+\\)") :: [String]

getTuples :: String -> Maybe (Int, Int)
getTuples input 
 | "mul" `isInfixOf` input = Just (head cases, last cases)
 | otherwise = Nothing
 where
    cases = map read $ getAllTextMatches (input =~ "[0-9]+" :: AllTextMatches [] String)

getMultsDosDonts :: String -> [String]
getMultsDosDonts input = getAllTextMatches (input =~ "mul\\([0-9]+,[0-9]+\\)|do\\(\\)|don\'t\\(\\)") :: [String]

gothrough :: [String] -> Bool -> [(Int, Int)]
gothrough input status = fst $ foldl eachIndi ([], status) input
  where
    eachIndi :: ([(Int, Int)], Bool) -> String -> ([(Int, Int)], Bool)
    eachIndi (prev, status) input
      | "mul" `isInfixOf` input && status = (prev++[fromJust $ getTuples input], status)
      | "mul" `isInfixOf` input && not status = (prev, status)
      | "don't()" `isInfixOf` input = (prev, False)
      | "do()" `isInfixOf` input = (prev, True)

dayThreePart1 :: String -> Int
dayThreePart1 input = sum $ map (\(x,y) -> x*y) (getMults input)

dayThreePart2 :: String -> Int
dayThreePart2 input = sum $ map (\(x,y) -> x*y) (gothrough (getMultsDosDonts input) True) `debug` show ((getMultsDosDonts input))