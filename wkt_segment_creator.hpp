/**@brief ogc标准下wkt格式的segment类型构造类头文件
@author felix
@data 2016-09-01
@note segment是linestring的一个特殊情况，是只有两个点的情况
*/
#ifndef WKT_SEGMENT_CREATOR_HEAD
#define WKT_SEGMENT_CREATOR_HEAD
#include "geom_base_creator.hpp"
#include "wkt_segment_param.hpp"

namespace ogc_wkt
{
	template<typename T>
	class segment_creator:public geom_base_creator
	{
	public:
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			segment_param<T>* st_param = ( segment_param<T>* ) param;
			if ( NULL == st_param )
			{
				return "";
			}

			typedef geom::model::d2::point_xy<T> point_xy_type;
			geom::model::segment<point_xy_type> segment(geom::make<point_xy_type>(st_param->get_begin_x(), 
				st_param->get_begin_y()),geom::make<point_xy_type>(st_param->get_end_x(), st_param->get_end_y()));

			std::ostringstream  ss;
			ss << boost::geometry::wkt(segment);
			ss.flush();
			return ss.str();
		}
	};
}

#endif //WKT_SEGMENT_CREATOR_HEAD
