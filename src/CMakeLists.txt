# add headers and source files
SET(proj-src logging.hpp logging.cpp Node.hpp Node.cpp LinkedListCpp.hpp LinkedListCpp.cpp)

# Create the executable
# -----------------
ADD_EXECUTABLE( ${PROJECT_NAME} main.cpp ${proj-src})

