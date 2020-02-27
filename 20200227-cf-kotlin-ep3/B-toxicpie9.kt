import java.io.*
import java.util.*

// <stolen-part>
@JvmField val cin = System.`in`.bufferedReader()
@JvmField val cout = PrintWriter(System.out, false)
@JvmField var tokenizer: StringTokenizer = StringTokenizer("")
fun nextLine() = cin.readLine()!!
fun read(): String {
    while(!tokenizer.hasMoreTokens())
        tokenizer = StringTokenizer(nextLine())
    return tokenizer.nextToken()
}
fun nextInt() = read().toInt()
fun nextDouble() = read().toDouble()
fun nextLong() = read().toLong()
fun nextStrings(n: Int) = List(n) { read() }
fun nextLines(n: Int) = List(n) { nextLine() }
fun nextInts(n: Int) = List(n) { read().toInt() }
fun nextIntArray(n: Int) = IntArray(n) { read().toInt() }
fun nextDoubles(n: Int) = List(n) { read().toDouble() }
fun nextDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun nextLongs(n: Int) = List(n) { read().toLong() }
fun nextLongArray(n: Int) = LongArray(n) { read().toLong() }
// </stolen-part>

fun solve() : Int {
    val n = nextInt()
    var a = ArrayList<Int>()
    var b = ArrayList<Int>()
    (1 .. n).forEach({
        a.add(nextInt())
        b.add(nextInt())
    })
    fun yes(x : Int) : Boolean {
        var cnt = 0
        (0 until n).forEach({
            if(x >= a[it] && x <= b[it])
                cnt++
            if(cnt > 1) return false
        })
        return (cnt == 1)
    }
    a.forEach({
        if(yes(it - 1)) return it - 1
        if(yes(it)) return it
    })
    b.forEach({
        if(yes(it)) return it
        if(yes(it + 1)) return it + 1
    })
    return -1
}

fun main() {
    val T = nextInt()
    (1 .. T).forEach{ cout.println(solve()) }
    cout.flush()
}
