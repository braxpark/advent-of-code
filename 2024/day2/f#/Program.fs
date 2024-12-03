open System.IO

let part1 (filePath: string) (delimiter: string) =
    File.ReadLines(filePath)
    |> Seq.sumBy (fun report ->
        let levels = report.Split(delimiter) |> Array.map int
        let increasing = levels.[1] > levels.[0]

        levels
        |> Array.indexed
        |> Array.skip 1
        |> Array.forall (fun (i, _) ->
            let isMonotonic =
                if increasing then
                    levels.[i] > levels.[i - 1]
                else
                    levels.[i] < levels.[i - 1]

            let isSafeDiff =
                let diff = abs (levels.[i] - levels.[i - 1]) in diff >= 1 && diff <= 3

            isMonotonic && isSafeDiff)
        |> fun isSafe -> if isSafe then 1 else 0)

let testPath = "../test.txt"
let inputPath = "../input.txt"
let delimiter = " "
printfn "Part 1 Answer: %d" (part1 inputPath delimiter)
