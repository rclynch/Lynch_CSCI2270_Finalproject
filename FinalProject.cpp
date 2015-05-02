//Ryan C Lynch
//csci 2270
//Final Project
//MAIN DRIVER

//use the following syntax in your terminal to run the code, make sure you compile in the right directory:

//g++ -std=c++11 FinalProject.cpp MovieTree.cpp  -o FinalProject
//./FinalProject projectMovies.txt cpi.txt questionBank.txt

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <istream>
//#include "MovieTree.cpp"
#include "MovieTree.h"

int main(int argc, char* argv[])
//int main()
{
	// cout<<"mainstart"<<endl;
	bool messageCheck;//Used to check if message file open
	bool cpiCheck;//Used to check if cpi file opens
	bool questionCheck;//Used to check if question file opens
	string object;
	int ranking;
	string title;
	double year;
	string director;
	string actor;
	string genre;
	int gross;
	double cpiYear;
	double cpi;
	string question;
	string answer;
	MovieTree call;//creating instance of class
	
	//Reading in projectMovies.txt file, parsing by commas and assigning each index to rank,
	//title, year, director, actor, genre, and gross. Then calling buildVector with all info for parameters.
	
	ifstream messageFile(argv[1]);
	//ifstream messageFile("projectMovies.txt");
	if(messageFile.fail())
	{
		cout <<"Failed to open file" <<endl;
		messageCheck = false;
	}
	if(messageFile.is_open())
	{
		messageCheck = true;
		while(!messageFile.eof())
		{
			getline(messageFile, object, ',');
			ranking = stoi(object);
			//cout <<ranking<<endl;
			getline(messageFile, object, ',');
			title = object;
			//cout<<title<<endl;
			getline(messageFile, object, ',');
			year = stoi(object);
			//cout<<year<<endl;
			getline(messageFile, object, ',');
			director = object;
			//cout<<director<<endl;
			getline(messageFile, object, ',');
			actor = object;
			//cout<<actor<<endl;
			getline(messageFile, object, ',');
			genre = object;
			//cout<<genre<<endl;
			getline(messageFile, object, ',');
			gross = stoi(object);
			getline(messageFile, object);
			//cout<<gross<<endl;
			
			call.buildVector(ranking, title, year, director, actor, genre, gross);
 		}
	}
	messageFile.close();
	
	//Reading in cpi.txt file, parsing by comma, and assigning index's to year, and cpi value. 
	//Then addCpi is called with the info as parameters.
	
	ifstream cpiFile(argv[2]);
	//ifstream cpiFile("cpi.txt");
	if(cpiFile.fail())
	{
		cout <<"Failed to open file" <<endl;
		cpiCheck = false;
	}
	if(cpiFile.is_open())
	{
		cpiCheck = true;
		while(!cpiFile.eof())
		{
			getline(cpiFile, object, ',');
			//cout<<object<<endl;
			cpiYear = stod(object);
			//cout<<cpiYear<<endl;
			getline(cpiFile, object);
			//cout<<object<<endl;
			cpi = stod(object);
			//cout<<cpi<<endl;
			
			call.addCpi(cpiYear, cpi);
 		}
	}
	cpiFile.close();
	
	//Reading in questionsBank.txt file, parsing by comma, and assigning info to question, and answer.
	//buildQVector is then called with question and answer passed in.
	
	ifstream questionFile(argv[3]);
	//ifstream questionFile("questionBank.txt");
	if(questionFile.fail())
	{
		cout <<"Failed to open file" <<endl;
		questionCheck = false;
	}
	if(questionFile.is_open())
	{
		questionCheck = true;
		while(!questionFile.eof())
		{
			getline(questionFile, object, ',');
			//cout<<object<<endl;
			question = object;
			//cout<<question<<endl;
			getline(questionFile, object);
			//cout<<object<<endl;
			answer = object;
			//cout<<answer<<endl;
			
			call.buildQVector(question, answer);
 		}
	}
	questionFile.close();
	
	bool check = true;
	
	//displaying menu and user interface:
	while(check == true && messageCheck == true)
	{
		int command;
		cout << "======Main Menu====="<<endl<<"1.Print Top 25 Movies "<<endl<<"2.Print In Order of Highest Total Domestic Gross"<<endl;
		cout<<"3.Print In Order of Highest Gross Adjusted for Inflation"<<endl<<"4.Print Movies in Alphebetical Order"<<endl;
		cout<<"5.Print by Director Name"<<endl<<"6.Print by Actor Name"<<endl<<"7.Print by Genre"<<endl;
		cout<<"8.Print All Movie Info"<<endl<<"9.Play Movie Trivia"<<endl<<"10.Quit"<<endl;
		cin>>command;
		if(command == 1)//print top 25 movies
		{
			call.printTopMovies();
			check = true;
		}
		else if(command == 2)//print in order of highest grossing
		{
			call.printHighestGrossing();
			check = true;
		}
		else if(command ==3)//print in order of highest grossing adjusted for inflation
		{
			if(cpiCheck == false){
	                	cout<<"cpi file did not open. Unable to run command."<<endl;
			}else{
				call.printByGrossInflated();
				check = true;
			}
		}
		else if(command == 4)//print in alphebetical order of movieTitle
		{
			call.printByTitle();
		}
		else if(command == 5)//print in alphebetical order of movie director
		{
			call.printByDirector();
		}
		else if(command == 6)//print in alphebetical order of movie's main actor
		{
			call.printByActor();
		}
		else if(command == 7)//print all movies (in order of rank) and corresponding movie genre
		{
			call.printByGenre();
		}
		else if(command == 8)//print all movie information
		{
			call.printAllMovieInfo();
		}
		else if(command == 9)//play movie Trivia
		{
			if(questionCheck == false){
                		cout<<"Question file did not open. Unable to run command."<<endl;
			}else{
				call.movieTrivia();
			}
		}
		else if(command == 10)//quit
		{
			cout<< "Goodbye!" <<endl;
			check = false;
		}
	}//end of while loop
	if(messageCheck == false){
	    cout<<"Message file did not open. Unable to run program."<<endl;
	}
	
	return 0;
}
