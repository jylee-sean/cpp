#include <iostream>
#include<time.h>



using std::cout;
using std::endl;

static void matrix_multiplication_normal(float* matA,float* matB,float* result,const int M,const int N,const int K)
{
	for (int i = 0; i < M;i++)
	{
		for (int j = 0; j < N;j++)
		{
			float sum = 0.0f;
			for (int k = 0; k < K;k++)
			{
				sum += matA[i*K + k] * matB[k*N + j];
			}
			result[i*N + j] = sum;
		}
	}
}

static void mPrint(float* result, int M, int N){
    cout<<"\n============================="<<endl;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            //printf("%f ",result[i*N + j]);
			cout<<result[i%N+j]<<" ";
        }
		cout<<" "<<endl;
    }
	cout<<" "<<endl;
}

/*
 * Strassen Algorithm
 * matA a M*K matrix
 * matB a K*N matrix
 * matC a M*N matrix
 * matC = matA * matB
 * M1 = (A11+A22)*(B11+B22)
 * M2 = (A21+A22)*B11
 * M3 = A11*(B12-B22)
 * M4 = A22*(B21-B11)
 * M5 = (A11+A12)*B22
 * M6 = (A21-A11)*(B11+B12)
 * M7 = (A12-A22)*(B21+B22)
 * C11 = M1+M4-M5+M7
 * C12 = M3+M5
 * C21 = M2+M4
 * C22 = M1-M2+M3+M6
 */
