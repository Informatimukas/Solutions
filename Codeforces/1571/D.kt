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
  val n = readInt()
  val m = readInt()
  val hasBoth = Array(n + 1) { Array(n + 1) { 0 } }
  val hasFirst = Array(n + 1) { 0 }
  val hasLast = Array(n + 1) { 0 }
  var myFirst = 0
  var myLast = 0
  for (i in 0..m-1) {
      val f = readInt()
      val l = readInt()
      if (i == 0) {
          myFirst = f
          myLast = l
      }
      hasBoth[f][l]++
      hasFirst[f]++
      hasLast[l]++
  }
  var res = 1
  for (i in 1..n)
    for (j in 1..n)
        if (i != j) {
            val c2 = hasBoth[i][j]
            val c1 = hasFirst[i] + hasLast[j] - 2 * hasBoth[i][j]
            val c0 = m - c1 - c2
            var cand = 1
            if (i == myFirst && j == myLast)
                cand = 1
            else if (i == myFirst || j == myLast)
                cand = c2 + 1
            else cand = c1 + c2 + 1
            res = max(res, cand)
        }
    println(res)
}