add_library(MathFunctions MathFunctions.cxx)

target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_library(tutorial_compiler_flags INTERFACE)
target_compile_features(tutorial_compiler_flags INTERFACE cxx_std_11)
target_link_libraries(Tutorial PUBLIC MathFunctions tutorial_compiler_flags)
# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)
if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

  # library that just does sqrt
  add_library(SqrtLibrary STATIC
              mysqrt.cxx
              )

  # TODO 7: Link SqrtLibrary to tutorial_compiler_flags

  target_link_libraries(MathFunctions PUBLIC SqrtLibrary)
endif()

# TODO 6: Link MathFunctions to tutorial_compiler_flags
target_link_libraries(SqrtLibrary PUBLIC tutorial_compiler_flags)
