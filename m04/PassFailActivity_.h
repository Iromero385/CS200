#ifndef PASSFAILACTIVITY__H
#define PASSFAILACTIVITY__H

class GradedActivity {
protected:
	double score;	// To hold the numeric score
public:
	GradedActivity() { score = 0.0; }
	GradedActivity(double s) { score = s; }
	void setScore(double s) { score = s; }
	double getScore() const { return score; }
	virtual char getLetterGrade() const;
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
//////////////////////////////////////////
// 	virtual char getLetterGrade() const;
};


class PassFailExam : public PassFailActivity {
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
	void set(int, int);  // Defined in PassFailExam.cpp
	double getNumQuestions() const { return numQuestions; }
	double getPointsEach() const { return pointsEach; }
	int getNumMissed() const { return numMissed; }
};

void PassFailExam::set(int questions, int missed) { 
	double numericScore;  // To hold the numeric score
	numQuestions = questions;
	numMissed = missed;
	pointsEach = 100.0 / numQuestions;
	numericScore = 100.0 - (missed * pointsEach);
	setScore(numericScore);
} 

#endif