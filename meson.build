project(
  'kv',
  'c',
  'cpp',
  version: '0.1.0',
  license: 'MIT',
  meson_version: '>=0.57.1',
  default_options: [
    'cpp_std=c++20',
    'c_std=c11',
    'warning_level=3',
    'werror=false',
    'cpp_args=-Og -g',
    'cpp_debugstl=true',
  ],
)

add_global_arguments('-fcolor-diagnostics', language : 'cpp')  # ninja color output

fmt = dependency('fmt')  # it is too nice to have flake.nix
expected = dependency('tl-expected', method : 'cmake', modules : ['tl::expected'])
cxxabi = host_machine.system() == 'darwin' ? meson.get_compiler('cpp').find_library('c++abi') : []  # required on darwin

inc = [include_directories('include')]
deps = [fmt, expected, cxxabi]

src = files(
  'src/main.cpp',
  'src/kv.cpp',
  'src/skiplist.cpp',
)
executable(
  'kv',
  src,
  include_directories: inc,
  dependencies: deps,
)

skiplist_lib = library(
  'skiplist',
  src,
  include_directories: inc,
  dependencies: deps,
)

subdir('tests')
