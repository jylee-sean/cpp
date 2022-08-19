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

/** (수정)
 * 1. min max return type  변경  -- 완료
 * 2. min max numeric limit 적용  -- 타입에 따라 어떻게? 
 * 3. initialization 시 type option 제거 -- 완료
 * 4. inplace new 로 메모리 할당  or array 로 할당 후 (사이즈 불만족시 예외처리) 
 * 5. try catch 문 코드 수정: exception 을 class 로 --
 * 6. operator/ 함수 리턴이 예외상황일 경우 처리 방법 -- ? 
 * 7. 배열 초기화 로직 삭제 -- new 로 배열 생성시 초기값 0 
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
            static const size_t max_size = 10;
            std::size_t ROW;
            std::size_t COL;
			T *m;

            T buf[max_size * max_size];

            //T *
        public:

			using value_type = T;


			matrix() = delete;

			matrix(const std::size_t row, const std::size_t col): ROW(row), COL(col) {
                
                if(row > max_size || col > max_size){
                    cout<<"exception\n";
                }
                int cnt=0;
                m = new (buf)T[row*col];
                cout<<"completed\n";

                cout<<row<<col<<endl;

                for(int i=0;i<row; i++){
                    for(int j=0;j<col; j++){
                        m[i*col+j] = cnt++;
                //         cout<<i*col+j<<endl;
                    }
                }
                // cout<<"completed2\n";

				//TODO:
				// int cnt=0;
				// //m = new T*[row];
				// for(int i=0;i<row; ++i){
				// 	for(int j=0; j<col; ++j){
				// 		m[i][j]=cnt++;
				// 	}
				// }
			}


			void mprint(){
				for(int i=0;i<this->rows(); i++){
					for(int j=0; j<this->cols(); j++){
						cout<<m[i*this->cols()+j]<<' ';
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
			static matrix<T> identity(const std::size_t row, std::size_t col) {
				//TODO:
				matrix<T> tmp(row, col);

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

	};
}

#endif // __PHY_MATRIX_H__
