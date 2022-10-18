testinput02: main.o Movie_checking.o Genre_preferences.o Studio_preferences.o Ratings_preferences.o Release_year_preferences.o User_preferences.o User_details.o Movies_Database.o
	g++ main.o Movie_checking.o Genre_preferences.o Studio_preferences.o Ratings_preferences.o Release_year_preferences.o User_preferences.o User_details.o Movies_Database.o -o testingInput2
	./testingInput2 < testinput02.txt > testoutput02.txt
	diff correctinput02.txt testoutput02.txt

testinput01: main.o Movie_checking.o Genre_preferences.o Studio_preferences.o Ratings_preferences.o Release_year_preferences.o User_preferences.o User_details.o Movies_Database.o
	g++ main.o Movie_checking.o Genre_preferences.o Studio_preferences.o Ratings_preferences.o Release_year_preferences.o User_preferences.o User_details.o Movies_Database.o -o testingInput1
	./testingInput1 < testinput01.txt > testoutput01.txt
	diff correctinput01.txt testoutput01.txt

output: main.o Movie_checking.o Genre_preferences.o Studio_preferences.o Ratings_preferences.o Release_year_preferences.o User_preferences.o User_details.o Movies_Database.o
	g++ main.o Movie_checking.o Genre_preferences.o Studio_preferences.o Ratings_preferences.o Release_year_preferences.o User_preferences.o User_details.o Movies_Database.o -o makefileMain
	clear
	./makefileMain

main.o: main.cpp 
	g++ -c main.cpp 

Movie_checking.o: Movie_checking.cpp Movie_checking.h Genre_preferences.h Studio_preferences.h Ratings_preferences.h Release_year_preferences.h User_preferences.h User_details.h Movies_database.h
	g++ -c Movie_checking.cpp

Genre_preferences.o: Genre_preferences.cpp Genre_preferences.h Preferences.h User_preferences.h User_details.h Movies_database.h
	g++ -c Genre_preferences.cpp

Studio_preferences.o: Studio_preferences.cpp Studio_preferences.h Preferences.h User_preferences.h User_details.h Movies_database.h
	g++ -c Studio_preferences.cpp

Ratings_preferences.o: Ratings_preferences.cpp Ratings_preferences.h Preferences.h User_preferences.h User_details.h Movies_database.h
	g++ -c Ratings_preferences.cpp

Release_year_preferences.o: Release_year_preferences.cpp Release_year_preferences.h Preferences.h User_preferences.h User_details.h Movies_database.h
	g++ -c Release_year_preferences.cpp

User_preferences.o: User_preferences.cpp User_preferences.h User_details.h Movies_database.h
	g++ -c User_preferences.cpp
 
User_details.o: User_details.cpp User_details.h Movies_database.h
	g++ -c User_details.cpp

Movies_Database.o: Movies_database.h Movies_database.cpp
	g++ -c Movies_Database.cpp
 
clean:
	rm *.o