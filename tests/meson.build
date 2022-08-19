gtest = dependency('gtest', main : true)

test_main = files('test_main.cpp')

sources = files(
  'test_skiplist.cpp',
)

test_exe = executable(
  'gtest',
  [test_main, sources],
  include_directories : inc,
  dependencies : [gtest, deps],
  link_with : [skiplist_lib],
)
test('unit tests', test_exe)
