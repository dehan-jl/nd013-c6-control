/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi,
               double output_lim_mini) {
  /**
   * DONE: Initialize PID coefficients (and errors, if needed)
   **/

  // Initialize errors
  prev_cte = 0.0;
  diff_cte = 0.0;
  int_cte = 0.0;

  // Initialize coefficients
  tau_p = Kpi;
  tau_i = Kii;
  tau_d = Kdi;

  // Initialize output limits
  output_lim_max = output_lim_maxi;
  output_lim_min = output_lim_mini;

  // Initialize delta time
  delta_time = 0.0;
}

void PID::UpdateError(double cte) {
  /**
   * DONE: Update PID errors based on cte.
   **/

  if (abs(delta_time) < 1.0e-6) return;  // delta time is too small

  diff_cte = (cte - prev_cte) / delta_time;
  int_cte += cte * delta_time;
  prev_cte = cte;
}

double PID::TotalError() {
  /**
   * DONE: Calculate and return the total error
   * The code should return a value in the interval [output_lim_mini,
   * output_lim_maxi]
   */
  double control = -tau_p * prev_cte - tau_d * diff_cte - tau_i * int_cte;
  if (control > output_lim_max) {
    control = output_lim_max;
  } else if (control < output_lim_min) {
    control = output_lim_min;
  }
  return control;
}

double PID::UpdateDeltaTime(double new_delta_time) {
  /**
   * DONE: Update the delta time with new value
   */
  delta_time = new_delta_time;
  return delta_time;
}