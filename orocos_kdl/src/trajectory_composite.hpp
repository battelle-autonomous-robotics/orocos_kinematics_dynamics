/*****************************************************************************
 *  \author
 *  	Erwin Aertbelien, Div. PMA, Dep. of Mech. Eng., K.U.Leuven
 *
 *  \version
 *		LRL V0.2
 *
 *	\par History
 *		- $log$
 *
 *	\par Release
 *		$Id: trajectory_composite.h 22 2004-09-21 08:58:54Z eaertbellocal $
 *		$Name:  $
 ****************************************************************************/


#ifndef TRAJECTORY_COMPOSITE_H
#define TRAJECTORY_COMPOSITE_H

#include "kdlapi.hpp"
#include "trajectory.hpp"
#include "path_composite.hpp"
#include <vector>



namespace KDL {
  /**
   * Trajectory_Composite implements a trajectory that is composed
   * of underlying trajectoria.  Call Add to add a trajectory
   * @ingroup Motion
   */
class Trajectory_Composite: public Trajectory
	{
		typedef std::vector<Trajectory*> VectorTraj;
		typedef std::vector<double>         VectorDouble;
		VectorTraj vt;      // contains the element Trajectories
		VectorDouble  vd;      // contains end time for each Trajectory
		double duration;    // total duration of the composed
				    // Trajectory

	public:
		KDL_DLLAPI Trajectory_Composite();
		// Constructs an empty composite

		KDL_DLLAPI virtual double Duration() const;
		KDL_DLLAPI virtual Frame Pos(double time) const;
		KDL_DLLAPI virtual Twist Vel(double time) const;
		KDL_DLLAPI virtual Twist Acc(double time) const;

		KDL_DLLAPI virtual void Add(Trajectory* elem);
		// Adds trajectory <elem> to the end of the sequence.

		KDL_DLLAPI virtual void Destroy();
		KDL_DLLAPI virtual void Write(std::ostream& os) const;
		KDL_DLLAPI virtual Trajectory* Clone() const;

		KDL_DLLAPI virtual ~Trajectory_Composite();
	};


}

#endif
