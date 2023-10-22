package main

import "fmt"

type Stack []int

func main() {
    stack := Stack{}
    stack.push(10)
    stack.push(20)
    stack.push(30)
    stack.push(10)

    for !stack.isEmpty() {
        fmt.Println(stack.pop())
    }
}

func (st *Stack) push(value int) {
    *st = append(*st, value)
}

func (st *Stack) pop() int {
    if st.isEmpty() {
        return 0
    }
    value := (*st)[len(*st) - 1]
    *st = (*st)[:len(*st) - 1]
    return value
}

func (st *Stack) isEmpty() bool {
    if len(*st) == 0 {
        return true
    }
    return false
}
