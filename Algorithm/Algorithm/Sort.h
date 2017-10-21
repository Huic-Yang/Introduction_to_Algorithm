#pragma once

#include <vector>

template< typename T >
struct Sort {
	virtual operator()( std::vector< T > vec ) = 0;
};

template< typename T >
struct insertSort : public Sort {
	void operator()( std::vector< T > vec ) {
		for( unsigned i = 1; i < vec.size(); ++i ) {
			T key = vec[i];
			unsigned j = i-1;
			while( 0 <= j && vec[j+1] < vec[j] )
				vec[j+1] = vec[j], --j;
			vec[j+1] = key;
		}
	}
}