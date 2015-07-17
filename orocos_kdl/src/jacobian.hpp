// Copyright  (C)  2007  Ruben Smits <ruben dot smits at mech dot kuleuven dot be>

// Version: 1.0
// Author: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// Maintainer: Ruben Smits <ruben dot smits at mech dot kuleuven dot be>
// URL: http://www.orocos.org/kdl

// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef KDL_JACOBIAN_HPP
#define KDL_JACOBIAN_HPP

#include "kdlapi.hpp"
#include "frames.hpp"
#include <Eigen/Core>

namespace KDL
{
    // Equal is friend function, but default arguments for friends are forbidden (§8.3.6.4)
    class Jacobian;
    KDL_DLLAPI bool Equal(const Jacobian& a,const Jacobian& b,double eps=epsilon);


    class Jacobian
    {
    public:

        EIGEN_MAKE_ALIGNED_OPERATOR_NEW
        Eigen::Matrix<double,6,Eigen::Dynamic> data;

        KDL_DLLAPI Jacobian();
        KDL_DLLAPI explicit Jacobian(unsigned int nr_of_columns);
        KDL_DLLAPI Jacobian(const Jacobian& arg);

        ///Allocates memory for new size (can break realtime behavior)
        KDL_DLLAPI void resize(unsigned int newNrOfColumns);

        ///Allocates memory if size of this and argument is different
        KDL_DLLAPI Jacobian& operator=(const Jacobian& arg);

        KDL_DLLAPI bool operator ==(const Jacobian& arg)const;
        KDL_DLLAPI bool operator !=(const Jacobian& arg)const;
        
        KDL_DLLAPI friend bool Equal(const Jacobian& a,const Jacobian& b,double eps);
        

        KDL_DLLAPI ~Jacobian();

        KDL_DLLAPI double operator()(unsigned int i,unsigned int j)const;
        KDL_DLLAPI double& operator()(unsigned int i,unsigned int j);
        KDL_DLLAPI unsigned int rows()const;
        KDL_DLLAPI unsigned int columns()const;

        KDL_DLLAPI friend void SetToZero(Jacobian& jac);

        KDL_DLLAPI friend bool changeRefPoint(const Jacobian& src1, const Vector& base_AB, Jacobian& dest);
        KDL_DLLAPI friend bool changeBase(const Jacobian& src1, const Rotation& rot, Jacobian& dest);
        KDL_DLLAPI friend bool changeRefFrame(const Jacobian& src1,const Frame& frame, Jacobian& dest);

        KDL_DLLAPI Twist getColumn(unsigned int i) const;
        KDL_DLLAPI void setColumn(unsigned int i,const Twist& t);

        KDL_DLLAPI void changeRefPoint(const Vector& base_AB);
        KDL_DLLAPI void changeBase(const Rotation& rot);
        KDL_DLLAPI void changeRefFrame(const Frame& frame);


    };

    KDL_DLLAPI bool changeRefPoint(const Jacobian& src1, const Vector& base_AB, Jacobian& dest);
    KDL_DLLAPI bool changeBase(const Jacobian& src1, const Rotation& rot, Jacobian& dest);
    KDL_DLLAPI bool changeRefFrame(const Jacobian& src1,const Frame& frame, Jacobian& dest);


}

#endif
