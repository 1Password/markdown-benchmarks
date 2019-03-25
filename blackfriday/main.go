package main

import (
	"fmt"
	"io/ioutil"
	"time"

	"gopkg.in/russross/blackfriday.v2"
)

func main() {
	input, err := ioutil.ReadFile("sample1.md")
	if err != nil {
		panic(err)
	}

	{
		iterations := 1000
		startedAt := time.Now()
		for i := 0; i < iterations; i++ {
			_ = blackfriday.Run(input, blackfriday.WithNoExtensions())
		}
		elapsed := time.Since(startedAt)
		fmt.Printf("%6d iterations = %3.3fs\n", iterations, elapsed.Seconds())
	}

	{
		iterations := 10000
		startedAt := time.Now()
		for i := 0; i < iterations; i++ {
			_ = blackfriday.Run(input, blackfriday.WithNoExtensions())
		}
		elapsed := time.Since(startedAt)
		fmt.Printf("%6d iterations = %3.3fs\n", iterations, elapsed.Seconds())
	}

	{
		iterations := 100000
		startedAt := time.Now()
		for i := 0; i < iterations; i++ {
			_ = blackfriday.Run(input, blackfriday.WithNoExtensions())
		}
		elapsed := time.Since(startedAt)
		fmt.Printf("%6d iterations = %3.3fs\n", iterations, elapsed.Seconds())
	}
}
