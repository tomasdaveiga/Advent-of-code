module DaySix
    ( daySixPart1
    , daySixPart2
    ) where

import Debug.Trace
debug = flip trace

getGuardPos :: [[Char]] -> Maybe (Int, Int, Char)
getGuardPos mapGuard = 
    case [(i,j, char) | (i, row) <- zip [0..] mapGuard, 
                        (j, char) <- zip [0..] row, 
                        char `elem` "<>^v"] of
    [] -> Nothing
    (x:_) -> Just x

checkNextSpace :: [[Char]] -> (Int, Int, Char) -> Bool
checkNextSpace mapGuard (i,j,dir) = case dir of
    '>' -> j + 1 < width && mapGuard !! i !! (j+1) /= '#'
    '<' -> j - 1 >= 0 && mapGuard !! i !! (j-1) /= '#'
    'v' -> i + 1 < height && mapGuard !! (i+1) !! j /= '#'
    '^' -> i - 1 >= 0 && mapGuard !! (i-1) !! j /= '#'
  where
    height = length mapGuard
    width = length (head mapGuard)

moveForward :: [[Char]] -> (Int, Int, Char) -> [[Char]]
moveForward mapGuard (i,j,dir) = case dir of
    '>' -> if null afterCols then beforeLines ++ [init beforeCol ++ "X"] ++ tail afterLines else beforeLines ++ [beforeCol ++ "X>" ++ tail (tail afterCols)] ++ tail afterLines -- there might not be enough afterCols for tail tail
    '<' -> if null beforeCol then beforeLines ++ ["X" ++ tail afterCols] ++ tail afterLines else beforeLines ++ [(init beforeCol) ++ "<X" ++ tail afterCols] ++ tail afterLines
    'v' -> if null (tail afterLines) then beforeLines ++ [beforeCol ++ "X" ++ tail afterCols] else beforeLines ++ [beforeCol ++ "X" ++ tail afterCols] ++ [b4ColNextLine ++ "v" ++ tail afColNextLine] ++ tail (tail afterLines) -- there might not be enough afterlines for tail tail
    '^' -> if null beforeLines then (b4ColB4Line ++ "X" ++ tail afColB4Line) : tail afterLines else init beforeLines ++ [b4ColB4Line ++ "^" ++ tail afColB4Line] ++ [beforeCol ++ "X" ++ tail afterCols] ++ tail afterLines
    where
        (beforeLines, afterLines) = splitAt i mapGuard
        (beforeCol, afterCols) = splitAt j (head afterLines)
        (b4ColNextLine, afColNextLine) = splitAt j (head $ tail afterLines)
        (b4ColB4Line, afColB4Line) = if null beforeLines then splitAt j (head afterLines) else splitAt j (last beforeLines)
    
rotate :: [[Char]] -> (Int, Int, Char) -> [[Char]]
rotate mapGuard (i,j,dir) = case dir of
    '>' -> beforeLines ++ [beforeCol ++ "v" ++ tail afterCols] ++ tail afterLines
    '<' -> beforeLines ++ [beforeCol ++ "^" ++ tail afterCols] ++ tail afterLines
    'v' -> beforeLines ++ [beforeCol ++ "<" ++ tail afterCols] ++ tail afterLines
    '^' -> beforeLines ++ [beforeCol ++ ">" ++ tail afterCols] ++ tail afterLines
    where
        (beforeLines, afterLines) = splitAt i mapGuard
        (beforeCol, afterCols) = splitAt j (head afterLines)

updateMap :: [[Char]] -> [[Char]]
updateMap mapGuard = case getGuardPos mapGuard of
    Nothing -> mapGuard
    Just pos -> if checkNextSpace mapGuard pos
        then updateMap (moveForward mapGuard pos) 
        else updateMap (rotate mapGuard pos)

countX :: [[Char]] -> Int
countX mapGuard = length $ concatMap (filter ('X'==)) mapGuard

daySixPart1 :: String -> Int
daySixPart1 input = countX $ updateMap (lines input)

daySixPart2 :: String -> Int
daySixPart2 input = 0
