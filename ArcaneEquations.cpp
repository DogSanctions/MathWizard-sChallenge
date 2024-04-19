#include <iostream> // For input/output operations
#include <cstdlib> // For using rand() and srand()
#include <ctime> // For accessing system time for randomization
#include <limits> // For accessing numeric_limits
#include <cctype> // For accessing toupper, tolower, etc.
#include <iomanip> // For setprecision

// Functions declarations
bool welcomeMessage();
bool introCheck();
void gameIntro();
bool readyCheck();
int randNum(int min, int max);
char randOps();
double computeAnswer(int num1, int num2, char operation);
void displayEquation(int num1, int num2, char operation);
bool getUserSolution(int correctAnswer);
void playGame();


int main() {
	using namespace std;
	
	srand(time(0)); // Intializes random seed
	
	cout << fixed << setprecision(2); // Set output to fixed-point notation within two decimal places
	
	if (welcomeMessage()) { // Asks if they want to enter labyrinth
		if (introCheck()) { // If they do, asks if they want to go through tutorial
			gameIntro(); // Starts tutorial
		}
		if (readyCheck()) { // Asks if they are ready to play
			playGame(); // If ready, starts game
		}
	} else {
		cout << "Okay, maybe next time!\n"; // User didn't want to enter labyrinth, exit game
	}
	return 0; // Ends program
}

bool welcomeMessage() {
	using namespace std;
	char enterResponse;
	// Display the welcome message & instructions.
	     cout << "Hello! Welcome to Arcane Equations: The Math Wizard's Challenge.\n"
		  << "Would you like to enter the labyrinth and take on the math wizard's challenge? (Y/N): ";
	while (true) {
		// Get user response
		cin >> enterResponse;
		enterResponse = toupper(enterResponse); // Convert to upper to standardize check

		// Validate Input
		if (enterResponse == 'Y' || enterResponse == 'N') {
			return enterResponse == 'Y';
		} else {
			cout << "Invalid input. Please enter 'Y' for yes or 'N' for no: ";
			cin.clear(); // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Dump invalid input
		}
	}
}

bool introCheck() {
	using namespace std;
	char introResponse;
	cout << "Do you want to go through the tutorial? (Y/N): ";
	
	while (true) {
		// Get user response
		cin >> introResponse;
		introResponse = toupper(introResponse); // Conver to upper to standardize checks
		// Validate Input
		if (introResponse == 'Y' || introResponse == 'N') {
			return introResponse == 'Y';
		} else {
			cout << "Invalid input. Please enter 'Y' for yes or 'N' for no: ";
			cin.clear(); // Clear error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Dump invalid input
		}
	}
}

