// A base class and a derived class.
#include <iostream>
#include <iomanip>

using namespace std;

class GradedActivity {
	double score;	// To hold the numeric score
public:
	GradedActivity() { score = 0.0; }
	GradedActivity(double s) { score = s; }
	void setScore(double s) { score = s; } 
	double getScore() const { return score; }
	char getLetterGrade() const;
};

char GradedActivity::getLetterGrade() const {
	char letterGrade; // To hold the letter grade
	
	if (score > 89) letterGrade = 'A';
	else if (score > 79) letterGrade = 'B';
	else if (score > 69) letterGrade = 'C';
	else if (score > 59) letterGrade = 'D';
	else letterGrade = 'F';
	
	return letterGrade;
}

/////////////////////////////////////////////////////
class FinalExam : public GradedActivity {
	int numQuestions; // Number of questions
	double pointsEach; // Points for each question
	int numMissed; // Number of questions missed
public:
	FinalExam() { numQuestions = 0;
					pointsEach = 0.0;
					numMissed = 0; }

	FinalExam(int questions, int missed) { set(questions, missed); }
	void set(int, int); // Defined in FinalExam.cpp
	double getNumQuestions() const { return numQuestions; }
	double getPointsEach() const { return pointsEach; } 
};

void FinalExam::set(int questions, int missed) { 
	double numericScore; // To hold the numeric score

	// Set the number of questions and number missed.
	numQuestions = questions;
	numMissed = missed;

	// Calculate the points for each question.
	pointsEach = 100.0 / numQuestions;
	numericScore = 100.0 - (missed * pointsEach);
	setScore(numericScore);
} 

int main() {
/////////////////////////////////////////////	
// Pr15-1 verifies Graded Activity Only
	double testScore;  
	GradedActivity test;

	cout << "Enter your numeric test score: ";
	cin >> testScore;

	test.setScore(testScore);
	cout << "The grade for that test is "
		 << test.getLetterGrade() << endl;
///////////////////////////////////////////////
	
	int questions; 
	int missed; 

	cout << "How many questions are on the final exam? ";
	cin >> questions;

	cout << "How many questions did the student miss? ";
	cin >> missed;

	FinalExam exam(questions, missed);

	cout << setprecision(2)
		  << "\nEach question counts " << exam.getPointsEach() << " points."
		  << "\nThe exam score is " << exam.getScore() 
		  << "\nThe exam grade is " << exam.getLetterGrade() << endl;
}