private fun readLn() : String = readLine()!! // string line
private fun readInt() : Int = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() : List<Int> = readStrings().map { it.toInt() } // list of ints

//println(a.joinToString("\n")) // each element of array/list of a separate line


fun main(args : Array<String>){
    var T = readInt()
    for (t in 1..T)
    {
        var n = readInt()
        var a = readInts()
        //var sorted_a = a.sorted()
        //var pos_min = 100000
        //var neg_max = -100000
        var use_val = 100000
        var use_id = -1
        var sum_of_pos = 0
        for(i in 0..(n-1))
        {
            when
            {
                a[i] > 0 -> {
                	sum_of_pos = sum_of_pos + a[i]
                	when
                	{
                	    a[i] < use_val -> {
                	        use_val = a[i]
                	        use_id = i
                	    }
                	}
                }
                a[i] < 0 -> when
                	{
                	    -a[i] < use_val -> {
                	        use_val = -a[i]
                	        use_id = i
                	    }
                	}
            }
        }

        println(sum_of_pos - use_val)
        for(i in 0..(n-1))
        {
            var cur = if ( a[i] > 0 ) 1 else 0
            when
            {
                i == use_id -> print(1-cur)
                else -> print(cur)
            }
        }
        println()
    }

}
