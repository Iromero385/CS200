#ifndef PASSFAILEXAM_H
#define PASSFAILEXAM_H
#include "PassFailActivity.h"

class PassFailExam : public PassFailActivity
{
private:
   int numQuestions;    // Number of questions
   double pointsEach;   // Points for each question
   int numMissed;       // Number of questions missed
public:
   PassFailExam() : PassFailActivity()
      { numQuestions = 0; pointsEach = 0.0; numMissed = 0; }
   PassFailExam(int questions, int missed, double mps) :
      PassFailActivity(mps) { set(questions, missed); }

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
   
   // Call the inherited setScore function to set the numeric score.
   setScore(numericScore);
} 
#endif 