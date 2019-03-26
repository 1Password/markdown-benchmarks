# markdown-benchmarks

Testing performance of the popular markdown libraries:

* [blackfriday](https://github.com/russross/blackfriday)
* [comrak](https://github.com/kivikakk/comrak)
* [pulldown-cmark](https://github.com/raphlinus/pulldown-cmark)
* [cmark](https://github.com/commonmark/cmark)

Running benchmarks:

```bash
git clone git@github.com:commonmark/cmark.git
mkdir -p cmark/build
cd cmark/build
cmake ..
make
cd ../..

git clone git@github.com:hoedown/hoedown.git
cd hoedown
make
cd ..

git clone git@github.com:1Password/markdown-benchmarks.git
go get -u gopkg.in/russross/blackfriday.v2

cd markdown-benchmarks
make build
make run -s
```

Results on 2018 Mac Book Pro (2.9 GHz Intel Core i9)

```bash
$ make run -s
Blackfriday (Go):
  1000 iterations = 0.054s
 10000 iterations = 0.517s
100000 iterations = 5.149s

Comrak (Rust):
  1000 iterations =   0.258s
 10000 iterations =   2.560s
100000 iterations =  25.890s

Pulldown-cmark (Rust):
  1000 iterations =   0.041s
 10000 iterations =   0.380s
100000 iterations =   3.709s

Cmark (C):
  1000 iterations =   0.075s
 10000 iterations =   0.787s
100000 iterations =   7.880s

Hoedown (C):
  1000 iterations =   0.022s
 10000 iterations =   0.233s
100000 iterations =   2.262s
```


