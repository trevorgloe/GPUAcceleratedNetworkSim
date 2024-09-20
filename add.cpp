#include <iostream>
#include <math.h>

float e_taylor(float x, int deg);
int factorial(int n);

// function to add the elements of two arrays
void add(int n, float *x, float *y)
{
  for (int i = 0; i < n; i++)
      y[i] = e_taylor(y[i], 20);
}

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

int factorial(int n){
  int ans = 1;
  for (int i = n; i > 0; i--){
    ans = ans * i;
  }
  return ans;
}

int main(void)
{
  int N = 1<<20; // 1M elements

  float *x = new float[N];
  float *y = new float[N];

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  // Run kernel on 1M elements on the CPU
  add(N, x, y);

  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-7.389f));
  std::cout << "Max error: " << maxError << std::endl;

  // Free memory
  delete [] x;
  delete [] y;

  return 0;
}