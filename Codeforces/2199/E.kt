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
  val q = readInt()
  val a = readInts(n)
  val b = LongArray(n)
  b[0] = 1
  for (i in 1..n-1) {
    if (a[i - 1] == a[i])
        b[i] = b[i - 1] + 2
    else b[i] = b[i - 1] + abs(a[i] - a[i - 1])
  }
  for (i in 0..q-1) {
    val x = readLong()
    if (x > b[n - 1])
        print(-1)
    else {
        var lef = 0
        var rig = n - 1
        while (lef <= rig) {
            val mid = (lef + rig) / 2
            if (b[mid] <= x)
                lef = mid + 1
            else rig = mid - 1
        }
        if (b[rig] == x)
            print(a[rig])
        else if (a[rig] == a[rig + 1])
            print(0)
        else if (a[rig] < a[rig + 1])
            print(a[rig] + x - b[rig])
        else print(a[rig] - (x - b[rig]))
    }
    if (i < q - 1)
        print(" ")
  }
  println()
}