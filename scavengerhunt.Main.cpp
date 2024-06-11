//Thierry Ndayisaba
//june 11th
//  scavengerhunt game where we where we create multiple question and clues 

#include "scavenger_hunt.h"
#include <iostream>
using namespace std;

void addClues(ScavengerHunt &game) 
{
    game.addClue("I can be red, blue, and green. No one can reach me. What am I?", "A rainbow", 3, "Think of something colorful in the sky.");
    game.addClue("I speak without a mouth and hear without ears. I have no body, but I come alive with the wind.", "An echo", 2, "It's something that repeats what you say.");
    game.addClue("I am not alive, but I can grow. I don't have lungs, but I need air. What am I?", "Fire", 1, "It can be dangerous and you might cook with it.");
}

int main() 
{
    ScavengerHunt game;

    cout << "Scavenger Hunt Game Creation Mode:\n";
    addClues(game);

    cout << "\nDisplaying all clues:\n";
    game.displayClues();

    cout << "\nScavenger Hunt Game Play Mode:\n";
    game.traverseAndPlay();

    return 0;
}
