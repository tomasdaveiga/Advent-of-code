module DayOne (dayOnePart1, dayOnePart2) where

import Data.List.Split (splitOn)
import Data.Set ( member, insert, empty)

parseInput :: String -> [(Char, Int)]
parseInput input = zip (head <$> splitOn ", " input) (map read (drop 1 <$> splitOn ", " input))

iterateCoordinates :: [(Char, (Int,Int))] -> (Char,Int) -> [(Char, (Int, Int))]
iterateCoordinates inputList (direction,numBlocks) = inputList ++ tail (take (numBlocks+1) (iterate (updateCoordinates 1) startPosition))
  where
    startPosition = last inputList
    updateCoordinates numBlock (_, (x,y)) =
      case fst startPosition of
        'N' -> if direction == 'L' then ('W', (x - numBlock, y)) else ('E', (x + numBlock, y))
        'W' -> if direction == 'L' then ('S', (x, y - numBlock)) else ('N', (x, y + numBlock))
        'S' -> if direction == 'L' then ('E', (x + numBlock, y)) else ('W', (x - numBlock, y))
        'E' -> if direction == 'L' then ('N', (x, y + numBlock)) else ('S', (x, y - numBlock))
        _   -> error "Unknown direction!!!"

dayOnePart1 :: String -> Int
dayOnePart1 input =  
  let finalPosition = snd $ last $ foldl iterateCoordinates [('N', (0,0))] (parseInput input)
  in (abs . fst) finalPosition + (abs . snd) finalPosition

dayOnePart2 :: String -> Int
dayOnePart2 input = (abs . fst) firstDuplicate + (abs . snd) firstDuplicate
  where
    firstDuplicate = getFirstDuplicate empty $ foldl iterateCoordinates [('N',(0,0))] (parseInput input)
    getFirstDuplicate visited ((_, coord):xs)
      | coord `member` visited = coord
      | otherwise = getFirstDuplicate (insert coord visited) xs