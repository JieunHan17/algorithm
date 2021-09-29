import java.util.*

fun main(args: Array<String>) {
    val s = Scanner(System.`in`)
    val N = s.nextInt()
    val K = s.nextInt()
    val input = readLine()!!.split(" ").map { it.toInt() }
    var idxOfOne = input.indexOf(1)

    val start = 0
    val end = N - 1
    var cnt = 0
    if (idxOfOne < K)
    {
        var cur = K - 1
        while (cur < end)
        {
            cnt++
            cur += (K - 1)
        }
        cnt++
    }
    else
    {
        var curFront = idxOfOne - (K - 1)
        var curBack = idxOfOne + (K - 1)
        while (start < curFront)
        {
            cnt++
            curFront -= (K - 1)
        }
        cnt++
        while (curBack < end)
        {
            cnt++
            curBack += (K - 1)
        }
        cnt++
    }

    println(cnt)
}