#ifndef LMOTION_HPP
#define LMOTION_HPP 1
#include "../point_motion.hpp"
#include "../interpolations/LinearGaussImproved.hpp"
#include "../../common/equation_of_state.hpp"
#include "../edge_velocity_calculator.hpp"

class LMotion : public PointMotion
{
private:
	LinearGaussImproved const& interp_;
	EquationOfState const& eos_;
	EdgeVelocityCalculator const& evc_;
public: 
	LMotion(LinearGaussImproved const& interp, EquationOfState const& eos,EdgeVelocityCalculator const& evc);
	
	vector<Vector2D> operator()(const Tessellation& tess, const vector<ComputationalCell>& cells,
	double time, TracerStickerNames const& tracerstickernames) const;

	vector<Vector2D> ApplyFix(Tessellation const& tess, vector<ComputationalCell> const& cells, double time,
	double dt, vector<Vector2D> const& velocities, TracerStickerNames const& tracerstickernames)const;
};
#endif //LMOTION_HPP