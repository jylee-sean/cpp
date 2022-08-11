/**
 * @brief		generic 2 dimensional matrix template class
 * @details		the template class composites std::array
 * 				and i wanted this to be something like Eigen Matrix implementation
 * @author		inode(joongyoung.eom@endoquestrobotics.com)
 * @version		initial
 * @copyright	EndoQuest Robotics, Inc. All rights reserved.
 */

#ifndef __PHY_MATRIX_H__
#define __PHY_MATRIX_H__

#include <array>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

/**
 * 1. 생성자 호출하면서 ROW, COL 
 * 
 */
namespace phy
{
	/**
	 * generic 2 dimensional matrix template class
	 */
	template<typename T>
	struct matrix
	{
        private:
            T **m;
            int ROW;
            int COL;
            
        public:

		using value_type = T;

		matrix() = delete;

		matrix(const std::size_t row, const std::size_t col) {
			//TODO:
			ROW = row;
			COL = col;

            m = new T*[row];
            for(int i=0;i<row; ++i){
                m[i]=new T[col];
            }

            int cnt=0;
            for(int i=0;i<row; i++)
                for(int j=0; j<col; j++)
                    m[i][j]=cnt++;
		}

        void mprint(){
            for(int i=0;i<this->rows(); i++){
                for(int j=0; j<this->cols(); j++){
                    cout<<m[i][j]<<' ';
                }
                cout<<'\n';
            }
        }
        

		/**
		 * get the number of rows
		 * @return		always rows
		 */
		inline std::size_t rows() const {
			//TODO:
           return this->ROW;
		}

		/**
		 * get the number of columns
		 * @return		always columns
		 */
		inline std::size_t cols() const {
			//TODO:
			return this->COL;
		}

		/**
		 * get a identity matrix
		 * @return		always indentity matrix
		 */
		static matrix<T> identity() {
			//TODO:
            matrix<T> tmp(ROW, COL);

            for(int i=0;i<tmp.rows();i++){
                for(int j=0;j<tmp.cols();j++){
                    if(i==j){
                        tmp.m[i][j]=1;
                    }else{
                        tmp.m[i][j]=0;
                    }
                }
            }

            return tmp;
		}

		/**
		 * get the transposition of the matrix
		 * @warning		be aware that this method returns a matrix newly created instead of changing current instance
		 * @return		always transposition matrix
		 */
		matrix<T> transpose() {
			//TODO:
            matrix<T> tmp(row,col);
			// for(std::size_t row = 0; row < this->rows(); row++) {
			// 	for(std::size_t col = 0; col < this->cols(); col++) {
			// 		ret._array[col * this->rows() + row] = this->operator()(row,col);
			// 	}
			// }
			// return ret;
		}

		/**
		 * get a reference to an element address by the index
		 * @param		i is the index of the matrix
		 * @return		always reference of the value
		 */
		T& operator()(const std::size_t i) {
			//TODO:

 
		}

		/**
		 * get a reference to an element address by the index
		 * @param		i is the index of the matrix
		 * @return		always const reference of the value
		 */
		const T& operator()(const std::size_t i) const {
			//TODO:
		}

		/**
		 * get a reference to an element address by the index
		 * @param		row is the row index of the matrix
		 * @param		col is the column index of the matrix
		 * @return		always reference of the value
		 */
 		T& operator()(const std::size_t row, std::size_t col) {
			//TODO:
		}

		/**
		 * get a reference to an element address by the index
		 * @param		row is the row index of the matrix
		 * @param		col is the column index of the matrix
		 * @return		always const reference of the value
		 */
		const T& operator()(std::size_t row, std::size_t col) const {
			//TODO:
		}

		/**
		 * compare two matrix
		 * @param		rhs is the matrix to compare with *this
		 * @return		true if two matrices are equal
		 */
		bool operator==(const matrix<T>& rhs) const {
			//TODO:
		}

		/**
		 * compare two matrix
		 * @param		rhs is the matrix to compare with *this
		 * @return		true if two matrices are not equal
		 */
		bool operator!=(const matrix<T>& rhs) const {
			//TODO:
		}

		/**
		 * matrix addition
		 * @param		rhs is the right-hand side matrix to add
		 * @return		always matrix addition
		 */
		matrix operator+(const matrix<T>& rhs) const {
			//TODO:
		}

		/**
		 * matrix subtraction
		 * @param		rhs is the right-hand side matrix to subtract
		 * @return		always matrix subtraction
		 */
		matrix operator-(const matrix<T>& rhs) const {
			//TODO:
		}

		/**
		 * matrix scalar multiplication
		 * @param		rhs is the right-hand side value to multiply
		 * @return		always matrix multiplication
		 */
		matrix operator*(const T& rhs) const {
			//TODO:
		}

		/**
		 * matrix scalar division
		 * @param		rhs is the right-hand side value to divide
		 * @return		always matrix division
		 */
		matrix operator/(const T& rhs) const {
			//TODO:
		}

		/**
		 * matrix multiplication
		 * @warning		there's room for improvement
		 *				you might wanna apply Strassen's formula or somethig else for efficiency
		 * @param		rhs is the right-hand side matrix to multiply
		 * @return		always matrix multiplication
		 */
		matrix<T> operator*(const matrix<T>& rhs) const {
			//TODO:
		}

		/**
		 * get the minimum of all its coefficients
		 * return		always minimum value of all its coefficients
		 */
		T min() const {
			//TODO:
		}

		/**
		 * get the maximum of all its coefficients
		 * return		always maximum value of all its coefficients
		 */
		T max() const {
			//TODO:
		}
			
		/**
		 * get the sum of all its coefficients
		 * return		always sum of all its coefficients
		 */
		// U sum() const {
		// 	//TODO:
		// }

		/**
		 * get the product of all its coefficients
		 * return		always product of all its coefficients
		 */
		// U prod() const {
		// 	//TODO:
		// }

		/**
		 * get the mean of all its coefficients
		 * return		always mean value of all its coefficients
		 */
		// U mean() const {
		// 	//TODO:
		// }
	};
}

#endif // __PHY_MATRIX_H__
