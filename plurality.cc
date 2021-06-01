#include <iostream>
#include <string>
using namespace std;

// plurality vote, every voter chooses one candidate
// ./plurality < name1, name2, name3 ... >
// Outputs the winner

// Max number of candidates
#define MAX 9

// Candidates name and vote count
typedef struct {
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function Prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, const char * argv[])
{
    // Checks for invalid usage
    if (argc < 2)
    {
        cout << "Usage: plurality [candidate ...]\n";
        return 1;
    }

    // Populating array of candidates
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
        }
    }

    // Display the winner of the election
    print_winner();

    return 0;
}

bool vote(string name){
    // look for candidate name
    bool found = false;

    for(int i = 0; i < candidate_count; i++){
        if(candidates[i].name == name)
        {
            cout << "inside vote loop" << endl;
            found = true;
            candidates[i].votes = candidates[i].votes + 1;
            return found;
        }
    }
    return found;
}

void print_winner(void){
    int highest_vote = 0;

    for(int i = 0; i < candidate_count; i++){
        if(highest_vote < candidates[i].votes)
            highest_vote = candidates[i].votes;
    }
    cout << highest_vote << endl;
    cout<< "Winner:" << endl;
    for(int i = 0; i < candidate_count; i++){
        if(highest_vote == candidates[i].votes)
            cout << candidates[i].name << endl;
    }
}
