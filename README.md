# markdown-benchmarks

Testing performance of the popular markdown libraries:

* [blackfriday](https://github.com/russross/blackfriday)
* [comrak](https://github.com/kivikakk/comrak)
* [pulldown-cmark](https://github.com/raphlinus/pulldown-cmark)

Running benchmarks:

```bash
git clone git@github.com:1Password/markdown-benchmarks.git
go get -u gopkg.in/russross/blackfriday.v2
cd markdown-benchmarks
./run-benchmarks.sh
```

Results on 2017 iMac Pro (3 GHz Intel Xeon W):

```bash
$ ./run-benchmarks.sh
Blackfriday Go Library
  1000 iterations = 0.057s
 10000 iterations = 0.549s
100000 iterations = 5.477s

Comrak Rust Library
    Finished release [optimized] target(s) in 0.07s
     Running `target/release/comrak`
  1000 iterations =   0.239s
 10000 iterations =   2.347s
100000 iterations =  23.714s

Pulldown-cmark Rust Library
    Finished release [optimized] target(s) in 0.03s
     Running `target/release/pulldown-cmark`
  1000 iterations =   0.035s
 10000 iterations =   0.338s
100000 iterations =   3.351s
```


