package Mathematics

object Fibonacci {
  private val allFibonacci: LazyList[Int] = 1 #:: 1 #:: allFibonacci.zip(allFibonacci.tail).map(t => t._1 + t._2)

  /**
    * @param total
    *   Maximum number of elements of the sequence
    * @return
    */
  def fibGenerate(total: Int): Seq[Int] = allFibonacci.take(total)
}