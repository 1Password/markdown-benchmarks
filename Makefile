build:
	cd comrak && cargo build -q --release
	cd pulldown-cmark && cargo build -q --release
	cd cmark && gcc -O2 -I../../cmark/src -I../../cmark/build/src  -o cmark main.c ../../cmark/build/src/libcmark.a
	cd hoedown && gcc -O2 -I../../hoedown/src -o hoedown main.c ../../hoedown/libhoedown.a
	cd md4c && gcc -O2 -I../../md4c/md4c -o md4c main.c ../../md4c/md4c/md4c.c

clean:
	rm -rf comrak/target/release
	rm -rf pulldown-cmark/target/release
	rm cmark/cmark
	rm hoedown/hoedown
	rm md4c/md4c

run: build
	@echo "Blackfriday (Go):"
	go run blackfriday/main.go
	@echo "\nComrak (Rust):"
	cd comrak && cargo run -q --release
	@echo "\nPulldown-cmark (Rust):"
	cd pulldown-cmark && cargo run -q --release
	@echo "\nCmark (C):"
	cmark/cmark
	@echo "\nHoedown (C):"
	hoedown/hoedown
	@echo "\nMD4C (C) with empty callbacks:"
	md4c/md4c
