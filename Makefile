build:
	cd comrak && cargo build -q --release
	cd pulldown-cmark && cargo build -q --release
	cd cmark && gcc -I../../cmark/src -I../../cmark/build/src  -o cmark main.c ../../cmark/build/src/libcmark.a
	cd hoedown && gcc -I../../hoedown/src -o hoedown main.c ../../hoedown/libhoedown.a

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
