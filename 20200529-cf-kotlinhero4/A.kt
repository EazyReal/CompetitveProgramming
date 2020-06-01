private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints


fun main() {
    // read input
    var T = readInt()
    for(t in 1..T) {
    	var (n, k) = readInts()
        var v = 1
        var s = 0
        var a : MutableList<Int> = mutableListOf()
        while(s < n)
    	{
            s += v
            a.add(v)
            v = v*k
    	} 
        for(ai in a) print("${ai} ")
        println()
    } 
}