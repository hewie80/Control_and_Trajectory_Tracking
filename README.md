# Project: Control_and_Trajectory_Tracking
## Overview
Based on a given trajectory and a simulation environment, a PID controller is designed and tested its efficiency on the CARLA simulator used in the industry.
## Solution
A PID controller is implemented and integrated into the provided framework.  for throttle and steering control. Several fixes are added to the framework and simulation client to make the control smooth(er) and more stable. Finally a short evaluation is provided of the controllers.
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
