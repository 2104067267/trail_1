set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

ADD_SUBDIRECTORY(googletest EXCLUDE_FROM_ALL)
AUX_SOURCE_DIRECTORY(. SOURCE)
ADD_EXECUTABLE(training_main ${SOURCE}
        ../include/Executor.h
        ../src/hello.cpp
        ExecutorTest.cpp
        ../include/Executorlmpl.h
        ../src/Executorlmpl.cpp
        ExecutorlmplTest.cpp
        ../include/Pose.h
        ../include/Pose.h
        ../src/Pose.cpp
        ../src/Pose.cpp
        ExecutorlmplTest.cpp
        ExecutorlmplTest.cpp
        ../include/Command.h
        ../include/PoseHandler.h
        ../src/PoseHandler.cpp
        ../src/Command.cpp
        ../include/Point.h
        ../src/Point.cpp

)
TARGET_LINK_LIBRARIES(training_main training gtest_main)

ADD_TEST(NAME training_main COMMAND training_main)
