/*
 * @file solid_particle.h 
 * @Brief the particle used to represent solid, carry deformation gradient information
 * @author Fei Zhu
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#ifndef PHYSIKA_DYNAMICS_PARTICLES_SOLID_PARTICLE_H_
#define PHYSIKA_DYNAMICS_PARTICLES_SOLID_PARTICLE_H_

#include "Physika_Dynamics/Particles/particle.h"
#include "Physika_Core/Matrices/matrix_2x2.h"
#include "Physika_Core/Matrices/matrix_3x3.h"

namespace Physika{

template <typename Scalar, int Dim>
class SolidParticle: public Particle<Scalar,Dim>
{
public:
    SolidParticle();
    SolidParticle(const Vector<Scalar,Dim> &pos, const Vector<Scalar,Dim> &vel, Scalar mass, Scalar vol); //F set to identity
    SolidParticle(const Vector<Scalar,Dim> &pos, const Vector<Scalar,Dim> &vel, Scalar mass, Scalar vol, const SquareMatrix<Scalar,Dim> &deform_grad);
    SolidParticle(const SolidParticle<Scalar,Dim> &particle);
    virtual ~SolidParticle(); 
    virtual SolidParticle<Scalar,Dim>* clone() const;
    SolidParticle<Scalar,Dim>& operator= (const SolidParticle<Scalar,Dim> &particle);
    const SquareMatrix<Scalar,Dim>& deformationGradient() const;
    void setDeformationGradient(const SquareMatrix<Scalar,Dim> &F);
protected:
    SquareMatrix<Scalar,Dim> F_;
};

}  //end of namespace Physika

#endif //PHYSIKA_DYNAMICS_PARTICLES_SOLID_PARTICLE_H_
