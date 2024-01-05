package main

/*
#include <time.h>
*/
import "C"

import "fmt"

func main() {
	// 调用 tzset 函数
	C.tzset()

	// 获取时区信息
	tz := C.GoString(C.tzname[0])
	offset := int(C.timezone)

	fmt.Printf("Time zone: %s, Offset: %d seconds\n", tz, offset)
}
