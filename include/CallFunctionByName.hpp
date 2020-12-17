#include <any> //Store methods
#include <map> //Access stored methods
#include <string> //Name methods
#include <functional> //Lambda for capturing instance of class with methods
#include <iostream> //std::cout

/*
This file will only have things related with any structure that can store and call a
function by its name
*/
namespace P23 {
	class FuncByNameExample
	{
	private:
	//map with methods
		std::map<std::string, std::any> Funciones;
	//some class attribute
		int my_attr = 0;

	//Private methods
		int exampleFunction_A(int x){return x;}
		float exampleFunction_B(int y, int z){return (float)y/z;}
		void exampleFunction_C(){std::cout << my_attr << std::endl;};


	public:
		FuncByNameExample() {
			//We fill in map with method information
			Funciones["exampleFunction_A"] = std::function<int (int)>([=](auto param){return this->exampleFunction_A(param);}); // Method with 1 param
			Funciones["exampleFunction_B"] = std::function<float (int,int)>([=](auto... params) {return this->exampleFunction_B(params...); }); // Method with 2+ param
			Funciones["exampleFunction_C"] = std::function<void()>([=]() {return this->exampleFunction_C(); }); // Method with 0 param
		}


		//use: call with execute<Return_type>("Method_name",param1,param2,...)
		template<typename Ret, typename... Args> Ret execute(std::string Funcion, Args ... a) {
			return std::any_cast<std::function<Ret(Args...)>>(Funciones[Funcion])(a...);
		}

		//some test
		void test() {
			Execute<void>("exampleFunction_C");
			std::cout << execute<int>("exampleFunction_A",3) << std::endl;
			std::cout << execute<float>("exampleFunction_B", 3,2) << std::endl;
		}
	};
}
