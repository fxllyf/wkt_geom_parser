/**@brief segment的组成参数类头文件
@note 先构造，再append，最后获取数据集，使用散列映射作为数据结构
@author felix
@data 2016-09-01
*/
#ifndef SEGMENT_GEOM_PARAM_HEAD 
#define SEGMENT_GEOM_PARAM_HEAD
#include "wkt_geom_common_public.h"
#include "wkt_geom_param_base.hpp"

namespace ogc_wkt
{
	template<typename T >
	struct segment_param : public geom_param_base
	{
		segment_param(T x_begin, T y_begin, T x_end, T y_end)
		{
			x_begin_ = x_begin;
			y_begin_ = y_begin;
			x_end_ = x_end;
			y_end_ = y_end;
		}

		inline void set_begin_point(T x, T y)
		{
			x_begin_ = x;
			y_begin_ = y;
		}

		inline void set_end_point(T x, T y)
		{
			x_end_ = x;
			y_end_ = y;
		}
		
		inline T get_begin_x(){return x_begin_;}
		inline T get_begin_y(){return y_begin_;}
		inline T get_end_x(){return x_end_;}
		inline T get_end_y(){return y_end_;}
	private:
		T x_begin_;
		T x_end_;
		T y_begin_;
		T y_end_;

	};
}

#endif //SEGMENT_GEOM_PARAM_HEAD
