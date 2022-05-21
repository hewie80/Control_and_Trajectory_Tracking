# Project: Control_and_Trajectory_Tracking
## Overview
Based on a given trajectory and a simulation environment, a PID controller is designed and tested its efficiency on the CARLA simulator used in the industry.
## Solution
A PID controller is implemented and integrated into the provided framework.  for throttle and steering control. Several fixes are added to the framework and simulation client to make the control smoother and more stable. Finally a short evaluation is provided of the controllers.
## Running
### Run Carla Simulator
Open new window
<br> *su - student // Will say permission denied, ignore and continue
<br> *cd /opt/carla-simulator/
<br> *SDL_VIDEODRIVER=offscreen ./CarlaUE4.sh -opengl
<br> Compile and Run the Controller
Open new window
<br> *cd nd013-c6-control-starter/project
<br> */install-ubuntu.sh
<br> *cd pid_controller/
<br> *rm -rf rpclib
<br> *git clone https://github.com/rpclib/rpclib.git
<br> *cmake .
<br> *make (This last command compiles your C++ code, run it after every change in your code)
### Testing
To test your installation run the following commands.
<br> *cd nd013-c6-control-starter/project
<br> *./run_main_pid.sh Go to desktop mode to see CARLA
## Project Comments
### Simulation Result
The screenshotshows the CARLA simulator after completeing the TODOs in “main.cpp”, “pid_controller.cpp” and “pid_controller.h”.
![85b03bbc-24fe-49a8-9401-fa6b2200ebfa-desktop](https://user-images.githubusercontent.com/99339837/169652903-d9fcef49-3511-43fc-b4c0-04217f9a27c2.jpeg)

### Question and Answer
<br> *Provide the plots in the report and explain the plots and describing what is plotted: the variables, the phenomenon shown.
<br> *What is the effect of the PID according to the plots, how each part of the PID affects the control command?
<br> *How would you design a way to automatically tune the PID parameters?
<br> *PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?
<br> *(Optional) What would you do to improve the PID controller?
###  Provide the plots in the report and explain the plots and describing what is plotted: the variables, the phenomenon shown.
<br> This plot shows the Error steering(blue) and steering output(orange). The PID controller tries to reduce the error. so Initially, you may found some oscillations. but the it becomes smaller and stable after some iterations. Unfortunatelly, it becomes high after about 225 iterations due to collistion with obstacles. so in this case more tuning may be helpful.
![PID Steer 22](https://user-images.githubusercontent.com/99339837/169652605-300deff9-1a1c-440d-82d0-5b8c70d3417b.jpg)
This plot shows the throttle (green) and brake output(orange) as well as the error throttle(blue). In the first 30 iterations, there are much oscillations. with intergral item works on compensation of error, it becomes stable and close. Proportional items casues an offset of error. The car run much smoother along the path.
![PID Throtte 22](https://user-images.githubusercontent.com/99339837/169652667-1f778ee8-da2c-4731-ae8d-7edb6527b484.jpg)

###  What is the effect of the PID according to the plots, how each part of the PID affects the control command?
Kp directly affected the error. High values results in a large change to close to desired path but make the car oscillated much. Low value maybe make the car run smoother but hard to close the track.
Ki means ingegral and it help to reduce the error to zero. It increases with iterations. High value will make the error smaller. when error is stable, ki is needed to delete error.
Kd is necessary for oscillations. This item is produced based on the error gradient not the error itself. so Kd will flatten the error into a horizontal line.

After tuning of each of parameters, the car can pass most of obastacles. but the trajectory is not perfect.so there is still potential to improve the PID controller.

### How would you design a way to automatically tune the PID parameters?
Frankly, it is very hard to tune the PID parameters manually. I put much time on this. To get the better parameters, I have to tune Kp,Ki,Kd one by one and wish to find a good result. But once I frozen, the parameters will not be changed. This is why I cannot find a number to guide the car in reality.so it is necessary to find a solution to tune the parameters automatically and solve problem in different cases.
TWIDDLE alogorithm is good way to automatically tune the PID parameters as I know until now. It can change the parameters for different cases. This is next direction what I need to study.

### PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?
Pros:
1. Not complex and easy to understand. 
2. Can be applied in many systems of car.e.g EPS.
Cons:
Due to intergra and differential, It is not friendly for non-linear change. Only similar or close to right value. 

### (Optional) What would you do to improve the PID controller?
I would try to use TWIDDLE alogrithem to improve the PID controller.
