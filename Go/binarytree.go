// Binary tree implementation in Go

package main

type Node struct {
	value int
	left  *Node
	right *Node
}

func (n *Node) insert(value int) {
	// your code here
}
func (n *Node) printTree() {
	// your code here
}

func main() {
	root := Node{value: 100}
	root.insert(50)
	root.insert(200)
	root.insert(25)
	root.printTree()
}
