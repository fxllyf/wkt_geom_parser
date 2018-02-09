/**@brief ogc标准下wkt格式的geom类型构造工厂类头文件
@author felix
@data 2016-09-01
*/
#pragma once
#include <vector>
#include "geom_base_creator.hpp"
namespace ogc_wkt
{

	enum GEOM_TYPE
	{
		BOX = 0,
		POINT,
		POINT_XY,
		LINESTRING,
		POLYGON,
		SEGMENT,
		RING,
		MULTI_LINESTRING,
		MULTI_POINT,
		MULTI_POLYGON,
	};

	class wkt_geom_factory
	{
	public:
		wkt_geom_factory(void);

		void init_factory();

		~wkt_geom_factory(void);
		geom_base_creator* get_object_link_geom(GEOM_TYPE type);

	protected:
		inline geom_base_creator* point_creator();
		inline geom_base_creator* point_xy_creator();
		inline geom_base_creator* polygon_geom_creator();
		inline geom_base_creator* linestring_geom_creator();
		inline geom_base_creator* segment_geom_creator();
		inline geom_base_creator* ring_geom_creator();
		inline geom_base_creator* multi_point_geom_creator();
		inline geom_base_creator* multi_polygon_geom_creator();
		inline geom_base_creator* multi_linestring_geom_creator();
	private:
		std::vector<geom_base_creator*> creator_;
		
	};

}
