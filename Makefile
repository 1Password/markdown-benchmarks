build:
	cd comrak && cargo build --release
	cd pulldown-cmark && cargo build --release
	cd cmark && gcc -I../../cmark/src -I../../cmark/build/src  -o cmark main.c ../../cmark/build/src/libcmark.a

run: build
	@echo "Blackfriday (Go):"
	go run blackfriday/main.go
	@echo "\nComrak (Rust):"
	cd comrak && cargo run -q --release
	@echo "\nPulldown-cmark (Rust):"
	cd pulldown-cmark && cargo run -q --release
	@echo "\nCmark (C)"
	cmark/cmark