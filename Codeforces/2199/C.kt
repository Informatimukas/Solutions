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
  while (T > 0) {
    val n = readInt()
    var A: String
    var B: String
    var found = false
    if (n == 1) {
        A = "*"
        B = "."
        found = true
    }
    if (n % 5 == 0) {
        A = ".".repeat(n / 5 * 3)
        B = ".".repeat(n / 5 * 3)
        for (i in 0..n/5-1)
            B[3 * i + 1] = '*'
        found = true
    }
    if (n >= 3 && (n - 3) % 5 == 0) {
        A = ".".repeat(n / 5 * 3 + 2)
        B = ".".repeat(n / 5 * 3 + 2)
        B[1] = '*'
        for (i in 0..n/5-1)
            B[2 + 3 * i + 1] = '*'
        found = true
    }
    if (n >= 6 && (n - 6) % 5 == 0) {
        A = ".".repeat(n / 5 * 3 + 4)
        B = ".".repeat(n / 5 * 3 + 4)
        B[1] = '*'
        for (i in 0..n/5)
            B[2 + 3 * i + 1] = '*'
        found = true
    }
    if (found) {
        println("YES")
        println(A.length)
        println(A)
        println(B)
    } else println("NO")
  }
  println()
}