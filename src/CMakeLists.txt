# Gather our source files in this directory.
set(
  riscbuddy_src_files
    "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ASTBuilder.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/AST.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Pass.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LabelReturn.cpp"
)

# Build our executable from the source files.
add_executable(riscbuddy ${riscbuddy_src_files})
target_include_directories(riscbuddy PUBLIC ${ANTLR_GEN_DIR})

# Ensure that the antlr4-runtime is available.
add_dependencies(riscbuddy antlr)

# Add the antlr runtime and parser as libraries to link.
target_link_libraries(riscbuddy parser antlr4-runtime)

# Symbolic link our executable to the base directory so we don't have to go searching for it.
symlink_to_bin("riscbuddy")