static void matrix_multiplication_strassen(float* matA, float* matB, float* result, const int M, const int N, const int K)
{
	if ((M <= 2) || M%2 != 0 || N%2 != 0 || K%2!=0)
	{
		return matrix_multiplication_normal(matA, matB, result, M, N, K);
	}

	int offset = 0;
	//M1 = (A11+A22)*(B11+B22)
	float* M1 = new float[(M/2) * (N/2) * sizeof(float)];
	{
		//M1_0 = (A11+A22)
		float * M1_0 = new float[(M/2) * (K/2) * sizeof(float)];
		offset = M*K / 2 + K / 2;
		
		for (int i = 0; i < M / 2; i++)
		{
			for (int j = 0; j < K/2; j++)
			{
				const int baseIdx = i*K + j;
				M1_0[i*K/2+j] = matA[baseIdx] + matA[baseIdx + offset];
			}
		}
		//M1_1 = (B11+B22)
		float* M1_1 = new float[(K/2) * (N/2) * sizeof(float)];
		offset = K*N / 2 + N / 2;
		for (int i = 0; i < K / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				const int baseIdx = i*N + j;
				M1_1[i*N/2+j] = matB[baseIdx] + matB[baseIdx + offset];
			}
		}
		matrix_multiplication_strassen(&M1_0[0], &M1_1[0], &M1[0], M / 2, N / 2, K / 2);

		delete []M1_0;         
		delete []M1_1;         
	}

	//M2 = (A21+A22)*B11
	float* M2 = new float[(M/2) * (N/2) * sizeof(float)];
	{
		//M2_0 = (A21+A22)
		float* M2_0 = new float[(M/2) * (K/2) * sizeof(float)];
		offset = K / 2;
		for (int i = M / 2; i < M; i++)
		{
			for (int j = 0; j < K / 2; j++)
			{
				const int baseIdx = i*K + j;
				M2_0[(i-M/2)*K/2+j] = matA[baseIdx] + matA[baseIdx + offset];
			}
		}
		//M2_1 = B11
        float* M2_1 = new float[(K/2) * (N/2) * sizeof(float)];
        for(int i = 0; i < K / 2; i++) {
            for(int j = 0; j < N / 2; j++){
                M2_1[i * N/2 + j] = matB[i * N + j];
            }
        }
		matrix_multiplication_strassen(&M2_0[0], &M2_1[0], &M2[0], M / 2, N / 2, K / 2);

		delete []M2_0;
		delete []M2_1;
	}

	//M3 = A11*(B12-B22)
	float* M3 = new float[(M/2) * (N/2) * sizeof(float)];
	{
		//M3_0 = A11
		float* M3_0 = new float[(M/2) * (K/2) * sizeof(float)];
		for(int i = 0; i < M / 2; i++){
            for(int j = 0; j < K / 2; j++){
                M3_0[i * K/2 + j] = matA[i * K + j];
            }
		}
		//M3_1 = (B12-B22)
		float* M3_1 = new float[(K/2) * (N/2) * sizeof(float)];
		offset = K*N / 2;
		for (int i = 0; i < K/2; i++)
		{
			for (int j = N/2; j < N; j++)
			{
				const int baseIdx = i*N + j;
				M3_1[i*N/2+j-N/2] = matB[baseIdx] - matB[baseIdx + offset];
			}
		}
		matrix_multiplication_strassen(&M3_0[0], &M3_1[0], &M3[0], M / 2, N / 2, K / 2);

		delete []M3_0;
		delete []M3_1;
	}

	//M4 = A22*(B21-B11)
	float* M4 = new float[(M/2) * (N/2) * sizeof(float)];
	{
		//M4_0 = A22
		float* M4_0 = new float[(M/2) * (K/2) * sizeof(float)];
		for(int i = M / 2; i < M; i++){
            for(int j = K / 2; j < K; j++){
                M4_0[(i-M/2) * K/2 + j - K/2] = matA[i * K + j];
            }
		}
		//M4_1 = (B21-B11)
		float* M4_1 = new float[(K/2) * (N/2) * sizeof(float)];
		offset = N*K/2;
		for (int i = 0; i < K / 2; i++)
		{
			for (int j = 0; j < N/2; j++)
			{
				const int baseIdx = i*N + j;
				M4_1[i*N/2 + j] = matB[baseIdx + offset] - matB[baseIdx];
			}
		}
		matrix_multiplication_strassen(&M4_0[0], &M4_1[0], &M4[0], M / 2, N / 2, K / 2);

		delete []M4_0;
		delete []M4_1;
	}

	//M5 = (A11+A12)*B22
	float* M5 = new float[(M/2) * (N/2) * sizeof(float)];
	{
		//M5_0 = (A11+A12)
		float* M5_0 = new float[(M/2) * (K/2) * sizeof(float)];
		offset = K / 2;
		for (int i = 0; i < M/2; i++)
		{
			for (int j = 0; j < K / 2; j++)
			{
				const int baseIdx = i*K + j;
				M5_0[i*K / 2 + j] = matA[baseIdx] + matA[baseIdx + offset];
			}
		}
		//M5_1 = B22
		float* M5_1 = new float[(K/2) * (N/2) * sizeof(float)];
		offset = N*K/2 + N/2;
		for(int i = 0; i < K / 2; i++){
            for(int j = 0; j < N / 2; j++){
                M5_1[i * N/2 + j] = matB[i * N + j + offset];
            }
		}
		matrix_multiplication_strassen(&M5_0[0], &M5_1[0], &M5[0], M / 2, N / 2, K / 2);

		delete []M5_0;
		delete []M5_1;
	}

	//M6 = (A21-A11)*(B11+B12)
	float* M6 = new float[(M/2) * (N/2) * sizeof(float)];
	{
		//M6_0 = (A21-A11)
		float* M6_0 = new float[(M/2) * (K/2) * sizeof(float)];
		offset = K * M / 2;
		for (int i = 0; i < M / 2; i++)
		{
			for (int j = 0; j < K/2; j++)
			{
				const int baseIdx = i*K + j;
				M6_0[i*K/2+j] = matA[baseIdx + offset] - matA[baseIdx];
			}
		}
		//M6_1 = (B11+B12)
		float* M6_1 = new float[(K/2) * (N/2) * sizeof(float)];
		offset = N / 2;
		for (int i = 0; i < K / 2; i++)
		{
			for (int j = 0; j < N/2; j++)
			{
				const int baseIdx = i*N + j;
				M6_1[i*N/2+j] = matB[baseIdx] + matB[baseIdx + offset];
			}
		}
		matrix_multiplication_strassen(&M6_0[0], &M6_1[0], &M6[0], M / 2, N / 2, K / 2);

		delete []M6_0;
		delete []M6_1;         
	}

	//M7 = (A12-A22)*(B21+B22)
	float* M7 = new float[(M/2) * (N/2) * sizeof(float)];
	{
		//M7_0 = (A12-A22)
		float* M7_0 = new float[(M/2) * (K/2) * sizeof(float)];
		offset = M*K / 2;
		for (int i = 0; i < M / 2; i++)
		{
			for (int j = K/2; j < K; j++)
			{
				const int baseIdx = i*K + j;
				M7_0[i*K / 2 + j - K / 2] = matA[baseIdx] - matA[baseIdx + offset];
			}
		}
		//M7_1 = (B21+B22)
		float* M7_1 = new float[(K/2) * (N/2) * sizeof(float)];
		offset = N / 2;
		for (int i = K/2; i < K; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				const int baseIdx = i*N + j;
				M7_1[(i-K/2)*N / 2 + j] = matB[baseIdx] + matB[baseIdx + offset];
			}
		}
		matrix_multiplication_strassen(&M7_0[0], &M7_1[0], &M7[0], M / 2, N / 2, K / 2);

		delete []M7_0;
		delete []M7_1;         
	}

	for (int i = 0; i < M / 2;i++)
	{
		for (int j = 0; j < N / 2;j++)
		{
			const int idx = i*N / 2 + j;
			//C11 = M1+M4-M5+M7
			result[i*N + j] = M1[idx] + M4[idx] - M5[idx] + M7[idx];
			//C12 = M3+M5
			result[i*N + j + N/2] = M3[idx] + M5[idx];
			//C21 = M2+M4
			result[(i+M/2)*N + j] = M2[idx] + M4[idx];
			//C22 = M1-M2+M3+M6
			result[(i+M/2)*N + j + N/2] = M1[idx] - M2[idx] + M3[idx] + M6[idx];
		}
	}
	delete []M1;           
	delete []M2;           
	delete []M3;           
	delete []M4;           
	delete []M5;           
	delete []M6;           
	delete []M7;           
}





