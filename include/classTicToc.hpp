#include <iostream>
#include <chrono>

/*
This file will only have things related with measuring time in a easy manner

//TODO: QuickTicToc: a class that on constructor starts timing, and on destructor ends.
//TODO: after that, probably a rename to "utilityTime.hpp would occurr"
*/
namespace P23 {

	class TicToc {
	public:
		//Counter Starts
		void tic() {
			t0 = std::chrono::high_resolution_clock::now();
		}
		//Counter Ends and prints time
		void toc() {
			t1 = std::chrono::high_resolution_clock::now();
			std::cout << "Elapsed: " << 1.e-9*std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << "s" << std::endl;
		}
		//For use after a loop, divides the final time by the total number of iterations
		void toc(size_t iters) {
			t1 = std::chrono::high_resolution_clock::now();
			std::cout << "Elapsed: " << 1.e-9*std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() / iters << "s" << std::endl;
		}
	private:
		std::chrono::steady_clock::time_point t0;
		std::chrono::steady_clock::time_point t1;
	};
}