void gameIntro() {
	using std::cout;
	     // Introduce game,setting,villians to user
	     cout << "As you enter the doors of the math wizard's challenge, you head a voice reverberate throughout your mind.\n"
		  << "The owner of the voice Lord Numerix loudly booms 'HOW DARE YOU!' causing you to feel as if a sledgehammer had smashed into your soul.\n"
		  << "As the pain washes over you, you experience a headsplitting pain while your vision starts to collapse.\n"
		  << "The soft jingle of bells rings out as the pain quickly subsides, and a healing warmth fills your body.\n"
		  << "A faint voice whispers out by your ear beforeyour mind goes into shock, ultimately kocking you unconscious.\n"
		  << "Fairy: Oh no! It seems your paltry skills in the arcane arts has angered Lord Numerix: The Mathemancer!\n"
		  << "As you sleep a series of messages seep into your dreams.\n\n"
		  << "Math Wizard: You weren't strong enough to take on my challenge or face Lord Numerix.\n"
		  << "I've sent you through a deminsional portal to a faraway land called 'The Enchanted Isles of Arithmetics: Numeralia'.\n"
		  << "This is my personal pocket deminsion that was given to me by my master, and set me on my journey to doning the mantle of 'Math Wizard'.\n"
		  << "I am giving you this pocket deminsion for being the first to take on my challenge."
		  << "You've angered Lord Numerix for being what he deems as unworthy and acquriing this legacy before he could.\n"
		  << "This deminsion will help you on your journey to becoming a Math Wizard, and defeating Lord Numerix!\n\n";
	     // Rule Explanation
	     cout << "You clutch your head as you groggily awake from your slumber.\n"
		  << "As you rub your eyes and look around you notice to your amazement a tiny blue fairy.\n"
		  << "You lean forward to inspect it further when it suddenly chirps out.\n\n"
		  << "Fairy: Here on the Enchanted Isles you will hone your abilities in the elementary arcane arts of addition, subtraction, multiplication, & division!\n"
		  << "There are two ways for you to leave the isles.\n"
		  << "The first way to leave is to practice the arcane arts until you feel like you've mastered them.\n"
		  << "The second way is to run out of life saving pixies and fall to the might of the Arcane Equations.\n\n";
	     // Lives
	     cout << "Fairy: There are 4 kinds of Arcane Equations you could possibly run into while exploring Numeralia.\n"
		  << "The first can be frequently found near the Summit of Sums(Addition).\n"
		  << "The second like to frequent the Delta Dunes(Subtraction).\n"
		  << "The third most commonly found Arcane Equations likes to laze around the Multiplicand Mountains(Multiplication).\n"
		  << "Lastly the most rare of the Arcane Equation can be found near the Divisive Deltas(Division).\n"
		  << "While you travel the isles you will randomly run into different arcane equations.\n"
		  << "For each arcane equation you will have 3 chanes to come up with the correct solution.\n"
		  << "If you cannot get the correct solution after 3 tries you will have to spend a 'life-saving pixie' to escape.\n"
		  << "The life-saving pixies can only help you escape the wrath of the Arcane Equations, 5 times.\n"
		  << "Once you run out of pixies you will be considered to have 'fallen' to the might of the Arcane Equations and expelled from this deminsion.\n\n";
	     // Sample problems w/ Solutions
	     cout << "Sample problem with incorrect solution\n" 
		  << "Bad Example: 1) 2+4=?\n"
		  << "Incorrect Solution: 2+4=6\n"
		  << "Correct Solution: 6\n";   
}

bool readyCheck() {
	using namespace std;
	int readyResponse;
	bool contLoop = true; // Flag to control loop
	// 'Menu' selection, loops until user selects 1,2,or 3
	while (contLoop) {
		cout << "Select an option:\n"
			  << "1. Begin the game\n"
			  << "2. Repeat the introduction\n"
			  << "3. Exit the game\n"
			  << "Enter your choice (1, 2, or 3): ";
		cin >> readyResponse;

		// Input validation
		if (cin.fail() || readyResponse < 1 || readyResponse > 3) {
		    cout << "Invalid input. Please enter 1, 2, or 3.\n";
		    cin.clear(); // Clear error flag
		    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards bad input
		    continue; // Skips the rest of the loop and prompts user again
		}
		switch (readyResponse) {
			case 1: // Begins the game
			  return true; // Return true, start game
			case 2: // Repeats introduction
			  gameIntro();
			  continue;
			case 3: // Exit the program
			  cout << "Exiting the program. Goodbye!\n";
			  contLoop = false; // Set flag to false to exit loop
			  continue;
			default:
			  cout << "Invalid input. Please enter 1, 2, or 3.\n";
			  continue;
			  
		}
	
	}
	
	return false; // Return false if user chooses to exit
}

int randNum(int min, int max) {
	// Generates random number between min and max
	// Min and Max is hardcoded in the playGame function
	// So this can be used to randomly decide ops
	return min + rand() % (max-min + 1);
}

char randOps() {
	// Generates random # to decide operation
	int randomOp = randNum(1, 4);
	// Switch case to decide op from randomly generated #
	switch (randomOp) {
		case 1: return '+';
		case 2: return '-';
		case 3: return '*';
		case 4: return '/';
		default: return '+';
	}
}

double computeAnswer(int num1, int num2, char operation){
	using namespace std;
	// Calculate the correct answer based on the operation
	switch (operation) {
		case '+': return num1 + num2;
		case '-': return num1 - num2;
		case '*': return num1 * num2;
		case '/': 
			if (num2 == 0) {
				cerr << "Error: Division by zero." << endl;
				return 0;
			}
			return num1 / static_cast<double>(num2); // Explicit type conersion to double
		default: return 0;
	}
}

