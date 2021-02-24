/*
This file will only have things related with utility and execution stuff. Non templated code is allowed in this file. Otherwise go to a .hpp
*/
namespace P23 {
	/*
	Upon static creation, it will only run once the function passed as parameter
	example:
		-----
		while(true){
			static RunOnce hey([](){std::cout << "Echo!" << std::endl;});
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
	
	
	/*
	Returns a vector with all the combinations taken by groups of size N
	Example:
	my_vect = {1,2,3,4,5,6};
	result = combine<int,3>(my_vect);
	result is -> 
	{
		{1,2,3},{1,2,4},{1,2,5},{1,2,6},
		{1,3,4},{1,3,5},{1,3,6},
		{1,4,5},{1,4,6},{1,5,6},
		{2,3,4},{2,3,5},{2,3,6},
		{2,4,5},{2,4,6},{2,5,6},
		{3,4,5},{3,4,6},{3,5,6},
		{4,5,6}
	}
	*/
	template<typename T, size_t N> std::vector<std::vector<T>> combine(const std::vector<T>& elements) {
		std::vector<bool> selection_array(elements.size());
		std::fill(selection_array.end() - N, selection_array.end(), true);
		std::vector<std::vector<T>> res;

		do {
			std::vector parcial;
			for (size_t i = 0; i < elements.size(); ++i) {	
				if (selection_array[i]) {
					parcial.push_back(elements[i]);
				}
			}
			res.push_back(parcial);
		} while (std::next_permutation(selection_array.begin(), selection_array.end()));

		return res;
	}
}
