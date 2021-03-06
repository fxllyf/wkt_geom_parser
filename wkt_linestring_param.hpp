/**@brief linestring的组成参数类头文件
@note 先构造，再append，最后获取数据集
@author felix
@data 2016-09-01
@modify boost::unordered_multimap有序被替换
*/

#ifndef WKT_LINESTRING_PARAM_HEAD
#define WKT_LINESTRING_PARAM_HEAD
#include "wkt_geom_common_public.h"
#include "wkt_geom_param_base.hpp"
namespace ogc_wkt
{
	template<typename T >
	struct linestring_param : public geom_param_base
	{
		linestring_param()
		{
			dataset_.param_x.clear();
			dataset_.param_y.clear();
		}

		inline void append(T x, T y)
		{
			/*dataset_.insert(std::make_pair(x,y))*/
			dataset_.param_x.push_back(x);
			dataset_.param_y.push_back(y);
		}

		inline geom_dataset<T> get_data_set()
		{
			return dataset_;
		}
	private:
		//boost::unordered_multimap<T,T> dataset_;
		geom_dataset<T> dataset_;
	};
}

#endif //WKT_LINESTRING_PARAM_HEAD
