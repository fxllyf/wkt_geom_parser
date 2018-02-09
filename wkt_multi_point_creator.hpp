/**@brief ogc标准下wkt格式的multi_point类型构造工厂类头文件
@author felix
@data 2016-09-01
*/
#ifndef WKT_MULTI_POINT_HEAD
#define WKT_MULTI_POINT_HEAD

#include "geom_base_creator.hpp"
#include "wkt_multi_point_param.hpp"
#include <sstream>
namespace ogc_wkt
{
	template< typename T = double>
	class wkt_multi_point_creator :public geom_base_creator
	{
	public:
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			multi_point_param<T>* mp_param = ( multi_point_param<T>* ) param;
			if ( NULL == mp_param )
			{
				return "";
			}

			typedef geom::model::d2::point_xy<T> point_xy_type;
			geom::model::multi_point<point_xy_type> multi_point;
			geom_dataset<T> dataset = mp_param->get_data_set();

			std::vector<T> paramx = dataset.param_x;
			std::vector<T> paramy = dataset.param_y;
			int size = paramx.size();
			for ( int index = 0; index < size; index++ )
			{
				multi_point.push_back(geom::make<point_xy_type>(paramx[index], paramy[index]));
			}

			std::ostringstream  ss;
			ss << boost::geometry::wkt(multi_point);
			ss.flush();
			return ss.str();
		}
	};
}



#endif//WKT_MULTI_POINT_HEAD
