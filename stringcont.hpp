#include <string>
#include <memory>
#include <cstring>
#include <iostream>
/*
Tree data structure

*/
template <typename T>
class StringTree{
	public:
		StringTree() = default;
		~StringTree(){
			/*TODO*/
		}
		StringTree& operator[](std::string index){
			if(index.size() == 0) return (*this);
			//We need to find it.
			char c = index.front(); 
			c &= 127; //Only ascii-allowed!
			index = index.substr(1, std::string::npos);
			if(c == 0) return (*this); /*Unusual case- the string had an extra NULL in it.*/
			c--; /*Need to decrement. Index between 0 and 254.*/
			/*Check if we have such a child.*/
			if (children[c].get()) return (*children[c].get())[index];
			/*We must create children of c*/
			/*std::cout << "\nEVENT: Allocation with remaining index: " << index << std::endl;*/
			children[c] = std::unique_ptr<StringTree<T>> (new StringTree<T>());
			return (*children[c].get())[index];
		}
		T data; //the data we hold.
	private:
		std::array<std::unique_ptr<StringTree<T>>, 127> children;
		
};

/*static_assert(sizeof(std::unique_ptr<int>) == 8, "unique pointer not as small as you think???");*/
