/**@brief ogc标准下wkt格式的geom类型构造工厂类实现文件
@author felix
@data 2016-09-01
*/
#include "wkt_geom_factory.h"
#include "wkt_geom_common_public.h"
#include "wkt_point_creator.h"
#include "wkt_point_xy_creator.h"
#include "wkt_polygon_creator.hpp"
#include "wkt_linestring_creator.hpp"
#include "wkt_segment_creator.hpp"
#include "wkt_ring_creator.hpp"
#include "wkt_multi_point_creator.hpp"
#include "wkt_multi_linestring_creator.hpp"
#include "wkt_multi_polygon_creator.hpp"

namespace ogc_wkt
{

	wkt_geom_factory::wkt_geom_factory(void)
	{
		init_factory();

	}

	wkt_geom_factory::~wkt_geom_factory(void)
	{
		for ( int index = 0; index<GEOM_MAX; ++index )
		{
			AUTO_DELETE(creator_[index]);
		}
	}

	void wkt_geom_factory::init_factory()
	{
		creator_.resize(GEOM_MAX);
		for ( int index = 0; index<GEOM_MAX; ++index )
		{
			creator_[index] = NULL;
		}
	}

	geom_base_creator* wkt_geom_factory::get_object_link_geom(GEOM_TYPE type)
	{
		switch ( type )
		{
		case BOX:
			break;
		case POINT:
			return point_creator();
		case POINT_XY:
			return point_xy_creator();
		case LINESTRING:
			return linestring_geom_creator();
		case POLYGON:
			return polygon_geom_creator();
		case SEGMENT:
			return segment_geom_creator();
		case RING:
			return ring_geom_creator();
		case MULTI_LINESTRING:
			break;
		case MULTI_POINT:
			return multi_point_geom_creator();
		case MULTI_POLYGON:
			break;
		default:
			break;
		}

		return NULL;
	}

	geom_base_creator* wkt_geom_factory::point_creator()
	{
		AUTO_DELETE(creator_[GEOM_POINT]);
		creator_[GEOM_POINT] = new wkt_point_creator;
		return creator_[GEOM_POINT];
	}

	geom_base_creator* wkt_geom_factory::point_xy_creator()
	{
		AUTO_DELETE(creator_[GEOM_POINT_XY]);
		creator_[GEOM_POINT_XY] = new wkt_point_xy_creator<double>;
		return creator_[GEOM_POINT_XY];
	}

	geom_base_creator* wkt_geom_factory::polygon_geom_creator()
	{
		AUTO_DELETE(creator_[GEOM_POLYGON]);
		creator_[GEOM_POLYGON] = new polygon_creator<double>;
		return creator_[GEOM_POLYGON];
	}

	geom_base_creator* wkt_geom_factory::linestring_geom_creator()
	{
		AUTO_DELETE(creator_[GEOM_LINESTRING]);
		creator_[GEOM_LINESTRING] = new linestring_creator<double>;
		return creator_[GEOM_LINESTRING];
	}

	geom_base_creator* wkt_geom_factory::segment_geom_creator()
	{
		AUTO_DELETE(creator_[GEOM_SEGMENT]);
		creator_[GEOM_SEGMENT] = new segment_creator<double>;
		return creator_[GEOM_SEGMENT];
	}

	geom_base_creator* wkt_geom_factory::ring_geom_creator()
	{
		AUTO_DELETE(creator_[GEOM_RING]);
		creator_[GEOM_RING] = new ring_creator<double>;
		return creator_[GEOM_RING];
	}

	geom_base_creator* wkt_geom_factory::multi_point_geom_creator()
	{
		AUTO_DELETE(creator_[GEOM_MULTI_POINT]);
		creator_[GEOM_MULTI_POINT] = new wkt_multi_point_creator<double>;
		return creator_[GEOM_MULTI_POINT];
	}

	geom_base_creator* wkt_geom_factory::multi_polygon_geom_creator()
	{
		AUTO_DELETE(creator_[GEOM_MULTI_POLYGON]);
		creator_[GEOM_MULTI_POLYGON] = new wkt_multi_polygon_creator<double>;
		return creator_[GEOM_MULTI_POLYGON];
	}

	inline geom_base_creator* wkt_geom_factory::multi_linestring_geom_creator()
	{
		AUTO_DELETE(creator_[GEOM_MULTI_LINESTRING]);
		creator_[GEOM_MULTI_LINESTRING] = new wkt_multi_linestring_creator<double>;
		return creator_[GEOM_MULTI_LINESTRING];
	}
}
