#include <iostream>
#include <iomanip>

class GradedActivity {
protected:
    double score; // To hold the numeric score
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

class FinalExam : public GradedActivity {
private:
    int numQuestions; // Number of questions
    double pointsEach; // Points for each question
    int numMissed; // Number of questions missed
public:
    FinalExam()
        { numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0; }
    FinalExam(int questions, int missed) { 
        set(questions, missed); }
        
    // Accessor functions
    double getNumQuestions() const { return numQuestions; }
    double getPointsEach() const { return pointsEach; }
    int getNumMissed() const { return numMissed; }
    void set(int, int); 
    void adjustScore(); 
};


void FinalExam::set(int questions, int missed) {
    double numericScore; 

    numQuestions = questions;
    numMissed = missed;

    pointsEach = 100.0 / numQuestions;
    numericScore = 100.0 - (missed * pointsEach);

    setScore(numericScore);
    adjustScore();
} 

void FinalExam::adjustScore() {
    double fraction = score - static_cast<int>(score);
    
    // Adjust the score variable in the GradedActivity class.
    if (fraction >= 0.5) score += (1.0 - fraction);
} 


using namespace std;

int main() {
    int questions; // Number of questions on the exam
    int missed; // Number of questions missed by the student
    
    // Get the number of questions on the final exam.
    cout << "How many questions are on the final exam? ";
    cin >> questions;
    
    // Get the number of questions the student missed.
    cout << "How many questions did the student miss? ";
    cin >> missed;
    
    // Define a FinalExam object and initialize it with
    // the values entered.
    FinalExam test(questions, missed);
    
    // Display the adjusted test results.
    cout << setprecision(2) << fixed
         << "\nEach question counts "
         << test.getPointsEach() << " points."
         << "\nThe adjusted exam score is "
         << test.getScore()
         << "\nThe exam grade is "
         << test.getLetterGrade() << endl;
} 