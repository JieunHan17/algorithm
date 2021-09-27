import java.util.Scanner

fun main(args: Array<String>) {
	val N: Int = readLine()!!.toInt()
	var level = IntArray(N)
	val input = readLine()!!.split(" ").map { it.toInt() }
	for (i: Int in 0..N - 1)
	{
		level.set(i, input[i])
	}
	level.sort()
	
	var cnt: Int = 1
	for (i: Int in 0 until N - 1)
	{
		if (level[i] != level[i + 1])
		{
			cnt++
		}
	}
	
	if (cnt < 3)
	{
		println("NO")
	}
	else
	{
		println("YES")
	}
}