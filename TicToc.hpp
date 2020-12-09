#include <iostream>
#include <chrono>

//Petacreepers23 namespace
namespace P23 {

	class TicToc {
	public:
		//Empieza el contador
		void tic() {
			t0 = std::chrono::high_resolution_clock::now();
		}
		//Acaba e imprime el tiempo
		void toc() {
			t1 = std::chrono::high_resolution_clock::now();
			std::cout << "Elapsed: " << 1.e-9*std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() << "s" << std::endl;
		}
		//Si se ha ejecutado en un bucle, divide el tiempo total entre el numero de iteraciones
		void toc(size_t iters) {
			t1 = std::chrono::high_resolution_clock::now();
			std::cout << "Elapsed: " << 1.e-9*std::chrono::duration_cast<std::chrono::nanoseconds>(t1 - t0).count() / iters << "s" << std::endl;
		}
	private:
		std::chrono::steady_clock::time_point t0;
		std::chrono::steady_clock::time_point t1;
	};
}
