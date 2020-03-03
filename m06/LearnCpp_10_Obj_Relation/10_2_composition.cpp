#include <iostream>
#include <string>

using namespace std;

class Point2D {
	int m_x, m_y;
public:
	Point2D() : m_x(0), m_y(0) { }
	Point2D(int x, int y) : m_x(x), m_y(y) { }
	friend ostream& operator<<(ostream& out, const Point2D &point) {
		out << "(" << point.m_x << ", " << point.m_y << ")";
		return out; }
	void setPoint(int x, int y) {
		m_x = x; m_y = y; }
};

class Creature {
	string m_name;
	Point2D m_location;
public:
	Creature(const string &name, const Point2D &location)
		: m_name(name), m_location(location) { }
	friend ostream& operator<<(ostream& out, const Creature &creature) {
		out << creature.m_name << " is at " << creature.m_location;
		return out; }
	void moveTo(int x, int y) { m_location.setPoint(x, y); }
};

int main() {
	cout << "Enter a name for your creature: ";
	string name;
	cin >> name;
	Creature creature(name, Point2D(4, 7));
	
	while (1) {
		// print the creature's name and location
		cout << creature << '\n';
 
		cout << "Enter new X location for creature (-1 to quit): ";
		int x=0;
		cin >> x;
		if (x == -1) break;
 
		cout << "Enter new Y location for creature (-1 to quit): ";
		int y=0;
		cin >> y;
		if (y == -1) break;
		
		creature.moveTo(x, y);
	}
}