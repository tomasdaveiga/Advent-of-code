module DayTwo (dayTwoPart1, dayTwoPart2) where

import Data.List.Split (splitOn)
import Data.Set ( member, insert, empty)

nextDigit :: Int -> String -> Int
nextDigit startDigit inputLine = foldl applyDirection startDigit inputLine
  where
    applyDirection :: Int -> Char -> Int
    applyDirection start direction =
      case direction of
        'U' -> if start < 4 then start else start - 3
        'D' -> if start > 6 then start else start + 3
        'L' -> if start == 1 || start == 4 || start == 7 then start else start - 1
        'R' -> if start == 3 || start == 6 || start == 9 then start else start + 1

nextDigitDay2 :: Char -> String -> Char
nextDigitDay2 startDigit inputLine = foldl applyDirectionDay2 startDigit inputLine
  where
    applyDirectionDay2 :: Char -> Char -> Char
    applyDirectionDay2 start direction =
      case direction of
        'U' -> case start of
          '1' -> '1'
          '2' -> '2'
          '3' -> '1'
          '4' -> '4'
          '5' -> '5'
          '6' -> '2'
          '7' -> '3'
          '8' -> '4'
          '9' -> '9'
          'A' -> '6'
          'B' -> '7'
          'C' -> '8'
          'D' -> 'B'
        'D' -> case start of
          '1' -> '3'
          '2' -> '6'
          '3' -> '7'
          '4' -> '8'
          '5' -> '5'
          '6' -> 'A'
          '7' -> 'B'
          '8' -> 'C'
          '9' -> '9'
          'A' -> 'A'
          'B' -> 'D'
          'C' -> 'C'
          'D' -> 'D'
        'L' -> case start of
          '1' -> '1'
          '2' -> '2'
          '3' -> '2'
          '4' -> '3'
          '5' -> '5'
          '6' -> '5'
          '7' -> '6'
          '8' -> '7'
          '9' -> '8'
          'A' -> 'A'
          'B' -> 'A'
          'C' -> 'B'
          'D' -> 'D'
        'R' -> case start of
          '1' -> '1'
          '2' -> '3'
          '3' -> '4'
          '4' -> '4'
          '5' -> '6'
          '6' -> '7'
          '7' -> '8'
          '8' -> '9'
          '9' -> '9'
          'A' -> 'B'
          'B' -> 'C'
          'C' -> 'C'
          'D' -> 'D'

dayTwoPart1 :: String -> Int
dayTwoPart1 input = foldl (\acc x -> acc * 10 + x) 0 $ tail $ scanl nextDigit 5 (splitOn "\n" input)

dayTwoPart2 :: String -> String
dayTwoPart2 input = tail $ scanl nextDigitDay2 '5' (splitOn "\n" input)