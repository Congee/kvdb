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

fmt = dependency('fmt')  # it is too nice having have flake.nix
expected = dependency('tl-expected', method : 'cmake', modules : ['tl::expected'])
cxxabi = host_machine.system() == 'darwin' ? meson.get_compiler('cpp').find_library('c++abi') : []  # required on darwin

sources = files(
  'src/main.cpp',
  'src/kv.cpp',
  'src/kv.hpp',
  'src/skiplist.cpp',
  'src/skiplist.hpp',
  'src/common.hpp',
)
executable(
  'kv',
  sources,
  install: false,
  dependencies: [fmt, expected, cxxabi]
)
