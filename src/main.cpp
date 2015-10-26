#include <iostream>
#include "Gyroscope.h"
#include "Accelerometer.h"
#include "Kalman.h"

using namespace std;

int main()
{
  Gyroscope gyro(1);
  Accelerometer accel(2);
  
  float bias_prior = gyro.Calibrate(500);
  
  Kalman kalman_filter(90.0f, bias_prior, 0.01);

  for(int x = 0; x< 100000; x++) {
    float accel_pitch = Accelerometer::ComputePitchFast(accel.Read()) * 180 / M_PI;
  	float pitch = kalman_filter.getAngle(accel_pitch, gyro.Read());
  	cout << pitch << endl;
  	usleep(1000-1000.0/819.0);
  }

  return 0;
}
