/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kii, double Kdi, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
  this->kp=Kpi;
  this->ki=Kii;
  this->kd=Kdi;
  this->output_lim_max=output_lim_maxi;
  this->output_lim_min=output_lim_mini;
  this->pre_cte=0;
  this->sum_cte=0;
    
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
  //PID error=-kp*cte-kd*d(cte)/dt-ki*sigma(cte)
  if(abs(delta_time)<=0.00001)
    return;
  double P=kp*cte;
  double D=kd*(cte-pre_cte)/delta_time;
  sum_cte+=cte*delta_time;
  double I=ki*sum_cte;
  error=P+I+D;
  pre_cte=cte;
  
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
  double control=error;
  if(control<output_lim_min)
  {
    control=output_lim_min;
  }
  else if (control>output_lim_max)
  {
    control=output_lim_max;
  }
  else
  {
    return control;
  }
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
   delta_time = new_delta_time;
   return delta_time;
}