void displayEquation(int num1, int num2, char operation) {
	using std::cout;
	// Display math problem to the user
	cout << "\n\nSolve: " << num1 << " " << operation << " " << num2 << " = ?\n";
}

bool getUserSolution(double correctAnswer, char operation) {
	using namespace std;
	double userSolution;
	bool validSolution = false;

	cout.precision(2); // For user input display
	cout << fixed; // Fixed point notation

	// Prompt the user for their answer
	cout << "\nYour solution: ";
	cin >> userSolution;
	
	// Ignores any extra input
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// Input validation
	if (cin.fail()) {
		cin.clear(); // Clear error state
		// Print Error Message
		cout << "\nInvalid input. Please enter a valid number: ";
		return false;
	} else {
		// Validates answer if input was successful
		// 0.005 allows for a small margin of error for division
		if (operation == '/' && abs(userSolution - correctAnswer) < 0.005) {
			validSolution = true;
		} else if (operation != '/' && static_cast<int>(userSolution) == static_cast<int>(correctAnswer)) {
			validSolution = true; // For +,*,- checks for exact match as integers
		} else {
			return false; // Incorrect answer breaks loop and continues to playGame function
		}
	}
	return validSolution; // Returns the result of the input validation
}

void playGame() {
	using namespace std;
	int num1, num2;
	double correctAnswer;
	char operation;
	int lives = 5; // # of 'life-saving pixies'
	bool contPlaying = true; // Flag to control main loop

	// Loop continues as long as live are available
	// and the player wants to continue
	while (lives > 0 && contPlaying) {
		num1 = randNum(0, 20); // Generates first rand #
		num2 = randNum(0, 20); // Generates second rand #
		operation = randOps(); // Determines op for problem
		correctAnswer = computeAnswer(num1, num2, operation); // Computes correct answer
		displayEquation(num1, num2, operation); // Displays problem to user
		
		int tries = 3; // Each problem allows 3 attempts
		bool solvedEquation = false; // Flag to track if user solved problem

		while (tries > 0 && !solvedEquation) {
			bool validInput = getUserSolution(correctAnswer, operation); // Check for valid input and if answer is correct
			if (validInput) {
				cout << "\nCorrect! Well done. \n";
				solvedEquation = true; // Sets flag to true if correct answer given
			} else if (!cin.fail()) { // Checks if wrong answer was valid input
				tries--; // Decrement tries on wrong answer
				if (tries > 0) {
					cout << "\nIncorrect.Please try again. " << tries << " tries left.\n";
				}
			}
		}
		if (!solvedEquation) {
			lives--; // Decrement life if the problem was not solved correctly
			cout<< "\n\nNo tries left! The correct answer was " << correctAnswer 
			<< ". Oh no! You've lost a pixie! " << lives << " pixies remaining.\n";
		}
	
		if (lives > 0) { // Check if user wants to continue if they still have lives
			int contResponse;
			bool validResponse = false; // Control flag for loop

			while (!validResponse) { // Loops until valid input received
				cout << "\nDo you want to continue playing? (1 for Yes, 2 for No): ";
				cin >> contResponse;

				if (cin.fail() || contResponse < 1 || contResponse > 2) {
					// If input is not an integer or is less than 1 or greater than two it is considered a fail
					cin.clear(); // Clear error state
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
					cout << "Invalid input. Please enter 1 or 2.\n";
				} else if (contResponse == 1) {
					contPlaying = true;
					validResponse = true; // Input is valid, breaks loop
				} else {
			    		contPlaying = false;
					validResponse = true; 
				}
			}
		}
	
	}
		if (lives == 0) {
			cout << "\n\nYou used all your life-saving pixies and have fallen to the might of the Arcane Equations.";
		} else {
			cout << "\n\nYou feel as if you've mastered the basics of the Arcane Arts and decide to leave the Enchanted Isles.";
		}
}
