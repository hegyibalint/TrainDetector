project(traindetector)

set(HEADER_FILES
        enums.h
        debouncer.h
        traindetection.h
        traindetector.h)

set(SOURCE_FILES
        debouncer.cpp
        traindetection.cpp
        traindetector.cpp)

add_library(traindetector STATIC ${SOURCE_FILES} ${HEADER_FILES})