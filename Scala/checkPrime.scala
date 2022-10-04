object Primes {
  def iterate(max: Int, callback: (Int) => Boolean) {
    for (i <- 1 to max) {
        if (callback(i)) {
          println(i)         
        }
    }
  }

  def isPrime(number: Int) : Boolean = {
    for (i <- 2 to number - 1) {
        if (number % i == 0) {
          return false;
        }
    }
    return true;
  }

  def main(args: Array[String]) {
    val max = if (args.length > 0) args(0).toInt else 100
    iterate(max, isPrime)
  }
}