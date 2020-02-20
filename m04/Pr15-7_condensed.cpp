// This program demonstrates a class that redefines
// a base class function.
#include <iostream>
#include <iomanip>

using namespace std;

class GradedActivity {
protected:
	char letter;			// To hold the letter grade
	double score;			 // To hold the numeric score
	void determineGrade();  // Determines the letter grade
public:
	GradedActivity() { letter = ' '; score = 0.0; }
	void setScore(double s) { score = s; determineGrade();}
	double getScore() const { return score; }
	char getLetterGrade() const ;
};

void GradedActivity::determineGrade() {
	if (score > 89) letter = 'A';
	else if (score > 79) letter = 'B';
	else if (score > 69) letter = 'C';
	else if (score > 59) letter = 'D';
	else letter = 'F';
}

char GradedActivity::getLetterGrade() const {
	char letterGrade; // To hold the letter grade
	
	if (score > 89) letterGrade = 'A';
	else if (score > 79) letterGrade = 'B';
	else if (score > 69) letterGrade = 'C';
	else if (score > 59) letterGrade = 'D';
	else letterGrade = 'F';
	
	return letterGrade;
}

class CurvedActivity : public GradedActivity {
protected:
	double rawScore; // Unadjusted score
	double percentage; // Curve percentage
public:
	// Default constructor
	CurvedActivity() : GradedActivity()
		{ rawScore = 0.0; percentage = 0.0; }

	// Mutator functions
	void setScore(double s) { rawScore = s;
		 GradedActivity::setScore(rawScore * percentage); }
	void setPercentage(double c) { percentage = c; }
	double getPercentage() const { return percentage; }
	double getRawScore() const { return rawScore; }
};


int main() {
	double numericScore; // To hold the numeric score
	double percentage; // To hold curve percentage
	
	// Get the unadjusted score.
	cout << "Enter the student's raw numeric score: ";
	cin >> numericScore;
	
	// Get the curve percentage.
	cout << "Enter the curve percentage for this student: ";
	cin >> percentage;
	
	CurvedActivity exam;
	exam.setPercentage(percentage);
	exam.setScore(numericScore);
	
	// Display the grade data.
	cout << fixed << setprecision(2)
			<< "The raw score is "
			<< exam.getRawScore() 
			<< "\nThe curved score is "
			<< exam.getScore() 
			<< "\nThe curved grade is "
			<< exam.getLetterGrade() << endl;
} 