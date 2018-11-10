cmake_minimum_required(VERSION 3.7)
project(external)

add_library(Catch2 INTERFACE)

target_include_directories(Catch2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch2/include)

target_compile_features(Catch2
  INTERFACE
    cxx_alignas
    cxx_alignof
    cxx_attributes
    cxx_auto_type
    cxx_constexpr
    cxx_defaulted_functions
    cxx_deleted_functions
    cxx_final
    cxx_lambdas
    cxx_noexcept
    cxx_override
    cxx_range_for
    cxx_rvalue_references
    cxx_static_assert
    cxx_strong_enums
    cxx_trailing_return_types
    cxx_unicode_literals
    cxx_user_literals
    cxx_variadic_macros
)

add_library(Catch2::Catch2 ALIAS Catch2)

add_subdirectory(entityx EXCLUDE_FROM_ALL)
add_library(entityx::entityx ALIAS entityx)

