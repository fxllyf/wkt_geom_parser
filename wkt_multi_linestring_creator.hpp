/**@brief ogc��׼��wkt��ʽ��multi_linestring���͹��칤����ͷ�ļ�
@author felix
@data 2016-09-01
*/
#ifndef WKT_MULTI_LINESTRING_HEAD
#define WKT_MULTI_LINESTRING_HEAD

#include "geom_base_creator.hpp"

#include <sstream>
namespace ogc_wkt
{
	template< typename T = double>
	class wkt_multi_linestring_creator :public geom_base_creator
	{
	public:
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			return "";
		}
	};
}



#endif//WKT_MULTI_LINESTRING_HEAD
