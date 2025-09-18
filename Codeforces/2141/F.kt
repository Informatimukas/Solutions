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

fun PrintWriter.solve() {
  var T = readInt()
  for (tc in 1..T) {
    val n = readInt()
    val a = readInts(n)
    var cnt = IntArray(n + 1) { 0 }
    for (i in 0..n-1)
        cnt[a[i]]++
    cnt.sort()
    cnt.reverse()
    var res = IntArray(n + 1) { 1000000000 }
    var cur = IntArray(0)
    for (i in n downTo 0) {
        res[0] = min(res[0], i + cnt[i])
        var nxt = IntArray(cnt[i])
        for (j in cnt[i] - 1 downTo 0) {
            nxt[j] = cnt[i] - j
            if (j < cur.size)
                nxt[j] += cur[j]
            res[nxt[j]] = min(res[nxt[j]], i + j)
        }
        cur = nxt
    }
    for (i in 0..n-1) {
        if (i > 0) {
            print(" ")
            res[i] = min(res[i - 1], res[i])
        }
        print(res[i])
    }
    println()
  }
}