module DayOne (dayOnePart1, dayOnePart2) where

import Data.List.Split (splitOn)
import Data.Set (Set, member, insert, empty)


parseInput :: String -> [(String, Int)]
parseInput input = zip directions numBlocks
  where
    directions = take 1 <$> splitOn ", " input
    numBlocks = map read (drop 1 <$> splitOn ", " input)


iterateCoordinates :: [(String, (Int,Int))] -> (String,Int) -> [(String, (Int, Int))]
iterateCoordinates inputList (direction,numBlocks) = inputList ++ tail (take (numBlocks+1) (iterate (updateCoordinates2 (movDir,1)) startPosition))
  where
    startPosition = last inputList
    movDir
      | fst startPosition  == "N" = if direction == "L" then "W" else "E"
      | fst startPosition  == "W" = if direction == "L" then "S" else "N"
      | fst startPosition  == "S" = if direction == "L" then "E" else "W"
      | fst startPosition  == "E" = if direction == "L" then "N" else "S"
      | otherwise = "Error"

-- Tuple with (Heading, Coordinate@(x,y))
updateCoordinates2 :: (String, Int) -> (String, (Int, Int)) -> (String, (Int, Int))
updateCoordinates2 (direction,numBlock) (_, (x,y)) =
  case direction of
    "W" -> ("W", (x - numBlock, y))
    "N" -> ("N", (x, y + numBlock))
    "E" -> ("E", (x + numBlock, y))
    "S" -> ("S", (x, y - numBlock))
    _   -> error "Unknown direction"

-- Tuple with (Heading, Coordinate@(x,y))
updateCoordinates :: (String, (Int, Int)) -> (String, Int) -> (String, (Int, Int))
updateCoordinates currentState@(_, (x,y)) (direction,numBlock) =
  case fst currentState of
    "N" -> if direction == "L" then ("W", (x - numBlock, y)) else ("E", (x + numBlock, y))
    "W" -> if direction == "L" then ("S", (x, y - numBlock)) else ("N", (x, y + numBlock))
    "S" -> if direction == "L" then ("E", (x + numBlock, y)) else ("W", (x - numBlock, y))
    "E" -> if direction == "L" then ("N", (x, y + numBlock)) else ("S", (x, y - numBlock))
    _   -> error "Unknown direction"

dayOnePart1 :: String -> Int
dayOnePart1 input =  (abs . fst) finalPosition + (abs . snd) finalPosition
  where
    finalPosition = snd $ foldl updateCoordinates ("N", (0,0)) (parseInput input)

dayOnePart2 :: String -> Int
dayOnePart2 input = (abs . fst) firstDuplicate + (abs . snd) firstDuplicate
  where
    firstDuplicate = getFirstDuplicate empty listOfPositions
    listOfPositions = foldl iterateCoordinates [("N",(0,0))] (parseInput input)
    getFirstDuplicate :: Set (Int, Int) -> [(String, (Int, Int))] -> (Int, Int)
    getFirstDuplicate visited ((_, coord):xs)
      | coord `member` visited = coord
      | otherwise = getFirstDuplicate (insert coord visited) xs



-- module DayOne (dayOnePart1, dayOnePart2) where

-- import Data.List.Split (splitOn)
-- import Data.Set (Set, member, insert, empty)

-- type Coordinate = (Int, Int)
-- type Direction = String

-- parseInput :: String -> [(Direction, Int)]
-- parseInput input = zip directions numBlocks
--   where
--     [direction, blocks] = splitOn ", " input
--     directions = [direction]
--     numBlocks = map read $ splitOn ", " blocks

-- updateCoordinates :: Coordinate -> (Direction, Int) -> Coordinate
-- updateCoordinates (x, y) (direction, numBlock) =
--   case direction of
--     "W" -> (x - numBlock, y)
--     "N" -> (x, y + numBlock)
--     "E" -> (x + numBlock, y)
--     "S" -> (x, y - numBlock)
--     _   -> error "Unknown direction"

-- iterateCoordinates :: [(Direction, Coordinate)] -> (Direction, Int) -> [(Direction, Coordinate)]
-- iterateCoordinates inputList (direction, numBlocks) =
--   inputList ++ tail (take (numBlocks + 1) (iterate (updateCoordinates (startPosition)) (direction,1)))
--   where
--     startPosition = snd $ last inputList

-- dayOnePart1 :: String -> Int
-- dayOnePart1 input =  (abs . fst) finalPosition + (abs . snd) finalPosition
--   where
--     finalPosition = foldl updateCoordinates (0, 0) (parseInput input)

-- dayOnePart2 :: String -> Int
-- dayOnePart2 input = (abs . fst) firstDuplicate + (abs . snd) firstDuplicate
--   where
--     firstDuplicate = getFirstDuplicate empty listOfPositions
--     listOfPositions = foldl iterateCoordinates [("N", (0, 0))] (parseInput input)
    
--     getFirstDuplicate :: Set Coordinate -> [(Direction, Coordinate)] -> Coordinate
--     getFirstDuplicate visited ((_, coord):xs)
--       | coord `member` visited = coord
--       | otherwise = getFirstDuplicate (insert coord visited) xs