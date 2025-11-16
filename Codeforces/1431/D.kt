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

const val Inf = 1000000

fun getMin(a: IntArray, b: BooleanArray): Int {
    var best = Inf;
    var with = -1
    for (i in 0..a.size-1)
        if (b[i] && (a[i] < best)) {
            best = a[i];
            with = i
        }
    return with
}

fun getMax(a: IntArray, b: BooleanArray): Int {
    var best = -Inf;
    var with = -1
    for (i in 0..a.size-1)
        if (b[i] && (a[i] > best)) {
            best = a[i];
            with = i
        }
    return with
}

fun PrintWriter.solve() {
  var T = readInt()
  for (tc in 0..T-1) {
    val n = readInt()
    val a = readIntArray(n)
    var b = BooleanArray(n) { true }
    var used = 0
    for (i in 0..n-1) {
        if (i > 0)
            print(" ")
        var ind = getMin(a, b)
        if (a[ind] <= used) {
            print(ind + 1)
            b[ind] = false
            used = 1
        } else {
            ind = getMax(a, b)
            print(ind + 1)
            b[ind] = false
            used++
        }
    }
    println()
  }
}