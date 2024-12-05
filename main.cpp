#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "autocompleter.h"

int main() {
    vector<string> values = {"adoption", "advocate", "albatross", "alpaca", "aloof", "amputate", "ardvark", "armadillo", "avenue", "bathroom", "bullet", "camel", "car", "cat", "coalition", "code", "convince", "creation", "crow", "crocodile", "despise", "draft", "encourage", "executrix", "far", "fence", "fuss", "giraffe", "goat", "goatfish", "goats", "gorilla", "hunting", "illusion", "intermediate", "kneel", "magnitude", "marble", "motivation", "mushroom", "pan", "period", "penalty", "print", "professor", "progressive", "read", "restaurant", "score", "sin", "skate", "slot", "spit", "substitute", "superior", "theorist", "toast", "total", "torture", "treaty", "transport", "twitch"};
    
    Autocompleter autocompleter;
    autocompleter.insert(values);

    // Printing size and height of the tree
    cout << "Size of the tree: " << autocompleter.size() << endl;
    cout << "Height of the tree: " << autocompleter.height() << endl;

    // Printing completions for prefix "a"
    cout << "Completions for prefix 'a': ";
    autocompleter.completions("a");
    cout << endl;

    // Displaying the whole tree in order
    autocompleter.displayInOrder();
    cout << endl;

    // Prompting the user to input a prefix and printing completions
    string prefix;
    cout << "Enter a prefix to get completions: ";
    cin >> prefix;
    cout << "Completions that start with prefix '" << prefix << "': ";
    autocompleter.completionsStart(prefix);
    cout << endl;
    
    cout << "Completions of a prefix '" << prefix << "': ";
    autocompleter.completions(prefix);
    cout << endl;

    return 0;
}