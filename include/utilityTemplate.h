/*
This file will only have things related with utility and execution stuff. Non templated code is allowed in this file. Otherwise go to a .hpp
*/
namespace P23 {
	/*
	Upon static creation, it will only run once the function passed as parameter
	example:
		-----
		while(true){
			RunOnce hey([](){std::cout << "Echo!" << std::endl;});
			std::cout << "...echo" << std::endl;
		}
		-----
	output:
		Echo!
		...echo...echo...echo...echo...echo
	*/
	template<typename T> struct RunOnce {
		RunOnce(T&& f) {f(); }
	};
}