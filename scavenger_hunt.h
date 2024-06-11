//Thierry Ndayisaba
//june 11th
//  scavengerhunt game where we where we create multiple question and clues 

#include <cstring>

struct Clue
{
    char *text;         
    char answer[100];       
    int difficulty;
    char hint[100]; 
    
    Clue() : text(nullptr) {}
    ~Clue()
    {
	if (text) 
	{   delete[] text;

	}
     }
	
};


struct Node
{
    Clue data;
    Node *next;

    Node() : next(nullptr) {}
};

class ScavengerHunt
{
public:
	ScavengerHunt ();
	~ScavengerHunt ();
	void addClue(const char *text, const char *answer, int difficulty, const char *hint);
	void displayClues() const;
	void traverseAndPlay();
	void clear();

private:
	Node *head;

	void InsertSorted(Node *newNode);
};
