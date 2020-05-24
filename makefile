CC_EXEC = g++
CC_FLAGS = -std=c++11

CC = ${CC_EXEC} ${CC_FLAGS}

BUILD_DIR = build

all: executable.out

executable.out:  ${BUILD_DIR}/main.o ${BUILD_DIR}/Store.o ${BUILD_DIR}/Goods.o ${BUILD_DIR}/Members.o ${BUILD_DIR}/Struct.o ${BUILD_DIR}/Exceptions.o 
	g++  ${BUILD_DIR}/main.o ${BUILD_DIR}/Store.o ${BUILD_DIR}/Goods.o ${BUILD_DIR}/Members.o ${BUILD_DIR}/Struct.o ${BUILD_DIR}/Exceptions.o -o ${BUILD_DIR}/exectable.out

${BUILD_DIR}/main.o: main.cpp Store.hpp Goods.hpp Members.hpp Struct.hpp Exceptions.hpp
	${CC} -c main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/Exceptions.o: Exceptions.cpp Exceptions.hpp
	${CC} -c Exceptions.cpp -o ${BUILD_DIR}/Exceptions.o

${BUILD_DIR}/Struct.o: Struct.cpp Struct.hpp Members.hpp Exceptions.hpp
	${CC} -c Struct.cpp -o ${BUILD_DIR}/Struct.o

${BUILD_DIR}/Goods.o: Goods.cpp Goods.hpp Exceptions.hpp Struct.hpp
	${CC} -c Goods.cpp -o ${BUILD_DIR}/Goods.o

${BUILD_DIR}/Members.o: Members.cpp Members.hpp Goods.hpp Struct.hpp Exceptions.hpp
	${CC} -c Members.cpp -o ${BUILD_DIR}/Members.o

${BUILD_DIR}/Store.o: Store.cpp Store.hpp Goods.hpp Members.hpp Struct.hpp Exceptions.hpp
	${CC} -c Store.cpp -o ${BUILD_DIR}/Store.o

.PHONY: clean
clean:
	rm -rf build/ && mkdir -p build