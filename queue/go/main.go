package main

import "fmt"

type queue []int

func (q *queue) push(v int) {
	*q = append(*q, v)
}

func (q *queue) pop() int {
    if (len(*q) == 0) {
        return 0;
    }
	r := (*q)[0]
	*q = (*q)[1:]
	return r
}

func main() {
	var q queue

	q.push(10)
	q.push(20)
	q.push(30)
	q.push(40)

	fmt.Println("10 -", q.pop())
	fmt.Println("20 -", q.pop())
	fmt.Println("30 -", q.pop())
	q.push(11)
	q.push(12)
	fmt.Println("40 -", q.pop())
	fmt.Println("11 -", q.pop())
	fmt.Println("12 -", q.pop())
	fmt.Println("0 -", q.pop())
}
