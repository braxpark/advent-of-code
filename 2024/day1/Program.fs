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

    Seq.zip firstList secondList
    |> ResizeArray
    |> Seq.fold (fun sum (first, second) -> (sum + abs (second - first))) 0


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

    Seq.fold
        (fun sum x ->
            sum
            + (x
               * if freq.ContainsKey(x) then
                     freq.[x]
                 else
                     0))
        0
        firstList


let testPath = "./test.txt"
let inputPath = "./input.txt"
let delimiter = "   "
printfn "Answer: %d" (solvePart1 inputPath delimiter)
printfn "Answer: %d" (solvePart2 inputPath delimiter)
