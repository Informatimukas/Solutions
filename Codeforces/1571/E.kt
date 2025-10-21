import java.util.Vector
import java.util.TreeMap
import kotlin.math.*
import java.io.BufferedReader
import java.io.PrintWriter
import java.util.StringTokenizer

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

fun main() { _writer.solve(); _writer.flush() }

const val Inf = 1000000000
const val Maxb = 4

fun PrintWriter.solve() {
  var T = readInt()
  for (tc in 0..T-1) {
    val n = readInt()
    val s = read()
    val a = read()
    var res = Inf
    var dp = Array(n + 1) {
        IntArray(1 shl Maxb) {Inf}
    }
    dp[0][0] = 0;
    for (i in 0..n)
        for (j in 0..((1 shl Maxb)-1))
            if (i - 4 < 0 || a[i - 4] == '0' || j == 3 || j == 5)
                if (i == n)
                    res = min(res, dp[i][j])
                else {
                    var nj = (j shl 1) % (1 shl Maxb)
                    var zer = 0
                    var one = 0
                    if (s[i] == '(') one++
                    else zer++
                    dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j] + zer)
                    dp[i + 1][(nj or 1)] = min(dp[i + 1][(nj or 1)], dp[i][j] + one)
                }
    if (res >= Inf)
        res = -1
    println(res)
  }
}