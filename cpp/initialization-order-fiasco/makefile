OK_ORDER=code/A.cpp code/B.cpp code/main.cpp
FIASCO_ORDER=code/B.cpp code/A.cpp code/main.cpp

all:
  g++ $(OK_ORDER) -o program

fiasco:
  g++ $(FIASCO_ORDER) -o fiasco
