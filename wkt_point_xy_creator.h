
#pragma once

#include "geom_base_creator.hpp"
#include "point_xy_geom_param.hpp"
#include <sstream>
namespace ogc_wkt
{
	template< typename T = double>
	class wkt_point_xy_creator :public geom_base_creator
	{
	public:
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			point_xy_param<T>* point_param = ( point_xy_param<T>* ) param;
			if ( NULL == point_param )
			{
				return "";
			}

			point_type point = geom::make<point_type>(point_param->get_x(), point_param->get_y());
			std::ostringstream  ss;
			ss << boost::geometry::wkt(point);
			ss.flush();
			return ss.str();
		}
	};
}
