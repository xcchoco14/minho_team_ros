#ifndef RSUPSTRIKER_H
#define RSUPSTRIKER_H

#include "role.h"
#include "mtmsl_common/obstacle.h"
using mtmsl_common::obstacle;

class RoleSupStriker : public Role
{
  
public:
   RoleSupStriker(); // Constructor
   ~RoleSupStriker();

   virtual void determineAction();
   virtual void computeAction(aiInfo *ai);
   virtual std::string getActiveRoleName();
   virtual void setField(fieldDimensions fd);
   virtual void setRosNodeHandle(ros::NodeHandle *parent, std::string topic_base);
private:
   float goal_line_x;
   float side_line_y;
   float small_area_x,small_area_y;
   float big_area_x, big_area_y, penalty_x;
   float center_circle_radius;
   bool passed_after_engage;
   bool ball_position_locked;
   vec2d kick_spot;
};

#endif
