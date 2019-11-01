package main

import "syscall/js"

// This calls a JS function from Go.
func main() {
	println("adding two numbers:", add(2, 3)) // expecting 5
	addToDocument();
}


func add(x, y int) int {
	return x + y;
}

func addToDocument() {
	document := js.Global().Get("document")
    p := document.Call("createElement", "p")
    p.Set("innerHTML", "Hello from Go!")
    document.Get("body").Call("appendChild", p)
}

//go:export multiply
func multiply(x, y int) int {
    return x * y;
}