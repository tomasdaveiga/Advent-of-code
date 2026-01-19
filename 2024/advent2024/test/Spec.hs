import Test.Hspec
import DayOne
import DayTwo
import DayThree
import DayFour
import DayFive
import DaySix

main :: IO ()
main = hspec $ do
    it "Day 01" $ do
        content <- readFile "test/day01Part1.txt"
        dayOnePart1 content `shouldBe` 11
        dayOnePart2 content `shouldBe` 31

    it "Day 02" $ do
        content <- readFile "test/day02Part1.txt"
        dayTwoPart1 content `shouldBe` 2
        dayTwoPart2 content `shouldBe` 4

    it "Day 03" $ do
        contentPart1 <- readFile "test/day03Part1.txt"
        contentPart2 <- readFile "test/day03Part2.txt"
        dayThreePart1 contentPart1 `shouldBe` 161
        dayThreePart2 contentPart2 `shouldBe` 48

    it "Day 04" $ do
        content <- readFile "test/day04Part1.txt"
        dayFourPart1 content `shouldBe` 18
        dayFourPart2 content `shouldBe` 9

    it "Day 05" $ do
        content <- readFile "test/day05Part1.txt"
        dayFivePart1 content `shouldBe` 143
        dayFivePart2 content `shouldBe` 123
    
    it "Day 06" $ do
        content <- readFile "test/day06Part1.txt"
        daySixPart1 content `shouldBe` 41
        daySixPart2 content `shouldBe` 0