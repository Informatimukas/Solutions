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
      T--
      val n = readInt()
      var lefk = 0
      var rigk = 1000000000
      for (i in 0..n-1) {
        val s = read()
        val t = read()
        val r = readInt()
        var sam = 0
        while (sam < s.length && sam < t.length &&
            s[s.length - sam - 1] == t[t.length - sam - 1])
            sam++
        if (r > 0)
            rigk = min(rigk, sam)
        else lefk = max(lefk, sam + 1)
      }
      if (lefk > rigk)
        println(0)
      else {
        println(rigk - lefk + 1)
        for (i in lefk..rigk) {
            print(i)
            if (i < rigk)
                print(" ")
        }
        println()
      }
  }
}
