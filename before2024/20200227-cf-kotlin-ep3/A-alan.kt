fun myread() = readLine()!!
fun readint() = myread().toInt()
fun readLong() = myread().toLong()
fun readints() = myread().split(" ").map{it.toInt()}
fun readLongs() = myread().split(" ").map{it.toLong()}

fun main() {
    val t = readint()
    for(i in 1 .. t){
        var n = readLong()
        if(n<1000){
            println(n);
        } else if(n<1000000-500){
            n+=500
            println("${n/1000}K")
        } else{
            n+=500000
            println("${n/1000000}M")
        }
    }
}
