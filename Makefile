all:make

make: Hunter.o Terrain.o Mountain.o Savanna.o Jungle.o
	clang++ -std=c++11 main.cpp Hunter.o Terrain.o Mountain.o Savanna.o Jungle.o
	./a.out

Hunter.o: Hunter.cpp Hunter.h Event.h Story.h
	g++ -c Hunter.cpp

Terrain.o: Terrain.cpp Terrain.h
	g++ -c Terrain.cpp

Mountain.o: Mountain.cpp Mountain.h
	g++ -c Mountain.cpp

Savanna.o: Savanna.cpp Savanna.h
	g++ -c Savanna.cpp

Jungle.o: Jungle.cpp Jungle.h
	g++ -c Jungle.cpp

#Test cases for Mountain
Test1: Hunter.o Terrain.o Mountain.o Savanna.o Jungle.o
	g++ -std=c++11 main.cpp Hunter.o Terrain.o Mountain.o Savanna.o Jungle.o -o test1
	./test1 < input-1-1.txt > output-1-1.txt

#Test cases for Savanna
Test2: Hunter.o Terrain.o Mountain.o Savanna.o Jungle.o
	g++ -std=c++11 main.cpp Hunter.o Terrain.o Mountain.o Savanna.o Jungle.o -o test2
	./test2 < input-2-1.txt > output-2-1.txt

#Test cases for Jungle
Test3: Hunter.o Terrain.o Mountain.o Savanna.o Jungle.o
	g++ -std=c++11 main.cpp Hunter.o Terrain.o Mountain.o Savanna.o Jungle.o -o test3
	./test3 < input-3-1.txt > output-3-1.txt

Test: Test1 Test2 Test3

clean:
	rm -rf *o make

#Regression Testing Area

#Hunter, event and story, as event and story are both just .h files
RTest1: Hunter.o
	g++ -std=c++11 mainHuntEvenStor.cpp Hunter.o -o Rtest1
	./Rtest1 < input-HuntEvenStor.txt

#Terrain
RTest2: Terrain.o
	g++ -std=c++11 mainTerrain.cpp Terrain.o -o Rtest2
	./Rtest2 < input-Terrain.txt

#Jungle, which includes Terrain
RTest3: Jungle.o Terrain.o
	g++ -std=c++11 mainJungle.cpp Jungle.o Terrain.o -o Rtest3
	./Rtest3

#Mountain, includes Terrain
RTest4: Mountain.o Terrain.o
	g++ -std=c++11 mainMountain.cpp Mountain.o Terrain.o -o Rtest4
	./Rtest4

#Savanna, includes Terrain
RTest5: Savanna.o Terrain.o
	g++ -std=c++11 mainSavanna.cpp Savanna.o Terrain.o -o Rtest5
	./Rtest5

RTests: RTest1 RTest2 RTest3 RTest4 RTest5