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

const val mod: Int = 998244353

fun getOne(s: String): Int {
    if (s[0] == '0')
        return 0
    var res = 1
    for (i in 1..s.length-1)
        if (s[i] == '?')
            res = 2 * res % mod
    return res
}

fun getZero(s: String): Int {
    if (s[0] == '1')
        return 0
    var res = 1
    var was = false
    for (i in 1..s.length-1)
        if (s[i] == '0')
            was = true
        else if (s[i] == '?')
            res = 2 * res % mod
    if (!was)
        res = (res - 1 + mod) % mod
    return res
}

fun PrintWriter.solve() {
  var T = readInt()
  for (tc in 1..T) {
    val s = read()
    println((getZero(s) + getOne(s)) % mod)
  }
}
