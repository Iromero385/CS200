// This program demonstrates the overloaded = operator returning a value.
#include <iostream>
#include <string>
using namespace std;

const double DEFAULT_SCORE = 0.0;

class StudentTestScores {
	string studentName;	// The student's name
	double *testScores;	// Points to array of test scores
	int numTestScores;	// Number of test scores

	// Private member function to create an array of test scores.
	void createTestScoresArray(int size) {
		numTestScores = size;
		testScores = new double[size]; 
		for (int i = 0; i < size; i++)
			testScores[i] = DEFAULT_SCORE; }
			
public:
	// Constructor
	StudentTestScores(string name, int numScores) {
		studentName = name;
		createTestScoresArray(numScores); }
		
	// Copy constructor
	StudentTestScores(const StudentTestScores &obj) {
		studentName = obj.studentName;
		numTestScores = obj. numTestScores;
		testScores = new double[numTestScores];
		for (int i = 0; i < numTestScores; i++)
			testScores[i] = obj.testScores[i]; 
	}

	// Destructor
	~StudentTestScores()
	{ delete [] testScores; }

	// Setters
	void setTestScore(double score, int index) { testScores[index] = score; }
	void setStudentName(string name) { studentName = name; }

	// Getters
	string getStudentName() const { return studentName; }
	int getNumTestScores() { return numTestScores; }
	double getTestScore(int index) const { return testScores[index]; }

	// Overloaded = operator
	const StudentTestScores operator=(const StudentTestScores &right) {
		delete [] testScores;
		studentName = right.studentName;
		numTestScores = right.numTestScores;
		testScores = new double[numTestScores];
		for (int i = 0; i < numTestScores; i++)
			testScores[i] = right.testScores[i];
		return *this; }
};

// Function prototype
void displayStudent(StudentTestScores);

int main() {
	// Create a StudentTestScores object.
	StudentTestScores student1("Kelly Thorton", 3);
	student1.setTestScore(100.0, 0);
	student1.setTestScore(95.0, 1);
	student1.setTestScore(80, 2);

	// Create two more StudentTestScores objects.
	StudentTestScores student2("Jimmy Griffin", 5);
	StudentTestScores student3("Kristen Lee", 10);
	
	// Create three backup copies
	StudentTestScores backup1(student1);
	StudentTestScores backup2(student2);
	StudentTestScores backup3(student3);
	
	// Assign student1 to student2 and student3.
	student3 = student2 = student1;	
	
	// Display the objects.
	displayStudent(student1);
	displayStudent(student2);
	displayStudent(student3);

    // Display the objects.
    cout << "\nThe following are archive records:\n";
    displayStudent(backup1);
    displayStudent(backup2);
    displayStudent(backup3);
    return 0;
}

// displayStudent function
void displayStudent(StudentTestScores s) {
	cout << "Name: " << s.getStudentName()
	    << "\nTest Scores: ";
	for (int i = 0; i < s.getNumTestScores(); i++)
		cout << s.getTestScore(i) << " ";
	cout << endl;
}