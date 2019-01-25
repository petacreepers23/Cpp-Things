#include <iostream>
#include <chrono>

class TicToc {
public:
	void tic() {
		t0 = std::chrono::high_resolution_clock::now();
	}
	void toc() {
		t1 = std::chrono::high_resolution_clock::now();
		std::cout << "Elapsed: " << 1.e-9*std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << "s" << std::endl;
	}
	void toc(int iters) {
		t1 = std::chrono::high_resolution_clock::now();
		std::cout << "Elapsed: " << 1.e-9*std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() / iters << "s" << std::endl;
	}
private:
	std::chrono::steady_clock::time_point t0;
	std::chrono::steady_clock::time_point t1;
};
