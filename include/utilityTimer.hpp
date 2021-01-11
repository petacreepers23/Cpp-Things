#include <chrono>
#include <iostream>

/*
   This file will only have things related with measuring time in a easy manner
*/
namespace P23 {
	constexpr float nanoConversion = 1.e-9;

	class TicToc {
		public:
			// Counter Starts
			void tic() { t0 = std::chrono::steady_clock::now(); }
			// Counter Ends and prints time
			void toc() {
				t1 = std::chrono::steady_clock::now();
				std::cout << "Elapsed: "
					<< nanoConversion * std::chrono::duration_cast<std::chrono::nanoseconds>(
							t1 - t0)
					.count()
					<< "s" << std::endl;
			}
			// For use after a loop, divides the final time by the total number of
			// iterations
			void toc(size_t iters) {
				t1 = std::chrono::steady_clock::now();
				std::cout << "Elapsed: "
					<< nanoConversion *
					std::chrono::duration_cast<std::chrono::nanoseconds>(t1 -
							t0)
					.count() /
					iters
					<< "s" << std::endl;
			}

		private:
			std::chrono::steady_clock::time_point t0;
			std::chrono::steady_clock::time_point t1;
	};

	/* Class that on constructor starts timing, and on destructor ends. */
	class QuickTicToc {
		public:
			// Counter starts
			QuickTicToc() : timeStart(std::chrono::steady_clock::now()) {}
			// Counter ends
			~QuickTicToc() {
				std::chrono::steady_clock::time_point timeEnd =
					std::chrono::steady_clock::now();
					std::cout << "Elapsed: "
					<< nanoConversion *
					std::chrono::duration_cast<std::chrono::nanoseconds>
					(timeEnd - timeStart).count()
					<< "s" << std::endl;
			}

		private:
			std::chrono::steady_clock::time_point timeStart;
	};
} // namespace P23
