#include <iostream>
#include <iomanip>
using namespace std;

class GradedActivity {
protected:
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

class PassFailActivity : public GradedActivity {
protected:
	double minPassingScore;	 // Minimum passing score.
public:
	PassFailActivity() : GradedActivity() 
	    { minPassingScore = 0.0; }
	PassFailActivity(double mps) : GradedActivity()
		{ minPassingScore = mps; }
	void setMinPassingScore(double mps)
		{ minPassingScore = mps; }
	double getMinPassingScore() const
		{ return minPassingScore; }
	char getLetterGrade() const;
};

char PassFailActivity::getLetterGrade() const {
	char letterGrade;
	if (score >= minPassingScore) letterGrade = 'P';
	else letterGrade = 'F';
		
	return letterGrade;
} 

class PassFailExam : public PassFailActivity {
private:
	int numQuestions;	 // Number of questions
	double pointsEach;	// Points for each question
	int numMissed;		 // Number of questions missed
public:
	PassFailExam() : PassFailActivity()
		{ numQuestions = 0;
		  pointsEach = 0.0;
		  numMissed = 0; }
	PassFailExam(int questions, int missed, double mps) :
		PassFailActivity(mps)
		{ set(questions, missed); }
	void set(int, int);  // Definition outside
	double getNumQuestions() const
		{ return numQuestions; }
	double getPointsEach() const
		{ return pointsEach; }
	int getNumMissed() const
		{ return numMissed; }
};

void PassFailExam::set(int questions, int missed) { 
	double numericScore;  // To hold the numeric score
	numQuestions = questions;
	numMissed = missed;
	pointsEach = 100.0 / numQuestions;
	numericScore = 100.0 - (missed * pointsEach);
	
	// Call the inherited setScore function to set
	// the numeric score.
	setScore(numericScore);
}

int main() {
	int questions;		  // Number of questions
	int missed;			  // Number of questions missed
	double minPassing;	 // The minimum passing score

	cout << "How many questions are on the exam? ";
	cin >> questions;

	cout << "How many questions did the student miss? ";
	cin >> missed;

	cout << "Enter the minimum passing score for this test: ";
	cin >> minPassing;

	PassFailExam exam(questions, missed, minPassing);

	cout << fixed << setprecision(1)
	     << "\nEach question counts " 
		 << exam.getPointsEach() << " points."
	     << "\nThe minimum passing score is "
		 << exam.getMinPassingScore() 
    	 << "\nThe student's exam score is " 
		 << exam.getScore() 
	     << "\nThe student's grade is " 
		 << exam.getLetterGrade() << endl;
	return 0;
}