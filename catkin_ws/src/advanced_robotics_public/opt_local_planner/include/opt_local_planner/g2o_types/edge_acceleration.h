/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2016,
 *  TU Dortmund - Institute of Control Theory and Systems Engineering.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the institute nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 * 
 * Notes:
 * The following class is derived from a class defined by the
 * g2o-framework. g2o is licensed under the terms of the BSD License.
 * Refer to the base class source for detailed licensing information.
 *
 * Author: Christoph Rösmann
 *********************************************************************/

#ifndef EDGE_ACCELERATION_H_
#define EDGE_ACCELERATION_H_

#include <opt_local_planner/g2o_types/vertex_pose.h>
#include <opt_local_planner/g2o_types/vertex_timediff.h>
#include <opt_local_planner/g2o_types/penalties.h>
#include <opt_local_planner/g2o_types/base_teb_edges.h>

#include <geometry_msgs/Twist.h>



namespace opt_local_planner
{

/**
 * @class EdgeAcceleration
 * @brief Edge defining the cost function for limiting the translational and rotational acceleration.
 * 
 * The edge depends on five vertices \f$ \mathbf{s}_i, \mathbf{s}_{ip1}, \mathbf{s}_{ip2}, \Delta T_i, \Delta T_{ip1} \f$ and minimizes:
 * \f$ \min \textrm{penaltyInterval}( [a, omegadot } ]^T ) \cdot weight \f$. \n
 * \e a is calculated using the difference quotient (twice) and the position parts of all three poses \n
 * \e omegadot is calculated using the difference quotient of the yaw angles followed by a normalization to [-pi, pi]. \n 
 * \e weight can be set using setInformation() \n
 * \e penaltyInterval denotes the penalty function, see penaltyBoundToInterval() \n
 * The dimension of the error / cost vector is 2: the first component represents the translational acceleration and
 * the second one the rotational acceleration.
 */    
class EdgeAcceleration : public BaseTebMultiEdge<2, double>
{
public:
  double acc_lim_x_;
  double acc_lim_theta_;
  double penalty_epsilon_;
  /**
   * @brief Construct edge.
   */ 
  EdgeAcceleration(double acc_lim_x = 1.0, double acc_lim_theta = 1.0, double penalty_epsilon = 0.1) : 
  acc_lim_x_(acc_lim_x), acc_lim_theta_(acc_lim_theta), penalty_epsilon_(penalty_epsilon)
  {
    this->resize(5);
  }
    
