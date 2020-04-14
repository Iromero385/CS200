#include <chrono> // chrono 
#include <cstdlib> // srand, rand 
#include <ctime> // time 
#include <algorithm> // sort
#include <iostream>

class Timer {
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now()) {}
	void reset() { m_beg = clock_t::now(); }
	double elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void bubbleSort(int* a, int size) {
    for(int i=0; i<size; i++)
        for(int j=0; j<size-1; j++) {
            if(a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
        }
}

void show(int *a) {
    for(int i=0; i<5; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}
 
int main() {
	const int Size = 10000;
	int array1[Size];
    int array2[Size];
    
    srand (time(NULL));
    int fill;
    for(int i=0; i<Size; i++) {
        array1[i] =array2[i] = rand() % 100003; // next prime 10X
    }
    
    show(array1);
    show(array2);
    

    Timer t1;
	bubbleSort(array1, Size);
	double run1 = t1.elapsed();
    show(array1);
		
    Timer t2;
	std::sort(array2, array2+Size);
    double run2 = t2.elapsed();
    show(array2);
    std::cout << "Bubble Sort Time: " << run1 << " seconds\n"
        << "CPP Sort Time: " << run2 << " seconds\n"
        << "Efficientcy: " << int( run1/run2 );
 
	return 0;
}