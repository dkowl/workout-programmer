#pragma once

#include <vector>
using namespace std;

//works like a property, but internally stores all history of changes aswell

template <class T>
class LoggedProperty {

private:
	vector<T> history_;

public:

	T& operator = (const T& i) {
		history_.push_back(i);
		return (T)*this;
	}

	operator T const& () const {
		if (history_.empty()) return T();
		else return history_.back();
	}


};