  /**
   * @brief Actual cost function
   */   
  void computeError()
  {
    const VertexPose* pose1 = static_cast<const VertexPose*>(_vertices[0]);
    const VertexPose* pose2 = static_cast<const VertexPose*>(_vertices[1]);
    const VertexPose* pose3 = static_cast<const VertexPose*>(_vertices[2]);
    const VertexTimeDiff* dt1 = static_cast<const VertexTimeDiff*>(_vertices[3]);
    const VertexTimeDiff* dt2 = static_cast<const VertexTimeDiff*>(_vertices[4]);

    // ------------------------------------------------------------------------
    // TODO
    // Define the cost function for the linear and angular acceleration 
    // For the sake of clarity: Three consecutive pose configurations are to be substituted by their two related velocities
    // Hint: EdgeAccelerationStart::computeError() is already implemented further down as orientation
   

    _error[0] = 0; // TODO: set the translational acceleration Error. use penaltyBoundToInterval() for the error assignment
    
      
    _error[1] = 0; // TODO: Set the rotational acceleration error. use penaltyBoundToInterval() for the error assignment

    
    ROS_ASSERT_MSG(std::isfinite(_error[0]), "EdgeAcceleration::computeError() translational: _error[0]=%f\n",_error[0]);
    ROS_ASSERT_MSG(std::isfinite(_error[1]), "EdgeAcceleration::computeError() rotational: _error[1]=%f\n",_error[1]);
  }


      
public: 
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
   
};
    
    
/**
 * @class EdgeAccelerationStart
 * @brief Edge defining the cost function for limiting the translational and rotational acceleration at the beginning of the trajectory.
 *
 * The edge depends on three vertices \f$ \mathbf{s}_i, \mathbf{s}_{ip1}, \Delta T_i \f$, an initial velocity defined by setInitialVelocity()
 * and minimizes: \n
 * \f$ \min \textrm{penaltyInterval}( [a, omegadot ]^T ) \cdot weight \f$. \n
 * \e a is calculated using the difference quotient (twice) and the position parts of the poses. \n
 * \e omegadot is calculated using the difference quotient of the yaw angles followed by a normalization to [-pi, pi].  \n
 * \e weight can be set using setInformation(). \n
 * \e penaltyInterval denotes the penalty function, see penaltyBoundToInterval(). \n
 * The dimension of the error / cost vector is 2: the first component represents the translational acceleration and
 * the second one the rotational acceleration.
 * @see TebOptimalPlanner::AddEdgesAcceleration
 * @see EdgeAcceleration
 * @see EdgeAccelerationGoal
 * @remarks Do not forget to call setTebConfig()
 * @remarks Refer to EdgeAccelerationGoal() for defining boundary values at the end of the trajectory!
 */      
class EdgeAccelerationStart : public BaseTebMultiEdge<2, const geometry_msgs::Twist*>
{
public:
  double acc_lim_x_;
  double acc_lim_theta_;
  double penalty_epsilon_;
  /**
   * @brief Construct edge.
   */	  
  EdgeAccelerationStart(double acc_lim_x = 1.0, double acc_lim_theta = 1.0, double penalty_epsilon = 0.1) : 
  acc_lim_x_(acc_lim_x), acc_lim_theta_(acc_lim_theta), penalty_epsilon_(penalty_epsilon)
  {
    _measurement = NULL;
    this->resize(3);
  }
  
  
  /**
   * @brief Actual cost function
   */   
  void computeError()
  {
    const VertexPose* pose1 = static_cast<const VertexPose*>(_vertices[0]);
    const VertexPose* pose2 = static_cast<const VertexPose*>(_vertices[1]);
    const VertexTimeDiff* dt = static_cast<const VertexTimeDiff*>(_vertices[2]);

    // VELOCITY & ACCELERATION
    const Eigen::Vector2d diff = pose2->position() - pose1->position();
    double dist = diff.norm();
    const double angle_diff = g2o::normalize_theta(pose2->theta() - pose1->theta());
    
    const double vel1 = _measurement->linear.x;
    double vel2 = dist / dt->dt();

    // consider directions
    vel2 *= fast_sigmoid( 100*(diff.x()*cos(pose1->theta()) + diff.y()*sin(pose1->theta())) ); 
    
    const double acc_lin  = (vel2 - vel1) / dt->dt();
    
    _error[0] = penaltyBoundToInterval(acc_lin, acc_lim_x_, penalty_epsilon_);
    
    // ANGULAR ACCELERATION
    const double omega1 = _measurement->angular.z;
    const double omega2 = angle_diff / dt->dt();
    const double acc_rot  = (omega2 - omega1) / dt->dt();
      
    _error[1] = penaltyBoundToInterval(acc_rot, acc_lim_theta_, penalty_epsilon_);

    ROS_ASSERT_MSG(std::isfinite(_error[0]), "EdgeAccelerationStart::computeError() translational: _error[0]=%f\n",_error[0]);
    ROS_ASSERT_MSG(std::isfinite(_error[1]), "EdgeAccelerationStart::computeError() rotational: _error[1]=%f\n",_error[1]);
  }
  
