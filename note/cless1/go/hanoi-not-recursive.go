package main

import (
	"fmt"
	"os"
)

type Fream struct {
	n, pc         int
	from, to, via rune
}

func hanoi(n int, from, to, via rune) {
	stk := make([]*Fream, 264)
	top := -1

	call := func(n int, from, to, via rune) {
		top++
		stk[top] = &Fream{
			n:    n,
			pc:   0,
			from: from,
			to:   to,
			via:  via,
		}
	}

	call(n, from, to, via)
	for f := stk[top]; top >= 0; f.pc, f = f.pc+1, stk[top] {
		switch f.pc {
		case 0:
			if f.n == 1 {
				fmt.Println(string(f.from), " -> ", string(f.to))
				f.pc = 3
			}
		case 1:
			call(f.n-1, f.from, f.via, f.to)
		case 2:
			call(1, f.from, f.to, f.via)
		case 3:
			call(f.n-1, f.via, f.to, f.from)
		case 4:
			top = top - 1
			if top == -1 {
				os.Exit(0)
			}
		default:
			os.Exit(0)
		}
	}

}

func main() {
	hanoi(3, 'A', 'B', 'C')
}
