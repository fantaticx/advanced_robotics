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
#ifndef EDGE_OBSTACLE_H_
#define EDGE_OBSTACLE_H_

#include <opt_local_planner/obstacles.h>
#include <opt_local_planner/g2o_types/vertex_pose.h>
#include <opt_local_planner/g2o_types/base_teb_edges.h>
#include <opt_local_planner/g2o_types/penalties.h>



namespace opt_local_planner
{

/**
 * @class EdgeObstacle
 * @brief Edge defining the cost function for keeping a minimum distance from obstacles.
 * 
 * The edge depends on a single vertex \f$ \mathbf{s}_i \f$ and minimizes: \n
 * \f$ \min \textrm{penaltyBelow}( dist2point ) \cdot weight \f$. \n
 * \e dist2point denotes the minimum distance to the point obstacle. \n
 * \e weight can be set using setInformation(). \n
 * \e penaltyBelow denotes the penalty function, see penaltyBoundFromBelow() \n
 * @see TebOptimalPlanner::AddEdgesObstacles, TebOptimalPlanner::EdgeInflatedObstacle
 * @remarks Do not forget to call setTebConfig() and setObstacle()
 */     
class EdgeObstacle : public BaseTebUnaryEdge<1, const Obstacle*, VertexPose>
{
public:
  double min_obstacle_dist_;
  double penalty_epsilon_;
  double obstacle_cost_exponent_;
  /**
   * @brief Construct edge.
   */    
  EdgeObstacle(double min_obstacle_dist = 0.1, double penalty_epsilon = 0.1, double obstacle_cost_exponent = 1.0) : 
  min_obstacle_dist_(min_obstacle_dist) , penalty_epsilon_(penalty_epsilon), obstacle_cost_exponent_(obstacle_cost_exponent)
  {
    _measurement = NULL;
  }
 
  /**
   * @brief Actual cost function
   */    
  void computeError()
  {
    const VertexPose* vertex_pose = static_cast<const VertexPose*>(_vertices[0]);

    // ------------------------------------------------------------------------
    // TODO
    // compute the distance between obstacle_ and the pose and use this as your cost function
    

    // TODO: Add cost value as error. use penaltyBoundFromBelow() for the error assignment
    _error[0] = 0; 

    if (obstacle_cost_exponent_ != 1.0 && min_obstacle_dist_ > 0.0)
    {
      // Optional non-linear cost. Note the max cost (before weighting) is
      // the same as the straight line version and that all other costs are
      // below the straight line (for positive exponent), so it may be
      // necessary to increase weight_obstacle and/or the inflation_weight
      // when using larger exponents.
      _error[0] = min_obstacle_dist_ * std::pow(_error[0] / min_obstacle_dist_, obstacle_cost_exponent_);
    }

    ROS_ASSERT_MSG(std::isfinite(_error[0]), "EdgeObstacle::computeError() _error[0]=%f\n",_error[0]);
  }

  
  /**
   * @brief Set pointer to associated obstacle for the underlying cost function 
   * @param obstacle 2D position vector containing the position of the obstacle
   */ 
  void setObstacle(Obstacle* obstacle)
  {
    _measurement = obstacle;
    obstacle_ = obstacle;
  }
    

    
  /**
   * @brief Set all parameters at once
   * @param obstacle 2D position vector containing the position of the obstacle
   */ 
  void setParameters( Obstacle* obstacle)
  {
    _measurement = obstacle;
    obstacle_ = obstacle;
  }
  
protected:


  Obstacle* obstacle_;
  
public: 	
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

};
  
   

} // end namespace

#endif
