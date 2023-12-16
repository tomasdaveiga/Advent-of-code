import Test.Hspec
import DayOne

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