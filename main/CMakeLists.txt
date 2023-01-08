# See the build system documentation in IDF programming guide
# for more information about component CMakeLists.txt files.

idf_component_register(
    SRCS storage.c wifi.c bluetooth.c unboxed.c main.c
    INCLUDE_DIRS .
    PRIV_INCLUDE_DIRS 
    REQUIRES 
    PRIV_REQUIRES 
)
