
option(USE_MYMATH "Use the math implementation" ON)

add_library(MathFunctions STATIC MathFunctions.cxx)

if (USE_MYMATH)
  target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")
endif()

if (USE_MYMATH)
  add_library(SqrtLibrary STATIC mysqrt.cxx)
endif()

if (USE_MYMATH)
  target_link_libraries(MathFunctions PRIVATE SqrtLibrary)
endif()
