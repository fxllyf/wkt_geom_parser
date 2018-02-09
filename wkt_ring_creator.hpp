/**@brief ogc标准下wkt格式的ring类型构造类头文件
@author felix
@data 2016-09-01
*/
#ifndef WKT_RING_CREATOR_HEAD
#define WKT_RING_CREATOR_HEAD
#include "geom_base_creator.hpp"
#include "wkt_ring_param.hpp"

namespace ogc_wkt
{
	template<typename T>
	class ring_creator:public geom_base_creator
	{
	public:
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			ring_param<T>* ls_param = ( ring_param<T>* ) param;
			if ( NULL == ls_param )
			{
				return "";
			}

			typedef geom::model::d2::point_xy<T> point_xy_type;
			geom::model::ring<point_xy_type> ring;
			geom_dataset<T> dataset = ls_param->get_data_set();

			std::vector<T> paramx = dataset.param_x;
			std::vector<T> paramy = dataset.param_y;
			int size = paramx.size();
			for ( int index = 0; index < size; index++ )
			{
				ring.push_back(geom::make<point_xy_type>(paramx[index], paramy[index]));
			}

			std::ostringstream  ss;
			ss << boost::geometry::wkt(ring);
			ss.flush();
			return ss.str();
		}
	};
}

#endif //WKT_RING_CREATOR_HEAD
