import kotlin.math.roundToInt

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

//println(a.joinToString("\n")) // each element of array/list of a separate line

fun main() {
    var T = readInt()
    for (t in 1..T)
    {
        var a = readInt()
        when(a)
        {
            in 0..999 -> println(a)
            in 1000..999499 -> println((a/1000.0).roundToInt().toString() + "K")
            else -> println((a/1000000.0).roundToInt().toString() + "M")
        }
    }

}
