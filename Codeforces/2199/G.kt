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

fun getLeft(r: Long, x: Long, y1: Long, y2: Long): Long {
    var lef = y1
    var rig = y2
    while (lef <= rig) {
        val mid = (lef + rig) / 2
        if (x * x + mid * mid > r * r)
            rig = mid - 1
        else lef = mid + 1
    }
    return lef
}

fun getRight(n: Long, m: Long, r: Long, x: Long, y1: Long, y2: Long): Long {
    var lef = y1
    var rig = y2
    while (lef <= rig) {
        val mid = (lef + rig) / 2
        if ((n - x) * (n - x) + (m - mid) * (m - mid) > r * r)
            lef = mid + 1
        else rig = mid - 1
    }
    return rig
}

fun solveRectangle(n: Long, m: Long, r: Long, p1: Boolean, p2: Boolean, p3: Boolean, p4: Boolean): Long {
    var x1 = 0L
    var x2 = n
    var y1 = 0L
    var y2 = m
    if (p1)
        x2 = min(x2, r)
    else x1 = max(x1, r + 1)
    if (p2)
        y1 = max(y1, m - r)
    else y2 = min(y2, m - r - 1)
    if (p3)
        x1 = max(x1, n - r)
    else x2 = min(x2, n - r - 1)
    if (p4)
        y2 = min(y2, r)
    else y1 = max(y1, r + 1)
    var res: Long = 0
    for (i in x1..x2) {
        val lef = getLeft(r, i, y1, y2)
        val rig = getRight(n, m, r, i, y1, y2)
        if (lef <= rig)
            res += rig - lef + 1
    }
    return res
}

fun PrintWriter.solve() {
  var T = readInt()
  while (T > 0) {
    T--
    var n = readLong()
    var m = readLong()
    val r = readLong()
    if (n > m) {
        val tmp = n
        n = m
        m = tmp
    }
    val res = solveRectangle(n, m, r, false, true, false, true) +
              solveRectangle(n, m, r, false, true, true, false) +
              solveRectangle(n, m, r, false, true, true, true) +
              solveRectangle(n, m, r, true, false, false, true) +
              solveRectangle(n, m, r, true, false, true, false) +
              solveRectangle(n, m, r, true, false, true, true) +
              solveRectangle(n, m, r, true, true, false, true) +
              solveRectangle(n, m, r, true, true, true, false) +
              solveRectangle(n, m, r, true, true, true, true)
    println(res)
  }
}