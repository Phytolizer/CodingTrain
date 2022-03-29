add_library(cpprocessing INTERFACE)
target_include_directories(cpprocessing INTERFACE include)
target_compile_features(cpprocessing INTERFACE cxx_std_20)

add_library(cpprocessing::cpprocessing ALIAS cpprocessing)
