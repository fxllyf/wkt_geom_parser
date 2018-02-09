/**@brief ogc标准下wkt格式的polygon类型构造类头文件
@author felix
@data 2016-09-01
*/
#ifndef WKT_POLYGON_CREATOR_HEAD
#define WKT_POLYGON_CREATOR_HEAD
#include "geom_base_creator.hpp"
#include "polygon_geom_param.hpp"

namespace ogc_wkt
{
	template<typename T>
	class polygon_creator:public geom_base_creator
	{
	public:
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			polygon_param<T>* pygon_param = ( polygon_param<T>* ) param;
			if ( NULL == pygon_param )
			{
				return "";
			}

			typedef geom::model::d2::point_xy<T> point_xy_type;
			geom::model::polygon<point_xy_type> polygon;
			geom_dataset<T> dataset = pygon_param->get_data_set();
			
			std::vector<T> paramx = dataset.param_x;
			std::vector<T> paramy = dataset.param_y;
			int size = paramx.size();
			for ( int index = 0; index < size; index++ )
			{
				geom::append(geom::exterior_ring(polygon), geom::make<point_xy_type>(paramx[index], paramy[index]));

			}

			std::ostringstream  ss;
			ss << boost::geometry::wkt(polygon);
			ss.flush();
			return ss.str();
		}
	};
}

#endif//WKT_POLYGON_CREATOR_HEAD