  /**
   * @brief Set the initial velocity that is taken into account for calculating the acceleration
   * @param vel_start twist message containing the translational and rotational velocity
   */    
  void setInitialVelocity(const geometry_msgs::Twist& vel_start)
  {
    _measurement = &vel_start;
  }
  
public:       
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};    
    
    
    

/**
 * @class EdgeAccelerationGoal
 * @brief Edge defining the cost function for limiting the translational and rotational acceleration at the end of the trajectory.
 * 
 * The edge depends on three vertices \f$ \mathbf{s}_i, \mathbf{s}_{ip1}, \Delta T_i \f$, an initial velocity defined by setGoalVelocity()
 * and minimizes: \n
 * \f$ \min \textrm{penaltyInterval}( [a, omegadot ]^T ) \cdot weight \f$. \n
 * \e a is calculated using the difference quotient (twice) and the position parts of the poses \n
 * \e omegadot is calculated using the difference quotient of the yaw angles followed by a normalization to [-pi, pi].  \n
 * \e weight can be set using setInformation() \n
 * \e penaltyInterval denotes the penalty function, see penaltyBoundToInterval() \n
 * The dimension of the error / cost vector is 2: the first component represents the translational acceleration and
 * the second one the rotational acceleration.
 * @see TebOptimalPlanner::AddEdgesAcceleration
 * @see EdgeAcceleration
 * @see EdgeAccelerationStart
 * @remarks Do not forget to call setTebConfig()
 * @remarks Refer to EdgeAccelerationStart() for defining boundary (initial) values at the end of the trajectory
 */  
class EdgeAccelerationGoal : public BaseTebMultiEdge<2, const geometry_msgs::Twist*>
{
public:
  double acc_lim_x_;
  double acc_lim_theta_;
  double penalty_epsilon_;
  /**
   * @brief Construct edge.
   */  
  EdgeAccelerationGoal(double acc_lim_x = 1.0, double acc_lim_theta = 1.0, double penalty_epsilon = 0.1) : 
  acc_lim_x_(acc_lim_x), acc_lim_theta_(acc_lim_theta), penalty_epsilon_(penalty_epsilon)
  {
    _measurement = NULL;
    this->resize(3);
  }
  

  /**
   * @brief Actual cost function
   */ 
  void computeError()
  {
    const VertexPose* pose_pre_goal = static_cast<const VertexPose*>(_vertices[0]);
    const VertexPose* pose_goal = static_cast<const VertexPose*>(_vertices[1]);
    const VertexTimeDiff* dt = static_cast<const VertexTimeDiff*>(_vertices[2]);

    // VELOCITY & ACCELERATION

    const Eigen::Vector2d diff = pose_goal->position() - pose_pre_goal->position();  
    double dist = diff.norm();
    const double angle_diff = g2o::normalize_theta(pose_goal->theta() - pose_pre_goal->theta());
    
    double vel1 = dist / dt->dt();
    const double vel2 = _measurement->linear.x;
    
    // consider directions
    vel1 *= fast_sigmoid( 100*(diff.x()*cos(pose_pre_goal->theta()) + diff.y()*sin(pose_pre_goal->theta())) ); 
    
    const double acc_lin  = (vel2 - vel1) / dt->dt();

    _error[0] = penaltyBoundToInterval(acc_lin, acc_lim_x_, penalty_epsilon_);
    
    // ANGULAR ACCELERATION
    const double omega1 = angle_diff / dt->dt();
    const double omega2 = _measurement->angular.z;
    const double acc_rot  = (omega2 - omega1) / dt->dt();
      
    _error[1] = penaltyBoundToInterval(acc_rot, acc_lim_theta_, penalty_epsilon_);

    ROS_ASSERT_MSG(std::isfinite(_error[0]), "EdgeAccelerationGoal::computeError() translational: _error[0]=%f\n",_error[0]);
    ROS_ASSERT_MSG(std::isfinite(_error[1]), "EdgeAccelerationGoal::computeError() rotational: _error[1]=%f\n",_error[1]);
  }
    
  /**
   * @brief Set the goal / final velocity that is taken into account for calculating the acceleration
   * @param vel_goal twist message containing the translational and rotational velocity
   */    
  void setGoalVelocity(const geometry_msgs::Twist& vel_goal)
  {
    _measurement = &vel_goal;
  }
  
public: 
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
}; 
    

    



}; // end namespace

#endif /* EDGE_ACCELERATION_H_ */
