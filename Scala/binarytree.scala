trait Tree[+A] {

  import scala.annotation.tailrec

  def value: Option[A] = this match {
    case n: Node[A] => Some(n.v)
    case l: Leaf[A] => Some(l.v)
    case Empty      => None
  }

  def left: Option[Tree[A]] = this match {
    case n: Node[A] => Some(n.l)
    case l: Leaf[A] => None
    case Empty      => None
  }

  def right: Option[Tree[A]] = this match {
    case n: Node[A] => Some(n.r)
    case l: Leaf[A] => None
    case Empty      => None
  }

  
  private case class Eval[A](v: A) extends Tree[A]

  
  @tailrec
  private def foldLoop[A, B](a: List[Tree[A]], z: B)(f: (B, A) => B)(o: (Node[A], List[Tree[A]]) => List[Tree[A]]): B = a match {
    case (n: Node[A]) :: tl => foldLoop(o(n, tl), z)(f)(o) // never directly evaluate nodes, function o will create new accumulator
    case (l: Leaf[A]) :: tl => foldLoop(tl, f(z, l.v))(f)(o) // always evaluate Leaf 
    case (e: Eval[A]) :: tl => foldLoop(tl, f(z, e.v))(f)(o) // always evaluate Eval 
    case Empty :: tl        => foldLoop(tl, z)(f)(o) // ignore Empty
    case _                  => z // will be Nil (empty list)
  }

  def foldPreorder[B](z: B)(f: (B, A) => B): B = {
    foldLoop(List(this), z)(f) { (n, tl) => Eval(n.v) :: n.l :: n.r :: tl }
  }

  def foldInorder[B](z: B)(f: (B, A) => B): B = {
    foldLoop(List(this), z)(f) { (n, tl) => n.l :: Eval(n.v) :: n.r :: tl }
  }

  def foldPostorder[B](z: B)(f: (B, A) => B): B = {
    foldLoop(List(this), z)(f) { (n, tl) => n.l :: n.r :: Eval(n.v) :: tl }
  }

  def foldLevelorder[B](z: B)(f: (B, A) => B): B = {
    foldLoop(List(this), z)(f) { (n, tl) => (Eval(n.v) :: tl) ::: List(n.l, n.r) }
  }

  def fold[B](z: B)(f: (B, A) => B): B = foldInorder(z)(f)

  def size: Int = fold(0) { (sum, v) => sum + 1 }

  def height: Int = {
    def loop(t: Tree[A]): Int = t match {
      case l: Leaf[A] => 1
      case n: Node[A] => Seq(loop(n.left.get), loop(n.right.get)).max + 1
      case _          => 0
    }
    loop(this) - 1
  }

  def leafCount: Int = {
    @tailrec
    def loop(t: List[Tree[A]], z: Int): Int = t match {
      case (l: Leaf[A]) :: tl => loop(tl, z + 1)
      case (n: Node[A]) :: tl => loop(n.left.get :: n.right.get :: tl, z)
      case _ :: tl            => loop(tl, z)
      case _                  => z
    }
    loop(List(this), 0)
  }

  def toSeq: Seq[A] = fold(List[A]()) { (l, v) => v :: l } reverse

  def toSeqPreorder: Seq[A] = foldPreorder(List[A]()) { (l, v) => v :: l } reverse
  def toSeqInorder: Seq[A] = foldInorder(List[A]()) { (l, v) => v :: l } reverse
  def toSeqPostorder: Seq[A] = foldPostorder(List[A]()) { (l, v) => v :: l } reverse
  def toSeqLevelorder: Seq[A] = foldLevelorder(List[A]()) { (l, v) => v :: l } reverse

  def lastPreorder = toSeqPreorder.last
  def lastInorder = toSeqInorder.last
  def lastPostorder = toSeqPostorder.last
  def lastLevelorder = toSeqLevelorder.last

  def penultimatePreorder = toSeqPreorder.dropRight(1).last
  def penultimateInorder = toSeqInorder.dropRight(1).last
  def penultimatePostorder = toSeqPostorder.dropRight(1).last
  def penultimateLevelorder = toSeqLevelorder.dropRight(1).last

  def nthPreorder(n: Int) = toSeqPreorder(n)
  def nthInorder(n: Int) = toSeqInorder(n)
  def nthPostorder(n: Int) = toSeqPostorder(n)
  def nthLevelorder(n: Int) = toSeqLevelorder(n)

}

case class Node[A](v: A, l: Tree[A], r: Tree[A]) extends Tree[A]
case class Leaf[A](v: A) extends Tree[A]
case object Empty extends Tree[Nothing]

object Run extends App {
  val t: Tree[Symbol] = Node('F, Node('B, Leaf('A), Node('D, Leaf('C), Leaf('E))), Node('G, Empty, Node('I, Leaf('H), Empty)))
  println("tree: " + t)

  for {
    b <- t.left
    value <- b.value
  } println("B node: " + value)

  for {
    b <- t.left
    d <- b.right
    value <- d.value
  } println("D node: " + value)

 
  for {
    b <- t.left
    d <- b.right
    e <- d.right
    x <- e.right
    value <- x.value
  } println("X node SHOUL NOT PRINT!: " + value)

  println("as seq: " + t.toSeq)

  println("count: " + t.size)
  assert(t.size == 9)

  println("height: " + t.height)
  assert(t.height == 3)

  println("leaft count: " + t.leafCount)
  assert(t.leafCount == 4)

  println("as seqPreorder: " + t.toSeqPreorder)
  println("as seqInorder: " + t.toSeqInorder)
  println("as seqPostorder: " + t.toSeqPostorder)
  println("as seqLevelorder: " + t.toSeqLevelorder)

  println("last preorder :" + t.lastPreorder)
  println("last inorder :" + t.lastInorder)
  println("last postorder :" + t.lastPostorder)
  println("last levelorder: " + t.lastLevelorder)

  println("nth preorder 5 : " + t.nthPreorder(5))
  println("nth inorder 5 : " + t.nthInorder(5))
  println("nth postorder 5 : " + t.nthPostorder(5))
  println("nth levelorder 5 : " + t.nthLevelorder(5))

}