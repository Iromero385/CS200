#include <iostream>
#include <iomanip>
#include "PassFailExam.h"

using namespace std;

void displayGrade(const GradedActivity &activity) {
	cout << setprecision(1) << fixed
		 << "The activity's numeric score is "
		 << activity.getScore()
	     << "\nThe activity's letter grade is "
		 << activity.getLetterGrade() << endl;
} 

void displayGrade_2(const GradedActivity *activity) {
	cout << setprecision(1) << fixed
		 << "The activity's numeric score is "
		 << activity->getScore()
	     << "\nThe activity's letter grade is "
		 << activity->getLetterGrade() << endl;
}

int main() {
	// 15_11
	cout << "------PR15_11------\n";
	PassFailActivity test(70);
	test.setScore(72);
	displayGrade(test);
	
	//15_12
	cout << "\n------PR15_12------\n";
	GradedActivity test1(88.0);
	// Create a PassFailExam object. There are 100 questions,
	// the student missed 25 of them, and the minimum passing
	// score is 70.
	PassFailExam test2(100, 25, 70.0);

	cout << "Test 1:\n";
	displayGrade(test1);	 // GradedActivity object
	cout << "\nTest 2:\n";
	displayGrade(test2);	 // PassFailExam object
	
	//15_13
	cout << "\n------PR15_13------\n";
	GradedActivity test3(88.0);
	PassFailExam test4(100, 25, 70.0);
	
	cout << "Test 3:\n";
	displayGrade_2(&test3);  // Address of the GradedActivity object
	cout << "\nTest 4:\n";
	displayGrade_2(&test4);  // Address of the PassFailExam object
	
	//15_14
	cout << "\n------PR15_14------\n";
	const int NUM_TESTS = 4;
	GradedActivity *tests[NUM_TESTS] = {
		new GradedActivity(88.0),
		new PassFailExam(100, 25, 70.0),
		new GradedActivity(67.0),
		new PassFailExam(50, 12, 60.0)
	};

	for (int count = 0; count < NUM_TESTS; count++) {
		cout << "Test #" << (count + 1) << ":\n";
		displayGrade_2(tests[count]);
		cout << endl;
	}
}
