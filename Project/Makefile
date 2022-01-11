
build: course.o tools.o main.o student.o
	g++ build/course.o build/file.o build/main.o build/student.o -o bin/app

course.o: src/course.cpp src/headers/course.h
	g++ -c src/course.cpp -o build/course.o

tools.o: src/headers/tools.h src/tools.cpp
	g++ -c src/tools.cpp -o build/file.o

main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o

student.o: src/student.cpp src/headers/student.h
	g++ -c src/student.cpp -o build/student.o

clean:
	rm build/*.o bin/app

run:
	./bin/app