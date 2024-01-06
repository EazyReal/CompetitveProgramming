import kotlin.math.roundToInt

private fun readLn() : String = readLine()!! // string line
private fun readInt() : Int = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() : List<Int> = readStrings().map { it.toInt() } // list of ints

//println(a.joinToString("\n")) // each element of array/list of a separate line


fun main() {
    var T = readInt()
    for (t in 1..T)
    {
        var n = readInt()
        var a : MutableList<Pair<Int,Int>>  = mutableListOf()
        for (i in 0..(n-1))
        {
            var (tl, tr) = readInts()
            a.add(Pair(tl, 1))
            a.add(Pair(tr+1, -1))
            a.add(Pair(tl, 2))
            a.add(Pair(tr+1, 2))
        }
        a.sortWith(compareBy({it.first}, {it.second}))
        var cur = 0
        var ans = -1
        for (ai in a)
        {
            when(ai.second)
            {
               1 -> cur = cur + 1
               -1 -> cur = cur - 1
               2 -> when(cur)
                {
                    1 -> ans = cur
                    else -> ans = ans
                }

            }
        }
        println(ans)
    }

}
