#! /bin/sh

echo "Blackfriday Go Library"
go run blackfriday/main.go

echo "\nComrak Rust Library"
cd comrak && cargo run --release

echo "\nPulldown-cmark Rust Library"
cd ../pulldown-cmark && cargo run --release