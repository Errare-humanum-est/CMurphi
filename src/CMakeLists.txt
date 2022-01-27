find_package(FLEX 2.5.13)
find_package(BISON 2.1.3)
message("FLEX WAS FOUND = ${FLEX_FOUND}")
message("BISON WAS FOUND = ${BISON_FOUND}")


BISON_TARGET(parser mu.y ${CMAKE_CURRENT_SOURCE_DIR}/y.tab.c)
FLEX_TARGET(lexer mu.l ${CMAKE_CURRENT_SOURCE_DIR}/lex.yy.c)
ADD_FLEX_BISON_DEPENDENCY(lexer parser)


if (APPLE)
    set(FLEX_LIBRARIES libl.a)
endif ()
message("FLEX LIBRARIES = ${FLEX_LIBRARIES}")

set_source_files_properties(y.tab.c PROPERTIES COMPILE_FLAGS "-DYYDEBUG=0 -x c++")
set_source_files_properties(lex.yy.c PROPERTIES COMPILE_FLAGS "-x c++")
# disable warnings & enable optimization
add_compile_options(-O2 -w)
add_executable(mu
        cpp_code.cpp
        cpp_code_as.cpp
        cpp_sym.cpp
        cpp_sym_aux.cpp
        cpp_sym_decl.cpp
        decl.cpp
        error.cpp
        expr.cpp
        lextable.cpp
        mu.cpp
        parse.cpp
        rule.cpp
        stmt.cpp
        symtab.cpp
        util.cpp
        ${BISON_parser_OUTPUTS}
        ${FLEX_lexer_OUTPUTS}
)
target_link_options(mu PRIVATE -lm)
target_link_libraries(mu ${FLEX_LIBRARIES})
