/**@brief ogc标准下wkt格式的geom类型构造基础类头文件
@author felix
@data 2016-09-01
*/
#ifndef GEOM_BASE_PARSER_HEAD
#define GEOM_BASE_PARSER_HEAD
#include <string>
namespace ogc_wkt
{
	struct geom_param_base; 
	struct geom_base_creator 
	{
		virtual ~geom_base_creator(){}
		virtual std::string get_geom_wkt_string(geom_param_base* param)
		{
			return "";
		}
	};
}

#endif//GEOM_BASE_PARSER_HEAD
