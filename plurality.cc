#include <iostream>
#include <string>
using namespace std;

// plurality vote, every voter chooses one candidate
// ./plurality Alice Bob Charlie
// Outputs the winner

#define MAX 9

// Number of candidates
int candidate_count;
int adding_to_file; // added via github

// Function Prototypes
bool vote(string name);
void print_winner(void);

int delete_later; // delete now!

typedef struct {
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

int main(int argc, const char * argv[])
{
    // Checks for invalid usage
    if (argc < 2)
    {
        cout << "Usage: plurality [candidate ...]\n";
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX)
    {
        cout << "Maximum number of candidates is " << MAX << endl;
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    
    for(int i = 1; i < argc; ++i){
        cout << argv[i] << ", ";
    }
    cout << endl;

    int voter_count;
    cout << "Number of voters: ";
    cin >> voter_count;


    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name;
        cout << "Vote: ";
        cin >> name;

        // Check for invalid vote
        if (!vote(name))
        {
            cout << "Invalid Vote" << endl;
            --i;
        }
    }

    print_winner();

    return 0;
}

bool vote(string name){
    // look for candidate name
    bool found = false;

    for(int i = 0; i < candidate_count; i++){
        if(candidates[i].name == name)
            found = true;
        if(found){
            candidates[i].votes += 1;
            cout << candidates[i].votes;
        }
    }
    return found;
}

void print_winner(void){
    int highest_vote;
    string winner [candidate_count];

    for(int i = 0; i < candidate_count; i++){
        for(int j = 1; j < candidate_count; j++){
            if(candidates[i].votes > candidates[j].votes)
                highest_vote = candidates[i].votes;
        }
    }
    cout << highest_vote << endl;
    cout<< "Winner:" << endl;
    for(int i = 0; i < candidate_count; i++){
        if(highest_vote == candidates[i].votes){
            cout << candidates[i].name << endl;
        }
    }
}
