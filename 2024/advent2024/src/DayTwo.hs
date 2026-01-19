module DayTwo
    ( dayTwoPart1
    , dayTwoPart2
    ) where

import Data.List ( tails
                 , inits)

readReports :: String -> [[Int]]
readReports input = map (map read . words) (lines input)

isSafe :: [Int] -> Bool
isSafe (x:y:xs)
  | x > y && x - y <= 3 = checkReportHelper (y:xs) False
  | x < y && y - x <= 3 = checkReportHelper (y:xs) True
  | otherwise           = False 
  where
    checkReportHelper (a:b:c) isIncreasing
      | isIncreasing = b>a && b-a <=3 && checkReportHelper (b:c) isIncreasing
      | otherwise    = b<a && a-b <=3 && checkReportHelper (b:c) isIncreasing
    checkReportHelper _ _ = True
isSafe _ = False

problemDampener :: [Int] -> Bool
problemDampener report
  | isSafe report = True
  | otherwise = any isSafe (removeOne report)
  where
    removeOne xs = [ys ++ zs | (ys, _:zs) <- zip (inits xs) (tails xs)]

dayTwoPart1 :: String -> Int
dayTwoPart1 input = length $ filter isSafe (readReports input)

dayTwoPart2 :: String -> Int
dayTwoPart2 input = length $ filter problemDampener (readReports input)