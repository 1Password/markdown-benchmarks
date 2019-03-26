# markdown-benchmarks

Testing performance of the popular markdown libraries:

* [blackfriday](https://github.com/russross/blackfriday)
* [comrak](https://github.com/kivikakk/comrak)
* [pulldown-cmark](https://github.com/raphlinus/pulldown-cmark)
* [cmark](https://github.com/commonmark/cmark)
* [md4c](https://github.com/mity/md4c)

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

git clone git@github.com:mity/md4c.git

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
 10000 iterations = 0.514s
100000 iterations = 5.121s

Comrak (Rust):
  1000 iterations =   0.264s
 10000 iterations =   2.542s
100000 iterations =  26.623s

Pulldown-cmark (Rust):
  1000 iterations =   0.044s
 10000 iterations =   0.373s
100000 iterations =   3.785s

Cmark (C):
  1000 iterations =   0.080s
 10000 iterations =   0.798s
100000 iterations =   7.788s

Hoedown (C):
  1000 iterations =   0.023s
 10000 iterations =   0.228s
100000 iterations =   2.303s

MD4C (C) with empty callbacks:
  1000 iterations =   0.010s
 10000 iterations =   0.112s
100000 iterations =   1.088s
```


