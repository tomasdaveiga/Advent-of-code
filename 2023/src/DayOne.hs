module DayOne (dayOnePart1, dayOnePart2) where
import qualified Data.Map as Map
import Data.List (isInfixOf, findIndex,tails)
import Data.Maybe
import Data.List.Split (splitOn)
import Data.Char (isDigit, isAlpha)

import Debug.Trace
debug = flip trace

digitMap :: Map.Map String Int
digitMap = Map.fromList
  [ ("zero", 0)
  , ("one" , 1)
  , ("two" , 2)
  , ("three",3)
  , ("four", 4)
  , ("five", 5)
  , ("six" , 6)
  , ("seven",7)
  , ("eight",8)
  , ("nine", 9)
  ]
digitList :: [String]
digitList = ["one","two","three","four","five","six","seven","eight","nine"]

findNumber :: String -> Maybe (Int, Char)
findNumber str = do
  let index = (fromJust (findIndex (`isInfixOf` digitList) str))
  let digit = str !! index
  return (index-1, digit) `debug` ("findNumber: input: " <> str <> ". (index, digit): " <> show ((index, str !! index)) )

getSpelledDigits :: String -> Int
getSpelledDigits input = fst $ fromJust $ findNumber input

getLiteralDigits :: String -> Int
getLiteralDigits input = read ((take 1 (filter isDigit input)) <> take 1 (reverse $ filter isDigit input))

dayOnePart1 :: String -> Int
dayOnePart1 input = sum $ getLiteralDigits <$> (splitOn "\n" input)

dayOnePart2 :: String -> Int
dayOnePart2 input = 1 `debug` ("here: " <> show (getSpelledDigits <$> splitOn "\n" input)) --sum $ getLiteralDigits <$> (splitOn "\n" input)