static int mm_test(int M, int N, int K, int size_limit, int max_value, int iteration){
    unsigned seed = time(0);
    srand(seed);
    clock_t start,end;
	static const std::size_t max_size = 1000000;

	float buf_norm[max_size];
	float buf_strasson[max_size];

	int cnt=0;
    for(int i = 0; i < 100; i++){

		M = rand() % size_limit;
		N = rand() % size_limit;
		K = rand() % size_limit;
	

		float* mA = new float[ M * K * sizeof(float)];
		float* mB = new float[ K * N * sizeof(float)];

		float *result_strasson = new (buf_strasson)float[M*N];
		float *result_normal = new (buf_norm)float[M*N];

        
		for(int j = 0; j < M*K; j++){
            mA[j] = rand() % max_value;
        }
        for(int j = 0; j < K*N; j++){
            mB[j] = rand() % max_value;
        }
        
		start = clock();

		//cout<< "M:" <<M<<"  N:"<<N<<"  K:"<<K <<endl;
        matrix_multiplication_strassen(mA, mB, result_strasson, M, N, K);
        end = clock();
        double endtime = (double) (end-start)/CLOCKS_PER_SEC;
		//cout<<"Strassen:" <<i<<"  time"<<endtime*1000<<" ms"<<endl;

		double strsn = endtime;
        start = clock();
        matrix_multiplication_normal(mA, mB, result_normal, M, N, K);
        end = clock();
        endtime = (double) (end-start)/CLOCKS_PER_SEC;
		//cout<<"Normal:" <<i<<"  time"<<endtime*1000<<" ms"<<endl;

		if(strsn < endtime){
			//cout<<"strassen win "<<strsn*1000<<" ms"<<endtime*1000<<" ms"<<endl;
			cnt++;
		}else{
			//cout<<"strassen lose "<<strsn*1000<<" ms"<<endtime*1000<<" ms"<<endl;
		}


        // for(int j = 0; j < M*N; j++){
        //     if(result_strasson[j] != result_normal[j] || result_strasson[j] != result_normal[j]){
        //         printf("========A========\n");
        //         mPrint(mA, M, K);
        //         printf("========B========\n");
        //         mPrint(mB, K, N);
        //         printf("========Strassen========\n");
        //         mPrint(result_strasson, M, N);
        //         printf("========Noraml way========\n");
        //         mPrint(result_normal, M, N);                
        //     }
        // }
        // cout<<" "<<endl;
    }
	cout<<"counts of Strasson algorithm's win:"<<size_limit<<": "<<cnt<<endl;
}

int main(){;
    int M, N, K, size_limit,max_value, iteration;
	iteration = 100;
    max_value = 100;
	int cnt_arr[20];
	int i=0;
	for(int size_limit=100;size_limit<1001;size_limit+=50){
    	cnt_arr[i++]=mm_test(M, N, K,size_limit, max_value, iteration);
	}
	return 0;
}
