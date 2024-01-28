module DayFour (dayFourPart1) where
import Data.List ( nub, sortBy )
import Data.Char (isAlpha, isNumber)
import Data.Function (on)

parseInput :: String -> [(String,Int,String)]
parseInput input =
  [(parts, idNum, checksum)
  | line <- lines input
  , let parts = reverse $ drop 5 $ reverse $ filter isAlpha line
  , let idNum = read (filter isNumber line) :: Int
  , let checksum = reverse $ take 5 $ reverse $ filter isAlpha line
  ]

checkCheckSum :: (String, Int, String) -> Bool
checkCheckSum (str, _, checkSum) = checkSum == common
  where
    common = map fst orderedPairs
    orderedPairs = take 5 $ sortBy comparingFunction pairs
    pairs = zip (nub str) counter
    counter = map ((\st el -> length $ filter (== el) st) str) (nub str)

comparingFunction :: Ord a => Ord b => (a, b) -> (a, b) -> Ordering
comparingFunction tup1 tup2 = case (flip compare `on` snd) tup1 tup2 of
  EQ  -> (compare `on` fst) tup1 tup2
  ord -> ord

dayFourPart1 :: String -> Int
dayFourPart1 input = foldl (\x (_,idNum, _) -> x+idNum) 0 $ filter checkCheckSum (parseInput input)