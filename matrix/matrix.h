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
            std::size_t ROW;
            std::size_t COL;
        public:

			using value_type = T;
    	    enum {ZERO = 0, INCREASE = 1};
			int TYPE;

		matrix() = delete;

		matrix(const std::size_t row, const std::size_t col, int type): ROW(row), COL(col), TYPE(type) {
			//TODO:

            m = new T*[row];
            for(int i=0;i<row; ++i){
                m[i]=new T[col];
            }
            int cnt=0;
            for(int i=0;i<row; i++)
                for(int j=0; j<col; j++)
					if(type == ZERO){
						m[i][j]=0;
					}else{
                    	m[i][j]=cnt++;
					}
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

		inline bool compareSize(std::size_t r, std::size_t c) const {
			bool isSameSize = true;
			try{
				if((this->rows() != r) ||  (this->cols() != c) )  throw -1;
				else return isSameSize;

			}catch(int exception){
				cout<<"cannot prooceed operation (size is differenct)";
				return false;
			}
		}

		/**
		 * get a identity matrix
		 * @return		always indentity matrix
		 */
		static matrix<T> identity(const std::size_t row, std::size_t col) {
			//TODO:
            matrix<T> tmp(row, col, tmp.ZERO);

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
		matrix<T> transpose(const std::size_t row, std::size_t col) {
			//TODO:
            matrix<T> tmp(row,col,tmp.ZERO);
			for(int i = 0; i < this->rows(); i++) {
			 	for(int j = 0; j < this->cols(); j++) {
					tmp.m[i][j]=m[j][i];			 	
				}
			}
			return tmp;
		}

		/**
		 * get a reference to an element address by the index
		 * @param		i is the index of the matrix
		 * @return		always reference of the value
		 */
		T& operator()(const std::size_t i) {
			//TODO:
			int row = (int)i/(this->cols());
			int col = i%(this->cols());
			return m[row][col];	
 
		}

		/**
		 * get a reference to an element address by the index
		 * @param		i is the index of the matrix
		 * @return		always const reference of the value
		 */
		const T& operator()(const std::size_t i) const {
			//TODO:

			int row = (int)i/(this->cols());
			int col = i%(this->cols());
			return m[row][col];	

		}

		/**
		 * get a reference to an element address by the index
		 * @param		row is the row index of the matrix
		 * @param		col is the column index of the matrix
		 * @return		always reference of the value
		 */
 		T& operator()(std::size_t row, std::size_t col) {
			//TODO:
			return m[row][col];	
		}

		/**
		 * get a reference to an element address by the index
		 * @param		row is the row index of the matrix
		 * @param		col is the column index of the matrix
		 * @return		always const reference of the value
		 */
		const T& operator()(std::size_t row, std::size_t col) const {
			//TODO:
			return m[row][col];
		}

		/**
		 * compare two matrix
		 * @param		rhs is the matrix to compare with *this
		 * @return		true if two matrices are equal
		 */
		bool operator==(const matrix<T>& rhs) const {
			//TODO:
			this->compareSize(rhs.rows(), rhs.cols());

			bool isSame = true;
				
			for(int i=0;i<this->rows();i++){
				for(int j=0;j<this->cols();j++){
					if(rhs.m[i][j] != m[i][j]){
						return false;
					}
				}
			}
			return isSame;
		}

		/**
		 * compare two matrix
		 * @param		rhs is the matrix to compare with *this
		 * @return		true if two matrices are not equal
		 */
		bool operator!=(const matrix<T>& rhs) const {
			//TODO:
			this->compareSize(rhs.rows(), rhs.cols());

			bool isNotSame = true;
			for(int i=0;i<this->rows();i++){
				for(int j=0;j<this->cols();j++){
					if(rhs.m[i][j] != m[i][j]){
						return isNotSame;
					}
				}
			}
			return false;
		}

		/**
		 * matrix addition
		 * @param		rhs is the right-hand side matrix to add
		 * @return		always matrix addition
		 */
		matrix operator+(const matrix<T>& rhs) const {
			//TODO:
			/* compare size is necessary */
			matrix<T> tmp(this->rows(),this->cols(), tmp.ZERO);
			for(int i = 0; i < this->rows(); i++) {
			 	for(int j = 0; j < this->cols(); j++) {
					tmp.m[i][j]=m[i][j] + rhs.m[i][j];			 	
				}
			}
			return tmp;
		}

		/**
		 * matrix subtraction
		 * @param		rhs is the right-hand side matrix to subtract
		 * @return		always matrix subtraction
		 */
		matrix operator-(const matrix<T>& rhs) const {
			//TODO:
			matrix<T> tmp(this->rows(),this->cols(), tmp.ZERO);
			for(int i = 0; i < this->rows(); i++) {
			 	for(int j = 0; j < this->cols(); j++) {
					tmp.m[i][j]=m[i][j] - rhs.m[i][j];			 	
				}
			}
			return tmp;
		}

		/**
		 * matrix scalar multiplication
		 * @param		rhs is the right-hand side value to multiply
		 * @return		always matrix multiplication
		 */
		matrix operator*(const T& rhs) const {
			//TODO:

			matrix<T> tmp(this->rows(),this->cols(), tmp.ZERO);
			for(int i = 0; i < this->rows(); i++) {
			 	for(int j = 0; j < this->cols(); j++) {
					tmp.m[i][j]=m[i][j] * (rhs);			 	
				}
			}
			return tmp;
		}

		/**
		 * matrix scalar division
		 * @param		rhs is the right-hand side value to divide
		 * @return		always matrix division
		 */
		matrix operator/(const T& rhs) const {
			//TODO:
			try{
				if(rhs==0) throw -1;
				matrix<T> tmp(this->rows(),this->cols(), tmp.ZERO);
				for(int i = 0; i < this->rows(); i++) {
					for(int j = 0; j < this->cols(); j++) {
						tmp.m[i][j]=m[i][j] / (rhs);			 	
					}
				}
				return tmp;
			}catch(int exception){
				cout<<"divide by 0 \n";
			}
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
			
			try{
				/*size comparison*/
				if(this->cols() != rhs.rows()) throw -1;
				matrix<T> tmp(this->rows(),rhs.cols(),tmp.ZERO);
				
				for(int i=0; i<this->rows(); i++){
					for(int j=0; j<rhs.cols(); j++){
						for(int k=0; k<this->cols(); k++){
							tmp.m[i][j]+=m[i][k]*rhs.m[k][j];
						}
					}
				}
				return tmp;

			}catch(int exception){
				cout<<"cannot calculate(size is not fit)\n";
			}
		}

		/**
		 * get the minimum of all its coefficients
		 * return		always minimum value of all its coefficients
		 */

		template<typename U = T>
		T min() const {
			//TODO:
			U minValue = 9999u;

			for(int i=0;i<this->rows();i++){
				for(int j=0;j<this->cols();j++){
					if(minValue > m[i][j]){
						minValue = m[i][j];
					}
				}
			}
			return minValue;
		}

		/**
		 * get the maximum of all its coefficients
		 * return		always maximum value of all its coefficients
		 */
		template<typename U = T>
		T max() const {
			//TODO:
			U maxValue = 0;

			for(int i=0;i<this->rows();i++){
				for(int j=0;j<this->cols();j++){
					if(maxValue < m[i][j]){
						maxValue = m[i][j];						
					}
				}
			}
			return maxValue;
		}
			
		/**
		 * get the sum of all its coefficients
		 * return		always sum of all its coefficients
		 */
		template<typename U = T>
		U sum() const {
			//TODO:
			U sumValue = 0;

			for(int i=0;i<this->rows();i++){
				for(int j=0;j<this->cols();j++){
					sumValue+=m[i][j];
				}
			}
			return sumValue;

		}

		/**
		 * get the product of all its coefficients
		 * return		always product of all its coefficients
		 */
		template<typename U = T>
		U prod() const {
		 	//TODO:
			U prodValue = 0;

			for(int i=0;i<this->rows();i++){
				for(int j=0;j<this->cols();j++){
					prodValue*=m[i][j];
				}
			}
			return prodValue;
		}

		/**
		 * get the mean of all its coefficients
		 * return		always mean value of all its coefficients
		 */
		template<typename U = T>
		U mean() const {
			//TODO:
			U meanValue = 0;
			try{
				if(this->rows()==0 || this->cols()==0)  throw -1;
			}catch(int exception){
				cout<<"cannot calculate (no coefficients)";
			}
			meanValue = this->sum()/((this->rows())*(this->cols()));
			return meanValue;
		}
	};
}

#endif // __PHY_MATRIX_H__
