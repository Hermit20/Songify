objects = main.o View.o Controller.o Songify.o MediaFactory.o Criteria.o A_Criteria.o C_Criteria.o AorC_Criteria.o  Album.o Song.o

a4: $(objects)
	g++ -o a4 $(objects)

main.o: main.cc
	g++ -c main.cc

View.o: View.h View.cc
	g++ -c View.cc

Controller.o: Controller.h Controller.cc
	g++ -c Controller.cc

Songify.o: Songify.h Songify.cc
	g++ -c Songify.cc

MediaFactory.o: MediaFactory.h MediaFactory.cc
	g++ -c MediaFactory.cc

Criteria.o: Criteria.cc Criteria.h
	g++ -c Criteria.cc

A_Criteria.o: A_Criteria.cc A_Criteria.h
		g++ -c A_Criteria.cc

C_Criteria.o: C_Criteria.cc C_Criteria.h
		g++ -c C_Criteria.cc

AorC_Criteria.o: AorC_Criteria.cc AorC_Criteria.h
		g++ -c AorC_Criteria.cc

Array.o: Array.cc Array.h
		g++ -c Array.cc

Album.o: Album.cc Album.h
	g++ -c Album.cc

Song.o: Song.cc Song.h
	g++ -c Song.cc

clean:
	rm -f a4 *.o
