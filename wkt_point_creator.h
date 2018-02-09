
#pragma once
#include "geom_base_creator.hpp"
namespace ogc_wkt
{
	class wkt_point_creator : public geom_base_creator
	{
	public:
		wkt_point_creator(void);
		~wkt_point_creator(void);
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			return "";
		}
	};

}

