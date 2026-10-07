# Makefile для практического задания 2 (вариант 2)
# Сборка и запуск:
#   Windows (MinGW):   mingw32-make
#   Linux:             make
#
#   mingw32-make clean   - удалить скомпилированные файлы
#   mingw32-make test    - запустить тесты

CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
TARGET = calculator
SRC = main.cpp

ifeq ($(OS),Windows_NT)
    TARGET = calculator.exe
    RM = del /Q
    EXE = calculator.exe
else
    RM = rm -f
    EXE = ./calculator
endif

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	-$(RM) $(TARGET)

test: $(TARGET)
	@echo --- Running without args (help) ---
	$(EXE)
	@echo.
	@echo --- summa 1 + 2 + 3 ---
	$(EXE) -o summa 1 2 3
	@echo.
	@echo --- summa 10+20+30+40+50 ---
	$(EXE) --operation summa 10 20 30 40 50
	@echo.
	@echo --- subtract 100 - 10 - 5 - 2 ---
	$(EXE) -o subtract 100 10 5 2
	@echo.
	@echo --- subtract 0-1-2-3-4 ---
	$(EXE) --operation subtract 0 1 2 3 4
	@echo.
	@echo --- summa with floating point ---
	$(EXE) -o summa 1.5 -2.5 3.0
	@echo.
	@echo --- help -h ---
	$(EXE) -h
