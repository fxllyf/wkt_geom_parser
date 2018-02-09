/**@brief ogc标准下wkt格式的geom读写公共头文件
   @author felix
   @data 2016-09-01
*/
#ifndef WKT_GEOM_COMMON_PUBLIC_HEAD
#define WKT_GEOM_COMMON_PUBLIC_HEAD

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/linestring.hpp> 
#include <boost/geometry/geometries/box.hpp>  
#include <boost/geometry/geometries/ring.hpp>  
#include <boost/geometry/geometries/multi_point.hpp>
#include <boost/geometry/geometries/multi_linestring.hpp>
#include <boost/geometry/geometries/multi_polygon.hpp>



#define AUTO_DELETE(ptr) {if(ptr){delete ptr;(ptr)=NULL;} }
#define AUTO_DELETE_ARRAY(ptr) {if(ptr){delete[] ptr;(ptr)=NULL;} }

///几何类型定义
#define  GEOM_MAX								10

#define  GEOM_BOX								0
#define  GEOM_LINESTRING						1
#define  GEOM_POINT								2
#define  GEOM_POINT_XY							3
#define  GEOM_POLYGON							4
#define  GEOM_RING								5
#define  GEOM_SEGMENT							6
#define  GEOM_MULTI_LINESTRING					7
#define  GEOM_MULTI_POINT						8
#define  GEOM_MULTI_POLYGON						9

namespace ogc_wkt
{
	template<typename T>
	struct geom_dataset 
	{
		std::vector<T> param_x;
		std::vector<T> param_y;
	};

	namespace geom = boost::geometry;
	typedef geom::model::d2::point_xy<double> point_type;
	
}

#endif//WKT_GEOM_COMMON_PUBLIC_HEAD
