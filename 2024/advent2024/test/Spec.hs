import Test.Hspec
import DayOne

main :: IO ()
main = hspec $ do
    it "Day 01" $ do
        content <- readFile "test/day01Part1.txt"
        dayOnePart1 content `shouldBe` 11
        dayOnePart2 content `shouldBe` 31
