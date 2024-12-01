open System.IO
open System.Collections.Generic

let solvePart1 (filePath: string) (delimiter: string) =
    let firstList = ResizeArray([])
    let secondList = ResizeArray([])

    let lines = File.ReadLines(filePath)

    for line in lines do
        let parts: string [] = line.Split(delimiter)
        firstList.Add((System.Int32.Parse(parts[0])))
        secondList.Add((System.Int32.Parse(parts[1])))

    firstList.Sort()
    secondList.Sort()
    let mutable diffs: int32 = 0

    for i in 0 .. firstList.Count - 1 do
        let diff =
            if firstList[i] >= secondList[i] then
                firstList[i] - secondList[i]
            else
                secondList[i] - firstList[i]

        diffs <- diffs + diff

    diffs


let solvePart2 (filePath: string) (delimiter: string) =
    let firstList = ResizeArray([])
    let freq = Dictionary<int, int>()

    let lines = File.ReadLines(filePath)

    for line in lines do
        let parts: string [] = line.Split(delimiter)
        let leftSideKey = System.Int32.Parse(parts[0])
        let rightSideKey = System.Int32.Parse(parts[1])
        firstList.Add(leftSideKey)

        if freq.ContainsKey(rightSideKey) then
            freq.[rightSideKey] <- freq.[rightSideKey] + 1
        else
            freq.Add(rightSideKey, 1)

    firstList.Sort()
    let mutable leftSideSum = 0

    for number in firstList do
        leftSideSum <-
            leftSideSum
            + number
              * if freq.ContainsKey(number) then
                    freq.[number]
                else
                    0

    leftSideSum


let testPath = "./test.txt"
let inputPath = "./input.txt"
let delimiter = "   "
printfn "Answer: %d" (solvePart1 inputPath delimiter)
printfn "Answer: %d" (solvePart2 inputPath delimiter)
