	// Calculator.h
	// WS09 in-lab
	#ifndef _SDDS_CALCULATOR_H_
	#define _SDDS_CALCULATOR_H_
	#include <iostream>
namespace sdds {
	template <typename T, int N>
	class Calculator {
		T results[N];
	public:

		Calculator() {
			for(int i =0;i<N;i++){
                        results[i] = 0;
                    }
		}


		void add(const T* a, const T* b) {

			for (int i = 0; i < N; i++) {
				results[i] = a[i] + b[i];
			}
		}

		void subtract(const T* a, const T* b) {

			for (int i = 0; i < N; i++) {
				results[i] = a[i] - b[i];
			}

		}

		void multiply(const T* arr1, const T* arr2) {

			for (int i = 0; i < N; i++) {
				results[i] = arr1[i] * arr2[i];
			}
		}

		void divide(const T* arr1, const T* arr2) {

			for (int i = 0; i < N; i++) {
				results[i] = arr1[i] / arr2[i];
			}
		}

		std::ostream& display(std::ostream& os)const {
			for (int i = 0; i < N; i++) {
				os << results[i];
                                if(i!=N-1){
                                  os<< ",";
                                 }
			}
			os << std::endl;
			return os;
		}

		Calculator& operator+=(const T* ro) {

			for (int i = 0; i < N; i++) {
				results[i] += ro[i];
			}
			return *this;

		}

		Calculator& operator-=(const T* ro) {

			for (int i = 0; i < N; i++) {
				results[i] -= ro[i];
			}
			return *this;

		}

		Calculator& operator*=(const T* ro) {

			for (int i = 0; i < N; i++) {
				results[i] *= ro[i];
			}
			return *this;

		}

		Calculator& operator/=(const T* ro) {

			for (int i = 0; i < N; i++) {
				results[i] /= ro[i];
			}
			return *this;

		}

	};

}



	#endif

