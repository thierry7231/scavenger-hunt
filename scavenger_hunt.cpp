//Thierry Ndayisaba
//june 11th
//  scavengerhunt game where we where we create multiple question and clues 



#include "scavenger_hunt.h"
#include <iostream>

ScavengerHunt::ScavengerHunt() : head(nullptr) {}

ScavengerHunt::~ScavengerHunt() 
{
    clear();
}

void ScavengerHunt::addClue(const char *text, const char *answer, int difficulty, const char *hint) 
{
    Node *newNode = new Node();
    newNode->data.text = new char[strlen(text) + 1];
    strcpy(newNode->data.text, text);
    strcpy(newNode->data.answer, answer);
    newNode->data.difficulty = difficulty;
    strcpy(newNode->data.hint, hint);

    insertSorted(newNode);
}

void ScavengerHunt::insertSorted(Node *newNode) 
{
    if (!head || head->data.difficulty >= newNode->data.difficulty) 
    {
        newNode->next = head;
        head = newNode;
    } else {
        Node *current = head;
        while (current->next && current->next->data.difficulty < newNode->data.difficulty) 
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void ScavengerHunt::displayClues() const 
{
    Node *current = head;
    while (current) 
    {
        cout << "Clue: " << current->data.text << "\n";
        cout << "Answer: " << current->data.answer << "\n";
        cout << "Difficulty: " << current->data.difficulty << "\n";
        cout << "Hint: " << current->data.hint << "\n\n";
        current = current->next;
    }
}

void ScavengerHunt::traverseAndPlay() 
{
    Node *current = head;
    char userAnswer[100];
    while (current) 
    {
        cout << "Clue: " << current->data.text << "\n";
        cout << "Hint: " << current->data.hint << "\n";
        cout << "Your answer: ";
        cin.getline(userAnswer, 100);
        if (strcmp(userAnswer, current->data.answer) == 0) 
        {
            cout << "Correct!\n\n";
        } else 
        {
            cout << "Incorrect! The correct answer is: " << current->data.answer << "\n\n";
        }
        current = current->next;
    }
}

void ScavengerHunt::clear() 
{
    Node *current = head;
    while (current) 
    {
        Node *toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
}

