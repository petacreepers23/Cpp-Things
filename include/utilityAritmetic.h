/*
This file will only have things related with mathematics. Non templated code is allowed in this file. Otherwise go to a .hpp
*/
namespace P23 {
	/*
	Returns the modulus operation like in python: -90 mod 360 = 270
	*/
	template <typename T> 
	T modPythonic(T a , T b) {
		return (b +((a)%b))%b;
	}
	
} // namespace P23
