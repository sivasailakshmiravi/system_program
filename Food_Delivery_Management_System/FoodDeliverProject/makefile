CXX = g++
CXXFLAGS = -g
EXEC = food
OBJS = Menu.o Users.o location.o main.o # List of object files needed to
# build the executable.
${EXEC}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${EXEC} ${OBJS}
menu.o: Menu.cpp Menu.h
	${CXX} ${CXXFLAGS} -c Menu.cpp
Users.o: Users.cpp Users.h
	${CXX} ${CXXFLAGS} -c Users.cpp
location.o: location.cpp location.h
	${CXX} ${CXXFLAGS} -c location.cpp
main.o: main.cpp Menu.h location.h Users.h
	${CXX} ${CXXFLAGS} -c main.cpp
clean:
	rm -f ${EXEC} ${OBJS}i
