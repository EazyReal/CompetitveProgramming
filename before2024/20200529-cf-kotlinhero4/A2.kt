private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun main() {
    // read input
    var T = readInt()
    for(t in 1..T) {
    	var (n, k) = readInts()
        var four = 4
        var v = 1
        var s = 0
        var a : MutableList<Int> = mutableListOf()
        for(i in 1..4)
        {
            a.add(v)
            s += v
            v *= k
        }
        var fst = n/s
        for(ai in a) print("${ai*fst} ")
        println()
    } 
}