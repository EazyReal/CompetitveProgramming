private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

// 2case
// only remove
// remove + one distribution

fun main() {
    // read input
    var T = readInt()
    for(t in 1..T) {
    	var (n, k1, k2) = readInts()
        k2 = listOf(k2, k1*2).min()!!
        //k2 = if (k2 > k1*2 ) k1*2 else k2
        var s = readLn()
        var pre = 0
        var ans = 0
        for(c in s)
        {
            if(c == '0')
            {
                ans += k2*(pre/2) + k1*(pre%2)
                pre = 0;
            }
            else pre++;
        }
        ans += k2*(pre/2) + k1*(pre%2)

        println(ans)
    } 
}