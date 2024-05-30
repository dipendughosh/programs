// go: build
package math

import (
	"fmt"
	"os"
	"testing"
	"time"
)

func Add(a, b int) int {
	time.Sleep(1 * time.Second / 100)
	c := a + b
	fmt.Fprintf(os.Stdout, "Add - %d + %d = %d\n", a, b, c)
	return a + b

}

func Subtract(a, b int) int {
	time.Sleep(1 * time.Second / 100)
	c := a - b
	fmt.Fprintf(os.Stdout, "Subtract - %d - %d = %d\n", a, b, c)
	return c
}

func Multiply(a, b int) int {
	time.Sleep(1 * time.Second / 100)
	c := a * b
	fmt.Fprintf(os.Stdout, "Multiply - %d * %d = %d\n", a, b, c)
	return c
}

func Divide(a, b int) (int, error) {
	time.Sleep(1 * time.Second / 100)
	if b == 0 {
		return 0, fmt.Errorf("cannot divide by zero")
	}
	c := a / b
	fmt.Fprintf(os.Stdout, "Divide - %d * %d = %d\n", a, b, c)
	return c, nil
}

func performAction(t *testing.T) {
	t.Log("Action: Performed an action")
}
