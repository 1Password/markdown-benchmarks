# markdown-benchmarks

Testing performance of the popular markdown libraries:

* [blackfriday](https://github.com/russross/blackfriday)
* [comrak](https://github.com/kivikakk/comrak)
* [pulldown-cmark](https://github.com/raphlinus/pulldown-cmark)
* [cmark](https://github.com/commonmark/cmark)

Running benchmarks:

```bash
git clone git@github.com:1Password/markdown-benchmarks.git
go get -u gopkg.in/russross/blackfriday.v2

git clone git@github.com:commonmark/cmark.git
mkdir -p cmark/build
cd cmark/build
cmake ..
make

cd markdown-benchmarks
make build
make run -s
```

Results on 2018 Mac Book Pro (2.9 GHz Intel Core i9)

```bash
$ make run -s
    Finished release [optimized] target(s) in 0.08s
    Finished release [optimized] target(s) in 0.04s
Blackfriday (Go):
  1000 iterations = 0.057s
 10000 iterations = 0.506s
100000 iterations = 5.210s

Comrak (Rust):
  1000 iterations =   0.259s
 10000 iterations =   2.625s
100000 iterations =  25.818s

Pulldown-cmark (Rust):
  1000 iterations =   0.040s
 10000 iterations =   0.397s
100000 iterations =   3.740s

Cmark (C)
  1000 iterations =   0.081s
 10000 iterations =   0.808s
100000 iterations =   7.946s
```


