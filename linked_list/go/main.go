package main

import "fmt"

type element struct {
    data int
    next *element
}

type list struct {
    head *element
}

func (l *list) add(data int) {
    e := &element{
        data: data,
    }

    if l.head == nil {
        l.head = e
        return
    }

    last := l.head
    for last.next != nil {
        last = last.next
    }
    last.next = e
    return
}

// removes the first occurrence
func (l *list) delete(data int) {
    if l.head == nil {
        return
    }

    h := l.head

    if h.data == data {
        l.head = h.next
        return
    }

    for h.next != nil {
        if h.next.data == data {
            h.next = h.next.next
            return
        }
        h = h.next
    }
}

func (l *list) find(data int) *element {
    for e := l.head; e != nil; e = e.next {
        if e.data == data {
            return e
        }
    }
    return nil
}

func main() {
    var head list

    head.add(10)
    head.add(20)
    head.add(30)
    head.add(40)

    head.delete(30)

    if e := head.find(20); e != nil {
        fmt.Println("found 20")
    } else {
        fmt.Println("Cannot find 20")
    }
    head.delete(20)
    if e := head.find(20); e != nil {
        fmt.Println("found 20")
    } else {
        fmt.Println("Cannot find 20")
    }
}
