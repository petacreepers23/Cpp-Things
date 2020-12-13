namespace P23 {
/*Returns the modulus operation like in python: -90 mod 360 = 270*/
	template <typename T> 
	T mod_pythonic(T a , T b){
		return (b +((a)%b))%b;
	}
	
	
	
	
	
} // namespace P23
