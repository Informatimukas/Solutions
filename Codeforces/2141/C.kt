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

const val popBack = "popback"
const val popFront = "popfront"
const val Min = "min"

fun pushBack(x: Int): String {
    return "pushback a[" + x.toString() + "]"
}

fun pushFront(x: Int): String {
    return "pushfront a[" + x.toString() + "]"
}

fun PrintWriter.solve() {
  var n = readInt()
  var res = arrayListOf<String>()
  res.add(pushBack(0))
  res.add(Min)
  for (i in 2..n step 2)
    if (i % 4 == 2) {
        for (j in i-1..n-1) {
            res.add(pushBack(j))
            res.add(Min)
            res.add(popFront)
            res.add(Min)
        }
        if (i + 1 <= n) {
            res.add(pushFront(n - i))
            res.add(pushFront(n - i - 1))
            res.add(Min)
        }
    } else {
        for (j in n-i downTo 0) {
            res.add(pushFront(j))
            res.add(Min)
            res.add(popBack)
            res.add(Min)
        }
        if (i + 1 <= n) {
            res.add(pushBack(i - 1))
            res.add(pushBack(i))
            res.add(Min)
        }
    }
    println(res.size)
    for (i in 0..res.size-1)
        println(res[i])
}
