This project aims to implement a KV database.

<details>
<summary>Dependencies</summary>

* meson
* ninja
* fmtlib  @ https://github.com/fmtlib/fmt
* tl::expected @ https://github.com/TartanLlama/expected
* gtest

These are all external dependencies. Please install them on your platform by
yourself.
</details>

# Build
```bash
meson build     # generate build instructions
ninja -C build  # compile the project
./build/kv      # run the executable
```


# References:
https://github.com/balloonwj/CppGuide/blob/master/articles/leveldb源码分析/README.md
