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


#include <stdexcept>

/** (수정내용) 검토필요 항목: 5, 6, 7, 8, 10 
 * 1. min max return type  변경  -- 완료
 * 2. (LINE#355, #374)min max 로직 수정  -- 완료 
 * 3. initialization 시 type option 제거 -- 완료
 * 4. placement new 로 메모리 할당 (1차원 array 사용, 사이즈 불만족시 예외처리) --완료 
 * 5. try catch 문 코드 수정: exception 을 class 로 -- ?
 * 6. (LINE#296) operator/ 함수 리턴이 예외상황일 경우 무엇을 리턴할지 -- ? 
 * 7. 배열 초기화 로직 삭제 -- 완료
 * 8. (LINE#117) 왜 identity 함수만 static 인지 -- 완료(instance화 하지 않고 call하려는 목적/테스트 코드(LINE#35)에 반영
 * 9. using namespace std 삭제 -- 완료
 * 10. (LINE#49) using value_type = T 의미 -- 완료(stl 컨테이너 기본 멤버)
 * 11. (LINE#394) prod 버그 수정 -- 완료
 * 12. Min, Max 함수 m[0] primitive value 로 초기화 -- 완료
 */
namespace phy
{
	/*
	 * generic 2 dimensional matrix template class
	 */
	template<typename T>
	struct matrix
	{
        private:
			static const std::size_t max_size = 100;
            std::size_t ROW;
            std::size_t COL;
			std::size_t ROWxCOL;
			T *m;
			T buf[max_size];
        public:

			using value_type = T;


			matrix() = delete;

			matrix(const std::size_t row, const std::size_t col): ROW(row), COL(col) {
				//TODO:

				ROWxCOL =ROW*COL;

				if(row*col > max_size )
					throw std::invalid_argument("too large");
				int cnt=0;
				m = new (buf) T[row*col];


				for(int i=0; i<ROWxCOL;i++){
					m[i]=++cnt;
				}				

			}


			void mprint(){
				for(int i=0;i<ROW; i++){
					for(int j=0; j<COL; j++){
						std::cout<<m[i*COL+j]<<' ';
					}
					std::cout<<'\n';
				}
			}
        

			/**
			 * get the number of rows
			 * @return		always rows
			 */
			inline std::size_t rows() const {
				//TODO:
				return ROW;
			}

			/**
			 * get the number of columns
			 * @return		always columns
			 */
			inline std::size_t cols() const {
				//TODO:
				return COL;
			}

			inline bool isSameSize(std::size_t r, std::size_t c) const {
				
				if((ROW == r) &&  (COL == c) ){
					return true;
				}else{
					std::cout<<"cannot prooceed operation (size is differenct)";
					return false;
				}
			}

