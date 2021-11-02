set(SDL2_IMAGE_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include/")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
  set(SDL2_IMAGE_LIBRARIES "${CMAKE_SOURCE_DIR}/lib/x64/SDL2_image.lib")
else ()
  set(SDL2_IMAGE_LIBRARIES "${CMAKE_SOURCE_DIR}/lib/x86/SDL2_image.lib")
endif ()

string(STRIP "${SDL2_IMAGE_LIBRARIES}" SDL2_IMAGE_LIBRARIES)
