#include "leg_control.h"
#include "kinematics.h"
#include <unistd.h>
#include <time.h>

void set_to_zero(void) {
    for(int i = 0; i < 4; i++){
        set_leg_pose(i,0,0,0);
    }
}

int main(int argc, char** argv){
    load_calibration(argv[1]);
    set_to_zero();
    sleep(1);
    struct timespec ts = {0, 100000000L};

    struct point front_legs = {125.0, -75.0, 0.0};
    struct pose leg_pose = {0,0,0};

    inv_leg_kin(&front_legs,&leg_pose);


    //right front leg
    set_leg_pose(front_right,
		    leg_pose.coxa_theta,
		    leg_pose.femur_theta,
		    leg_pose.tibia_theta);
  
    nanosleep(&ts, NULL);


    //left front leg
    set_leg_pose(front_left,
		    leg_pose.coxa_theta,
		    leg_pose.femur_theta,
		    leg_pose.tibia_theta);
  

    nanosleep(&ts, NULL);

    struct point back_legs = {125.0, 75.0, 0.0};
    inv_leg_kin(&back_legs,&leg_pose);
    
    //left rear leg
    set_leg_pose(back_left,
		    leg_pose.coxa_theta,
		    leg_pose.femur_theta,
		    leg_pose.tibia_theta);
  

    nanosleep(&ts, NULL);

    //right rear leg
    set_leg_pose(back_right,
		    leg_pose.coxa_theta,
		    leg_pose.femur_theta,
		    leg_pose.tibia_theta);
  

    nanosleep(&ts,NULL);

    
    front_legs.Z = -60.0;
    inv_leg_kin(&front_legs,&leg_pose);


    //right front leg
    set_leg_pose(front_right,
		    leg_pose.coxa_theta,
		    leg_pose.femur_theta,
		    leg_pose.tibia_theta);

    //left front leg
    set_leg_pose(front_left,
		    leg_pose.coxa_theta,
		    leg_pose.femur_theta,
		    leg_pose.tibia_theta);
  
    back_legs.Z =  -60.0;
    inv_leg_kin(&back_legs,&leg_pose);
    
    //left rear leg
    set_leg_pose(back_left,
		    leg_pose.coxa_theta,
		    leg_pose.femur_theta,
		    leg_pose.tibia_theta);
  


    //right rear leg
    set_leg_pose(back_right,
		    leg_pose.coxa_theta,
		    leg_pose.femur_theta,
		    leg_pose.tibia_theta);
  

   
}
