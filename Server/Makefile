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

# executable이 생성될 디렉토리
EXECTUABLE_OUTPUT_DIR = ../output

# Include 디렉토리
INCLUDE_DIR =-I../3rdParty/ -I../NetworkLibrary/src/
#INCLUDE_DIR =-I/home/user/projects/cliontest/cpp_linux_server/3rdParty/ -I../NetworkLibrary/src/
#INCLUDE_DIR =

# 링킹할 커스텀 lib 파일의 위치
CUSTOM_LINK_PATH = -L../NetworkLibrary/lib/

# 링킹할 커스텀 lib 파일 이름
CUSTOM_LIB_TO_LINK = -lNetworkLibrary

# 다운로드 받은 lib 파일 중 링크할 파일
LIB_FILE_TO_LINK = -lodbc -lpqxx -lpulsarwithdeps

# SRC_DIR 디렉토리 안에 디렉토리들 제외하고(notdir) .cpp 파일들의 이름만 가져온다.
# 예 : src/maincpp => main.cpp
# 주의 : SRC_DIR 디렉토리의 sub directory 들은 해당 안 된다.
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp))

# 예 : SRCS가 main.cpp test.cpp 라면 main.o test.o 로 convert
OBJS = $(SRCS:.cpp=.o)

# OBJS 안의 object 파일들 이름 앞에 $(OBJ_DIR)/ 를 붙인다.
OBJS_W_OBJ_DIR = $(patsubst %.o,$(OBJ_DIR)/%.o, $(OBJS))

DEPS = $(OBJS_W_OBJ_DIR:.o=.d)

# 컴파일할 cpp 파일명 / cpp 파일명으로 executable 생성
TARGET = main


#============================
#	   Build Pipeline       #
#============================
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -MD $(CUSTOM_LINK_PATH) $(INCLUDE_DIR)

build : $(OBJS_W_OBJ_DIR)
	$(CC) $(CXXFLAGS) $(OBJS_W_OBJ_DIR) -o $(EXECTUABLE_OUTPUT_DIR)/$(TARGET) $(CUSTOM_LINK_PATH) $(CUSTOM_LIB_TO_LINK) $(LIB_FILE_TO_LINK)

.PHONY: clean all

clean:
	rm -rf $(OBJS_W_OBJ_DIR) $(EXECTUABLE_OUTPUT_DIR)/$(TARGET) $(DEPS) 

echo:
	@echo SRCS : $(SRCS)
	@echo OBJS : $(OBJS)

-include $(DEPS)