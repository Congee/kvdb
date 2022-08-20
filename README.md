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
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FCongee%2Fkvdb.svg?type=shield)](https://app.fossa.com/projects/git%2Bgithub.com%2FCongee%2Fkvdb?ref=badge_shield)

```bash
meson build     # generate build instructions
ninja -C build  # compile the project
./build/kv      # run the executable
```


# References:
https://github.com/balloonwj/CppGuide/blob/master/articles/leveldb源码分析/README.md


## License
[![FOSSA Status](https://app.fossa.com/api/projects/git%2Bgithub.com%2FCongee%2Fkvdb.svg?type=large)](https://app.fossa.com/projects/git%2Bgithub.com%2FCongee%2Fkvdb?ref=badge_large)