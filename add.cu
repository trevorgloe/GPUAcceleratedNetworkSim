#include <iostream>
#include <math.h>

__device__ float e_taylor(float x, int deg);
__device__ int factorial(int n);

// Kernel function to add the elements of two arrays
__global__
void add(int n, float *x, float *y)
{
  int index = blockIdx.x * blockDim.x + threadIdx.x;
  int stride = blockDim.x * gridDim.x;
  for (int i = index; i < n; i += stride)
    y[i] = e_taylor(y[i], 20);
}

__device__
float e_taylor(float x, int deg){
  float ans = 0.0f;
  for (int i = 0; i < deg; i ++){
    if (i==0){
      ans = ans + 1.0;
    } else {
      int n_fac = factorial(i);
      float denom = static_cast<float>(n_fac);
      ans = ans + pow(x, i) / denom;
      // printf("%f", ans);
      // printf("%f", denom);
    }
  }
  // printf("%f", ans);
  return ans;
}

__device__
int factorial(int n){
  int ans = 1;
  for (int i = n; i > 0; i--){
    ans = ans * i;
  }
  return ans;
}

int main(void)
{
  int N = 1<<20;
  float *x, *y;

  // Allocate Unified Memory – accessible from CPU or GPU
  cudaMallocManaged(&x, N*sizeof(float));
  cudaMallocManaged(&y, N*sizeof(float));

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  // Run kernel on 1M elements on the GPU
  int blockSize = 256;
  int numBlocks = std::ceil((N + blockSize - 1) / blockSize);
  add<<<numBlocks, blockSize>>>(N, x, y);

  // Wait for GPU to finish before accessing on host
  cudaDeviceSynchronize();

  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-7.389f));
  std::cout << "Max error: " << maxError << std::endl;

  // Free memory
  cudaFree(x);
  cudaFree(y);
  
  return 0;
}