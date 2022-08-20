# A Distributed Key Value Store

<details>
<summary>Dependencies</summary>

* meson
* ninja
* [fmtlib](https://github.com/fmtlib/fmt)
* [tl::expected](https://github.com/TartanLlama/expected)
* [gtest](https://github.com/google/googletest)

These are all external dependencies. Please install them on your platform by
yourself.
</details>

## Build

```bash
meson setup --native-file=native.ini build/     # generate build instructions
meson compile -C build                          # build the project
```

## Run

```bash
./build/kv              # run the executable
meson test -C build     # run tests
```

## References

1. <https://github.com/balloonwj/CppGuide/blob/master/articles/leveldb源码分析/README.md>
