/**@brief ogc标准下wkt格式的linestring类型构造类头文件
@author felix
@data 2016-09-01
*/
#ifndef WKT_LINESTRING_CREATOR_HEAD
#define WKT_LINESTRING_CREATOR_HEAD
#include "geom_base_creator.hpp"
#include "wkt_linestring_param.hpp"

namespace ogc_wkt
{
	template<typename T>
	class linestring_creator:public geom_base_creator
	{
	public:
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			linestring_param<T>* ls_param = ( linestring_param<T>* ) param;
			if ( NULL == ls_param )
			{
				return "";
			}

			typedef geom::model::d2::point_xy<T> point_xy_type;
			geom::model::linestring<point_xy_type> linestring;
			geom_dataset<T> dataset = ls_param->get_data_set();

			std::vector<T> paramx = dataset.param_x;
			std::vector<T> paramy = dataset.param_y;
			int size = paramx.size();
			for ( int index = 0; index < size; index++ )
			{
				linestring.push_back(geom::make<point_xy_type>(paramx[index], paramy[index]));
			}

			std::ostringstream  ss;
			ss << boost::geometry::wkt(linestring);
			ss.flush();
			return ss.str();
		}
	};
}

#endif //WKT_LINESTRING_CREATOR_HEAD
