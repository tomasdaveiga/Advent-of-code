import Test.Hspec
import DayOne

main :: IO ()
main = hspec $ do
    it "Day 01" $ do
        testContentPart1 <- readFile "test/day01Part1.txt"
        testContentPart2 <- readFile "test/day01Part2.txt"
        dayOnePart1 testContentPart1 `shouldBe` 142
        dayOnePart2 testContentPart2 `shouldBe` 281