/**@brief ogc��׼��wkt��ʽ��geom���͹��������ͷ�ļ�
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
