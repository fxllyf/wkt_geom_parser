/**@brief ogc��׼��wkt��ʽ��geom���͹��������ͷ�ļ�
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
