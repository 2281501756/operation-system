package main

import (
	"fmt"
	"io/fs"
	"path/filepath"
)

func main() {
	filepath.WalkDir("/proc", func(path string, d fs.DirEntry, err error) error {
		// if d.IsDir() && unicode.IsDigit(rune(d.Name()[0])) {
		// }
		if d == nil {
			return nil
		}
		fmt.Println(d.Name())
		return nil
	})

}
