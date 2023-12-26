import Test.Hspec
import DayOne
import DayTwo
import DayThree

main :: IO ()
main = hspec $ do
    it "Day 01" $ do
        testContentP1T1 <- readFile "test/day01Part1_test1.txt"
        testContentP1T2 <- readFile "test/day01Part1_test2.txt"
        testContentP1T3 <- readFile "test/day01Part1_test3.txt"
        testContentP2   <- readFile "test/day01Part2.txt"
        dayOnePart1 testContentP1T1 `shouldBe` 5
        dayOnePart1 testContentP1T2 `shouldBe` 2
        dayOnePart1 testContentP1T3 `shouldBe` 12
        dayOnePart2 testContentP2   `shouldBe` 4
    
    it "Day 02" $ do
        testContentP1 <- readFile "test/day02Part1.txt"
        dayTwoPart1 testContentP1 `shouldBe` 1985
        dayTwoPart2 testContentP1 `shouldBe` "5DB3"

    it "Day 03" $ do
        testContentP1 <- readFile "test/day03Part1.txt"
        dayThreePart1 testContentP1 `shouldBe` 0
        dayThreePart2 testContentP1 `shouldBe` 2