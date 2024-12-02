import Test.Hspec
import DayOne
import DayTwo

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
