## install lin binary to bin and header to include
add_library (mysqrt mysqrt.cpp)
install (TARGETS mysqrt DESTINATION bin)
install (FILES mysqrt.h DESTINATION include)

