
#ifndef POINT_XY_GEOM_PARAM_HEAD 
#define POINT_XY_GEOM_PARAM_HEAD
#include "wkt_geom_param_base.hpp"

namespace ogc_wkt
{
	template<typename T = double>
	struct point_xy_param:public geom_param_base
	{
		point_xy_param(T x, T y)
		{
			x_ = x;
			y_ = y;
		}
		inline T get_x(){ return x_;}
		inline T get_y(){ return y_;}

		inline void set_x(T x){ x_ = x;}
		inline void set_y(T y){y_ = y;}
	private:
		T x_;
		T y_;
	};
}

#endif//POINT_XY_GEOM_PARAM_HEAD
