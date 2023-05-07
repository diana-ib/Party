Ass5:democraticLeader.o democraticParty.o democraticSocial.o leader.o main.o Party.o PoliticalSys.o Politician.o republicanLeader.o republicanParty.o republicanSocial.o social.o
	g++ democraticLeader.o democraticParty.o democraticSocial.o leader.o main.o Party.o PoliticalSys.o Politician.o republicanLeader.o republicanParty.o republicanSocial.o social.o -o Ass5
democraticLeader.o: democraticLeader.cpp democraticLeader.h leader.h Politician.h
	g++ -c democraticLeader.cpp
democraticParty.o: democraticParty.cpp democraticParty.h Party.h Politician.h
	g++ -c democraticParty.cpp
democraticSocial.o: democraticSocial.cpp democraticSocial.h social.h Politician.h
	g++ -c democraticSocial.cpp
leader.o: leader.cpp leader.h Politician.h Party.h
	g++ -c leader.cpp
main.o: main.cpp PoliticalSys.h democraticLeader.h democraticParty.h democraticSocial.h leader.h Party.h Politician.h republicanLeader.h republicanParty.h republicanSocial.h social.h Errors.h
	g++ -c main.cpp
Party.o: Party.cpp Party.h Politician.h
	g++ -c Party.cpp
PoliticalSys.o: PoliticalSys.cpp PoliticalSys.h democraticLeader.h democraticParty.h democraticSocial.h leader.h Party.h Politician.h republicanLeader.h republicanParty.h republicanSocial.h social.h Errors.h
	g++ -c PoliticalSys.cpp
Politician.o: Politician.cpp Politician.h Party.h
	g++ -c Politician.cpp
republicanLeader.o: republicanLeader.cpp republicanLeader.h leader.h Politician.h
	g++ -c republicanLeader.cpp
republicanParty.o: republicanParty.cpp republicanParty.h Party.h Politician.h
	g++ -c republicanParty.cpp
republicanSocial.o: republicanSocial.cpp republicanSocial.h social.h Politician.h
	g++ -c republicanSocial.cpp
social.o: social.cpp social.h Politician.h Party.h
	g++ -c social.cpp
clean :
	rm -f *.o