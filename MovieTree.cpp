//Ryan C. Lynch
//csci2270
//Final Project
//Method definitions

//NOTES:

//mainVector is always kept in order of rank by calling sortByRank whenever it is re-ordered for the various other functions.

//CPI: consumer price index
//TDG: total domestic gross

/*
 * Order of Functions:
 * 1 - printTopMovies
 * 2 - sortByRank
 * 3 - printAllMovieInfo
 * 4 - printHighestGrossing
 * 5 - sortByGross
 * 6 - printByTitle
 * 7 - sortBytTitle
 * 8 - printByGrossInflated
 * 9 - sortByGrossInflated
 * 10 - adjustGross
 * 11 - inflationFutureCalculator
 * 12 - reAdjustGross
 * 13 - inflationPresentCalculator
 * 14 - searchCPI
 * 15 - printByDirector
 * 16 - sortByDirector
 * 17 - printByActor
 * 18 - sortByActor
 * 19 - printByGenre
 * 20 - movieTrivia
 * 21 - addCpi
 * 22 - buildVector
 * 23 - buildQVector
 */
using namespace std;
#include <iostream>
#include "MovieTree.h"
#include <vector>
#include <cmath>

MovieTree::MovieTree()
{
}
MovieTree::~MovieTree()
{
}
//printTopMovies function goes through the mainVector and prints out each movie's ranking and corresponding title.
void MovieTree::printTopMovies()
{
	sortByRank();
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		cout<<"Ranking: "<<mainVector[i]->ranking<<endl;
		cout<<"Movie: "<<mainVector[i]->title<<endl;
		cout<<" "<<endl;
	}
}
//sortByRank perfoms a sorting algorithm in a bubble sort style to mainVector. The Vector is sorted by highest ranking in ascending order.
//sortByRank is called at end of every sorting function in order to maintain orginization of mainVector( which is initially by rank)
void MovieTree::sortByRank()
{
	bool isSorted = false;
	while(isSorted == false)
	{
		isSorted = true;
		for(unsigned int i = 0; i < mainVector.size() - 1; i++)
		{
			if(mainVector[i]->ranking > mainVector[i+1]->ranking)
			{
				MovieNode* temp = mainVector[i];
				mainVector[i] = mainVector[i+1];
				mainVector[i+1] = temp;
				isSorted = false;
			}
		}
	}
}
//printAllMovieInfo loops through the mainVector and prints out each movie and all of it's corresponding information
void MovieTree::printAllMovieInfo()
{
	sortByRank();
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		cout<<"Movie: "<<mainVector[i]->title<<endl;
		cout<<"Ranking: "<<mainVector[i]->ranking<<endl;
		cout<<"Year: "<<mainVector[i]->year<<endl;
		cout<<"Director: "<<mainVector[i]->director<<endl;
		cout<<"Main actor: "<<mainVector[i]->mainActor<<endl;
		cout<<"Genre: "<<mainVector[i]->genre<<endl;
		cout<<"Total Domestic Gross: "<<"$"<<mainVector[i]->totalDomesticGross<<endl;
		cout<<" "<<endl;
	}
}
//printHighestGrossing function first calls sortByGross to do a bubble type sort on the mainVector, then loops through the mainVector..
//printing all movies and their corresponding total domestic gross in decending order.
//Once all movies are printed it calls sortByRank to re-arrange mainVector by rank.
void MovieTree::printHighestGrossing()
{
	sortByGross();
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		cout<<"Movie: "<<mainVector[i]->title<<endl;
		cout<<"Total Domestic Gross: "<<"$"<<mainVector[i]->totalDomesticGross<<endl;
		cout<<" "<<endl;
	}
	sortByRank();
}
//sortByGross loops through mainVector and sorts it by total domestic gross in descending order using a bubble sort type algorithm
void MovieTree::sortByGross()
{
	bool isSorted = false;
	while(isSorted == false)
	{
		isSorted = true;
		for(unsigned int i = 0; i < mainVector.size() - 1; i++)
		{
			//cout<<mainVector[i]->title<<":"<<mainVector[i]->totalDomesticGross<<endl;
			//cout<<mainVector[i+1]->title<<":"<<mainVector[i+1]->totalDomesticGross<<endl;
			if(mainVector[i]->totalDomesticGross < mainVector[i+1]->totalDomesticGross)
			{
				MovieNode* temp = mainVector[i];
				mainVector[i] = mainVector[i+1];
				mainVector[i+1] = temp;
				isSorted = false;
			}
		}
	}
}
//printByTitle function calls sortByTitle, then loops through mainVector printing out all movie's in alphebetical order
void MovieTree::printByTitle()
{
	sortByTitle();
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		cout<<"Movie: "<<mainVector[i]->title<<endl;
		//cout<<"Total Domestic Gross: "<<"$"<<mainVector[i]->totalDomesticGross<<endl;
		cout<<" "<<endl;
	}
	sortByRank();
}
//sortByTitle function goes through mainVector and sorts it by title in alphebetical order in a bubble sort type algorithm
void MovieTree::sortByTitle()
{
	bool isSorted = false;
	while(isSorted == false)
	{
		isSorted = true;
		for(unsigned int i = 0; i < mainVector.size() - 1; i++)
		{
			if(mainVector[i]->title.compare(mainVector[i+1]->title) > 0)
			{
				MovieNode* temp = mainVector[i];
				mainVector[i] = mainVector[i+1];
				mainVector[i+1] = temp;
				isSorted = false;
			}
		}
	}
}
//printByGrossInflated first calls sortByGrossInflated then loops through mainVector and prints out movie's with highest..
//total domestic gross adjusted for inflation in descending order.
void MovieTree::printByGrossInflated()
{
	sortByGrossInflated();
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		cout<<"Movie: "<<mainVector[i]->title<<endl;
		cout<<"Total Domestic Gross: "<<"$"<<mainVector[i]->totalDomesticGross<<endl;
		cout<<" "<<endl;
	}
	reAdjustGross();
	sortByRank();
}
//sortByGrossInflated calls adjustGross, then sorts mainVector by highes total domestic gross adjust for inflation in descending order.
void MovieTree::sortByGrossInflated()
{
	adjustGross();
	bool isSorted = false;
	while(isSorted == false)
	{
		isSorted = true;
		for(unsigned int i = 0; i < mainVector.size() - 1; i++)
		{
			//cout<<mainVector[i]->title<<":"<<mainVector[i]->totalDomesticGross<<endl;
			//cout<<mainVector[i+1]->title<<":"<<mainVector[i+1]->totalDomesticGross<<endl;
			if(mainVector[i]->totalDomesticGross < mainVector[i+1]->totalDomesticGross)
			{
				MovieNode* temp = mainVector[i];
				mainVector[i] = mainVector[i+1];
				mainVector[i+1] = temp;
				isSorted = false;
			}
		}
	}
}
//adjustGross loops through mainVector and re-assigns each totalDomesticGross value to the number returned by inflationFutureCalculator.
void MovieTree::adjustGross()
{
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		if(mainVector[i]->year == 2014)
		{
			mainVector[i]->totalDomesticGross = mainVector[i]->totalDomesticGross;
		}
		else
		{
			mainVector[i]->totalDomesticGross = inflationFutureCalculator(mainVector[i]);
			//cout<<mainVector[i]->totalDomesticGross<<endl;
		}
	}
}
//InflationFutureCalculator calculates each movies TDG value adjusted for inflation though the years.
//This function works in exactly the same way as inflationPresentCalculator except for otherwise noted in the function definition.
double MovieTree::inflationFutureCalculator(MovieNode* node)
{
	//cout<<"currentMovie:"<<node->title<<endl;
	double movieGross = node->totalDomesticGross;
	double currentYrAvInfl = 233.916;
	double currentYr = 2014;//using 2014 for better CPI average
	double movieYr = node->year;//average consumer price index for current movie
	double movieYrAvInfl = searchCPI(node);//average consumer price index of movie yr.
	//cout<<"MOvieyr av inflation:"<<movieYrAvInfl<<endl;
	double movieAge = currentYr - movieYr;
	//cout<<"MOvieage:"<<movieAge<<endl;
	double avInfl = (currentYrAvInfl/movieYrAvInfl);
	//cout<<"avinlfation:"<<avInfl<<endl;
	double invMovieAge= (1/movieAge);
	//cout<<"inverseMovieAge:"<<invMovieAge<<endl;
	double x = pow(avInfl, invMovieAge) - 1;//average annual inflation per year from movie date till present
	//cout<<"x:"<<x<<endl;
	double y = (1+x);
	double z = pow(y, movieAge);
	//cout<<"z:"<<z<<endl;
	double newMovieGross = movieGross*z;//**MAIN DIFFERENCE. MovieGross is multiplied by z rather than dived by in the inflationPresentCalculator function
	//cout<<"newMOvieGros:"<<newMovieGross<<endl;
	return newMovieGross;
}
//reAdjustGross is called after values for totalDomesticGross values are changed for inflation. The purpose of this function is to..
//re-assign the original movies total domestic gross (not adjusted for inflation) to maintain original movie data.
//this is done by looping through mainVector and re-assigning each domestic gross value by setting it equal to the value returned..
//by inflationPresentCalculator.
void MovieTree::reAdjustGross()
{
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		if(mainVector[i]->year == 2014)
		{
			mainVector[i]->totalDomesticGross = mainVector[i]->totalDomesticGross;
		}
		else
		{
			mainVector[i]->totalDomesticGross = inflationPresentCalculator(mainVector[i]);
			//cout<<mainVector[i]->totalDomesticGross<<endl;
		}
	}
}
//inflationPresentCalculator takes in a data type of pointer type and uses the node to identify needed information for the calculation.
//The formula to calculate Present Value is the opposite of calculating future value, That is to say we are calculating what the TDG for..
//the year in wich the movies was released, not what the TDG of a movie is if it were adjusted for inflation.
//The function calls searchCPI to obtain the needed consumer price index of the movies corresponding year.
//Once the calculation is complete the function returns a value of data type double.
double MovieTree::inflationPresentCalculator(MovieNode* node)
{
	//cout<<"currentMovie:"<<node->title<<endl;
	double movieGross = node->totalDomesticGross;
	double currentYrAvInfl = 233.916;
	double currentYr = 2014;//using 2014 for better CPI average
	double movieYr = node->year;//average consumer price index for current movie
	double movieYrAvInfl = searchCPI(node);//average consumer price index of movie yr.
	//cout<<"MOvieyr av inflation:"<<movieYrAvInfl<<endl;
	double movieAge = currentYr - movieYr;
	//cout<<"MOvieage:"<<movieAge<<endl;
	double avInfl = (currentYrAvInfl/movieYrAvInfl);
	//cout<<"avinlfation:"<<avInfl<<endl;
	double invMovieAge= (1/movieAge);
	//cout<<"inverseMovieAge:"<<invMovieAge<<endl;
	double x = pow(avInfl, invMovieAge) - 1;//average annual inflation per year from movie date till present
	//cout<<"x:"<<x<<endl;
	double y = (1+x);
	double z = pow(y, movieAge);
	//cout<<"z:"<<z<<endl;
	double originalMovieGross = movieGross/z;//DIFFERENCE BETWEEN FUTURE AND PRESENT TDG VALUE CALCULATION (movieGross dived by Z rather than multiplied)
	//cout<<"newMOvieGros:"<<newMovieGross<<endl;
	return originalMovieGross;
}
//searchCPI takes in a data type of type pointer and searches through the cpiVector for the movies corresponding cpi value associated by year..
//Once the value is found the function returns it as a data type of type double.
double MovieTree::searchCPI(MovieNode* node)
{
	double cpiNum;
	for(unsigned int i = 0; i < cpiVector.size(); i++)
	{
		//cout<<cpiVector[i]->year<<endl;
		//cout<<cpiVector[i]->cpi<<endl;

		if(node->year == cpiVector[i]->year)
		{
			cpiNum = cpiVector[i]->cpi;
			return cpiNum;
		}
	}
	return 0;
}
//printByDirector first calls sortByDirector, then loops through mainVector and prints out movie's by director name in alphebetical order.
void MovieTree::printByDirector()
{
	sortByDirector();
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		cout<<mainVector[i]->title;
		cout<<", "<<"Directed By: "<<mainVector[i]->director<<endl;
		cout<<" "<<endl;
	}
	sortByRank();
}
//sortByDirector goes through mainVector and sorts it by director name in alphebetical order.
void MovieTree::sortByDirector()
{
	bool isSorted = false;
	while(isSorted == false)
	{
		isSorted = true;
		for(unsigned int i = 0; i < mainVector.size() - 1; i++)
		{
			//cout<<mainVector[i]->title<<":"<<mainVector[i]->totalDomesticGross<<endl;
			//cout<<mainVector[i+1]->title<<":"<<mainVector[i+1]->totalDomesticGross<<endl;
			if(mainVector[i]->director.compare(mainVector[i+1]->director) > 0)
			{
				MovieNode* temp = mainVector[i];
				mainVector[i] = mainVector[i+1];
				mainVector[i+1] = temp;
				isSorted = false;
			}
		}
	}
}
//printByActor loops through mainVector and prints out each movie by main actors name in alphebetical order
void MovieTree::printByActor()
{
	sortByActor();
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		cout<<mainVector[i]->mainActor;
		cout<<", "<<"Starring In: "<<mainVector[i]->title<<endl;
		cout<<" "<<endl;
	}
	sortByRank();
}
//sortByActor goes through mainVector and sorts it by the main actors name in alphebetical order.
void MovieTree::sortByActor()
{
	bool isSorted = false;
	while(isSorted == false)
	{
		isSorted = true;
		for(unsigned int i = 0; i < mainVector.size() - 1; i++)
		{
			//cout<<mainVector[i]->title<<":"<<mainVector[i]->totalDomesticGross<<endl;
			//cout<<mainVector[i+1]->title<<":"<<mainVector[i+1]->totalDomesticGross<<endl;
			if(mainVector[i]->mainActor.compare(mainVector[i+1]->mainActor) > 0)
			{
				MovieNode* temp = mainVector[i];
				mainVector[i] = mainVector[i+1];
				mainVector[i+1] = temp;
				isSorted = false;
			}
		}
	}
}
//printByGenre loops through mainVector and prints out each movie and it's corresponding genre.
void MovieTree::printByGenre()
{
	for(unsigned int i = 0; i < mainVector.size(); i++)
	{
		cout<<mainVector[i]->title;
		cout<<", "<<"Genre: "<<mainVector[i]->genre<<endl;
		cout<<" "<<endl;
	}
	sortByRank();
}
//movieTrivia function calculated a random number between 1 & 9, then uses that value to print out the corresponding question..
//in qVector at that index. The user is then prompted for a response to the question and compares the respons to qVector's corresponding..
//index answer value.
void MovieTree::movieTrivia()
{
    vector <int> done;
    cout << "Type q to quit" << endl;
    int score = 0;
	int index = rand() % 10;
	done.push_back(index);
	string response;
	cout<<qVector[index]->question<<endl;
	getline(cin, response);
	if(response == "q")
        return;
	if(response == qVector[index]->answer)
	{
	    score ++;
		cout<<"Correct!"<<endl;
	}
	else
	{
		cout<<"Wrong"<<endl;
		cout<<"Answer: "<<qVector[index]->answer<<endl;
	}
	while(index == done[0])
        index = rand() % 10;
    done.push_back(index);
	cout<<qVector[index]->question<<endl;
	getline(cin, response);
	if(response == "q")
        return;
	if(response == qVector[index]->answer)
	{
	    score ++;
		cout<<"Correct!"<<endl;
	}
	else
	{
		cout<<"Wrong"<<endl;
		cout<<"Answer: "<<qVector[index]->answer<<endl;
	}
	while(index == done[0] || index == done[1])
        index = rand() % 10;
	cout<<qVector[index]->question<<endl;
	getline(cin, response);
	if(response == "q")
        return;
	if(response == qVector[index]->answer)
	{
	    score ++;
		cout<<"Correct!"<<endl;
	}
	else
	{
		cout<<"Wrong"<<endl;
		cout<<"Answer: "<<qVector[index]->answer<<endl;
	}
	if(score == 3){
        cout << "Congratulations, you have a perfect score! You have earned .........." << endl;
        cout << "NOTHING!!!!!!!!" << endl;
	} else {
	    cout << "Final Score: " << score << endl;
	}
}
//addCpi function takes in two values of data type double from the file being read in by the main driver.
//A temp pointer is then made and assigned the values of year and cpi, and pushes them into the cpiVector.
void MovieTree::addCpi(double in_yr, double in_cpi)
{
	MovieNode*temp = new MovieNode;
	temp->year = in_yr;
	temp->cpi = in_cpi;
	cpiVector.push_back(temp);
}
//BuildVector function takes in data types of int, double, string, and double, creates a temp pointer of type MovieNode..
//assignes each value to it consisting of ranking, title, releaseYear, director, mainActor genre, and totalGross..
//then pushes the temp node into the mainVector via the buildVector function.
void MovieTree::buildVector(int ranking, string title, double releaseYear, string director, string mainActor, string genre, double totalGross)
{
	MovieNode* node = new MovieNode(ranking, title, releaseYear, director, mainActor, genre, totalGross);//new node being added
	//cout<<tracker->ranking<<endl;
	//cout<<temp->title<<endl;
	//cout<<tracker->year<<endl;
	//cout<<tracker->director<<endl;
	//cout<<tracker->mainActor<<endl;
	//cout<<tracker->genre<<endl;
	//cout<<temp->totalDomesticGross<<endl;
	//buildVector(temp);
	mainVector.push_back(temp); // combined void MovieTree::buildVector(MovieNode *node)
}
//buildVector pushes the temp node from previous buildVector function into the mainVector
/*void MovieTree::buildVector(MovieNode *node)
{
	mainVector.push_back(node);
}*/
//buildQVector takes in two strings from the file being read in by the main Driver, assigns them to a temp MovieNode pointer..
//then pushes temp into the qVector.
void MovieTree::buildQVector(string Q, string A)
{
	MovieNode* temp = new MovieNode;
	temp->question = Q;
	temp->answer = A;
	qVector.push_back(temp);
}



