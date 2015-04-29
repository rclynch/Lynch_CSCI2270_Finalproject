//Ryan C. Lynch
//csci2270
//header file
//Final Project

//method definitions are breifly explaned in their definitions in MovieTree.cpp

#ifndef MOVIETREE_H
#define MOVIETREE_H
#include <vector>

struct MovieNode
{
	double cpi;
	double year;
	double totalDomesticGross;
    int ranking;
    std::string title;
    std::string question;
    std::string answer;
    std::string director;
    std::string mainActor;
    std::string genre;

    MovieNode()//defualt constructor
    {
	};
    MovieNode(int in_ranking, std::string in_title, int in_year, std::string in_director, std::string in_actor,std::string in_genre,int in_gross)//constructor
    {
        ranking = in_ranking;
        title = in_title;
        year = in_year;
        director = in_director;
        mainActor = in_actor;
        genre = in_genre;
        totalDomesticGross = in_gross;
    }
};
class MovieTree
{
    public:
        MovieTree();
        virtual ~MovieTree();
        
        void printTopMovies();
        void printHighestGrossing();
        void printAllMovieInfo();
        void printByTitle();
        void printByGrossInflated();
        void printByDirector();
        void printByActor();
        void printByGenre();
        void movieTrivia();
        
        double searchCPI(MovieNode* node);
        void addCpi(double in_yr, double in_cpi);
        void buildQVector(std::string Q, std::string A);
        void buildVector(int ranking, std::string title, double releaseYear, std::string director, std::string mainActor, std::string genre, double totalGross);
    protected:
    private:
		void sortByGenre();
        void sortByRank();
        void sortByTitle();
		void sortByGross();
        void sortByGrossInflated();
		void sortByDirector();
		void sortByActor();
		void adjustGross();
        void reAdjustGross();
		double inflationFutureCalculator(MovieNode* node);
		double inflationPresentCalculator(MovieNode* node);
        void buildVector(MovieNode*node);
        std::vector<MovieNode*> cpiVector;
        std::vector<MovieNode*> mainVector;
        std::vector<MovieNode*> qVector;
};
#endif // MOVIETREE_H
