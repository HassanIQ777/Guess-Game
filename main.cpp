#include <ctime>
#include <iostream>

using namespace std;

int totalTries = 0;
int gamesPlayed = 0;

void game() {
  int n, guess;
  int tries = 0;
  srand(static_cast<unsigned int>(time(NULL)));
  cout << "Range: ";
  cin >> n;
  if (n > 0) {
    int randNum = rand() % n + 1;
    cout << "***************** Guessing Game ****************\n";
    do {
      cout << "Guess: ";
      cin >> guess;
      if (guess == randNum) {
        cout << "\nCongrats you won!";
      } else if (guess > randNum) {
        cout << guess << " is too Large!\n";
      } else if (guess < randNum) {
        cout << guess << " is too Small!\n";
      }
      cout << "\n";
      tries += 1;
      totalTries += 1;
    } while (guess != randNum);
    gamesPlayed += 1;
    if (tries == 1) {
      cout << "\nAmazing! You won in " << tries << " try.\n";
    } else {
      cout << "You won in " << tries << " tries.\n";
    }
    cout << "**********************************************\n";
  } else {
    cout << "Error: Invalid range, please try again.\n";
  }
}

int main() {
  string repeat = "y";
  do {
    game();
    cout << "Play again? [y/n]\n> ";
    cin >> repeat;
  } while (repeat == "y" || repeat == "Y");
  if (gamesPlayed > 0) {
    double averageTries = static_cast<double>(totalTries) / gamesPlayed;
    cout << "\n[Stats]: Total games played: " << gamesPlayed << endl;
    cout << "[Stats]: Total number of tries: " << totalTries << endl;
    cout << "[Stats]: Average tries per game: " << averageTries << endl;
  } else {
    cout << "[Stats]: No games played.\n";
  }
  cout << "\nThanks for playing!\n";
}