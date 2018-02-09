/**@brief ogc标准下wkt格式的geom类型构造参数类头文件
@author felix
@data 2016-09-01
*/
#ifndef WKT_GEOM_PARAM_BASE_HEAD
#define WKT_GEOM_PARAM_BASE_HEAD

namespace ogc_wkt
{
	struct geom_param_base 
	{
		virtual ~geom_param_base(){}
		virtual void append(double,double){}
		//virtual  geom_dataset<double> get_data_set(){}
	};


}

#endif//WKT_GEOM_PARAM_BASE_HEAD