			/**
			 * get a identity matrix
			 * @return		always indentity matrix
			 */
			static matrix<T> identity(const std::size_t row, std::size_t col) {
				/* exception: it must be "row = col" and row >= 1 */ 
				
				matrix<T> tmp(row, col); 

				tmp.m[0]=1;

				for(int i=1; i<row*col; i++){
					if(i%(col+1)==0){
						tmp.m[i]=1;
					}
					else{
						tmp.m[i]=0;
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
				matrix<T> tmp(row,col);

				int mod = ROWxCOL-1;
				for(int i=0; i< ROWxCOL; i++){
					
					if(i==mod){
						tmp.m[i] = m[mod];
					}else{
						tmp.m[i] = m[(col*i)%mod];
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

				std::cout<<"operator () type1 called"<<std::endl;
				int row = (int)i/COL;
				int col = i%COL;
				return m[row*COL+ col];	
	
			}

			/**
			 * get a reference to an element address by the index
			 * @param		i is the index of the matrix
			 * @return		always const reference of the value
			 */
			const T& operator()(const std::size_t i) const {
				//TODO:

				int row = (int)i/COL;
				int col = i%COL;
				return m[row*COL+ col];	

			}

			/**
			 * get a reference to an element address by the index
			 * @param		row is the row index of the matrix
			 * @param		col is the column index of the matrix
			 * @return		always reference of the value
			 */
			T& operator()(std::size_t row, std::size_t col) {
				//TODO:
				std::cout<<"operator () type2 called"<<std::endl;

				return m[row*COL+col];	
			}

			/**
			 * get a reference to an element address by the index
			 * @param		row is the row index of the matrix
			 * @param		col is the column index of the matrix
			 * @return		always const reference of the value
			 */
			const T& operator()(std::size_t row, std::size_t col) const {
				//TODO:
				return m[row*COL+col];	
			}

			/**
			 * compare two matrix
			 * @param		rhs is the matrix to compare with *this
			 * @return		true if two matrices are equal
			 */
			bool operator==(const matrix<T>& rhs) const {
				//TODO:
				this->isSameSize(rhs.rows(), rhs.cols());
					
				for(int i=0;i<ROWxCOL;i++){
					if(rhs.m[i] != m[i]){
						return false;
					}
				}
				return true;
			}

			/**
			 * compare two matrix
			 * @param		rhs is the matrix to compare with *this
			 * @return		true if two matrices are not equal
			 */
			bool operator!=(const matrix<T>& rhs) const {
				//TODO:
				this->isSameSize(rhs.rows(), rhs.cols());

				for(int i=0;i<ROWxCOL;i++){
					if(rhs.m[i] != m[i]){
						return true;
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
				this->isSameSize(rhs.rows(), rhs.cols());

				matrix<T> tmp(ROW,COL);
				for(int i = 0; i < ROWxCOL; i++) {
						tmp.m[i]=m[i] + rhs.m[i];			 					}
				return tmp;
			}

			/**
			 * matrix subtraction
			 * @param		rhs is the right-hand side matrix to subtract
			 * @return		always matrix subtraction
			 */
			matrix operator-(const matrix<T>& rhs) const {
				//TODO:
				this->isSameSize(rhs.rows(), rhs.cols());

				matrix<T> tmp(ROW,COL);
				for(int i = 0; i < ROWxCOL; i++) {
						tmp.m[i]=m[i] - rhs.m[i];			 	
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

				matrix<T> tmp(ROW,COL);
				for(int i = 0; i < ROWxCOL; i++) {
					tmp.m[i]=m[i] * (rhs);			 	
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
					matrix<T> tmp(ROW,COL);
					for(int i = 0; i < ROWxCOL; i++) {
						tmp.m[i]= m[i]/(rhs);			 	
					}
					return tmp;
				}catch(int exception){
					std::cout<<"divide by 0 \n";
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
					if(COL != rhs.rows())
						throw -1;
					
					int rhsCOL = rhs.cols();

					matrix<T> tmp(ROW,rhsCOL);
					
					for(int i=0; i<ROW; i++){
						for(int j=0; j<rhsCOL; j++){
							tmp.m[i*rhsCOL+j]=0;
							for(int k=0; k<COL; k++){
								tmp.m[i*rhsCOL+j]+=m[i*COL+k]*rhs.m[k*rhsCOL+j];
							}
						}
					}

					return tmp;
				}catch(int exception){
					std::cout<<"cannot calculate(size is not fit)\n";
				}
			}

			/**
			 * get the minimum of all its coefficients
			 * return		always minimum value of all its coefficients
			 */

			template<typename U = T>
			U min() const {
				/* exception (no coefficient) neccesary */

				//U minValue = m[0];
				U minValue = std::numeric_limits<U>::max();

				for(int i=0;i<ROWxCOL;i++){
					if(minValue > m[i]){
						minValue = m[i];
					}
				}
				return minValue;
			}

			/**
			 * get the maximum of all its coefficients
			 * return		always maximum value of all its coefficients
			 */
			template<typename U = T>
			U max() const {
				/* exception (no coefficient) neccesary */

				//U maxValue = m[0];

				U maxValue = std::numeric_limits<U>::min();
				for(int i=0;i<ROWxCOL;i++){
					if(maxValue < m[i]){
						maxValue = m[i];						
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
				U sumValue = 0;

				for(int i=0;i<ROWxCOL;i++){
					sumValue+=m[i];
				}
				return sumValue;

			}

			/**
			 * get the product of all its coefficients
			 * return		always product of all its coefficients
			 */
			template<typename U = T>
			U prod() const {
				U prodValue = 1;

				for(int i=0;i<ROWxCOL;i++){
					prodValue*=m[i];
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
					if(ROW==0 || COL==0)  throw -1;
				}catch(int exception){
					std::cout<<"cannot calculate (no coefficients)";
				}
				meanValue = this->sum()/(ROWxCOL);
				return meanValue;
			}
	};
}

#endif // __PHY_MATRIX_H__
