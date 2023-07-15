#============================
#	Variable Declaration	#
#============================

# 사용할 compiler
CC = g++

# C++ 컴파일러 옵션
CXXFLAGS = -g

# 소스 파일이 위치한 디렉토리
SRC_DIR =./src

# 오브젝트 파일이 생성될 디렉토리
OBJ_DIR =./obj

# Static library 파일(.a)이 생성될 디렉토리
LIB_OUTPUT_DIR = ./lib

# Include 디렉토리
INCLUDE_DIR =../3rdParty/
#INCLUDE_DIR =

# 링커 옵션
LDFLAGS =

# SRC_DIR 디렉토리 안에 디렉토리들 제외하고(notdir) .cpp 파일들의 이름만 가져온다.
# 예 : src/maincpp => main.cpp
# 주의 : SRC_DIR 디렉토리의 sub directory 들은 해당 안 된다.
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))

# 예 : SRCS가 main.cpp test.cpp 라면 main.o test.o 로 convert
OBJS = $(SRCS:.cpp=.o)

# OBJS 안의 object 파일들 이름 앞에 $(OBJ_DIR)/ 를 붙인다.
OBJS_W_OBJ_DIR = $(patsubst %.o,$(OBJ_DIR)/%.o, $(OBJS))

DEPS = $(OBJS_W_OBJ_DIR:.o=.d)

#생성할 Static Library 명
LIBRARY_NAME = libNetworkLibrary

TARGET = build




#=======================================
#	   Static Libray Build Pipeline    #
#=======================================

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -MD $(LDFLAGS) -I $(INCLUDE_DIR)

# Static Library를 생성할 때는 ar 커맨드를 사용한다
# ar rvs [생성할 .a 이름] [...포함시킬 .o 파일들]
$(TARGET) : $(OBJS_W_OBJ_DIR)
	ar rvs $(LIBRARY_NAME).a $(OBJS_W_OBJ_DIR)
	mv $(LIBRARY_NAME).a $(LIB_OUTPUT_DIR)

.PHONY: clean all

clean:
	rm -rf $(OBJS_W_OBJ_DIR) $(LIB_OUTPUT_DIR)/$(LIBRARY_NAME) $(DEPS) 

-include $(DEPS)