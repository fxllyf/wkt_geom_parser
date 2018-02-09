/**@brief ogc标准下wkt格式的geom类型测试
@author felix
@data 2016-09-01
*/

#include <iostream>
#include "wkt_geom_factory.h"
#include "point_xy_geom_param.hpp"
#include "polygon_geom_param.hpp"
#include "wkt_linestring_param.hpp"
#include "wkt_segment_param.hpp"
#include "wkt_ring_param.hpp"
#include "wkt_multi_point_param.hpp"

int main()
{
	ogc_wkt::wkt_geom_factory factory;
	ogc_wkt::geom_base_creator* creator = factory.get_object_link_geom(ogc_wkt::POINT_XY);

	///////////////////geom point test/////////////////////////////////
	ogc_wkt::geom_param_base* param1 = new ogc_wkt::point_xy_param<double>(3,6);
	ogc_wkt::geom_param_base* param2 = new ogc_wkt::point_xy_param<double>(13,16);

	std::cout<<creator->get_geom_wkt_string(param1)<<std::endl;
	std::cout<<creator->get_geom_wkt_string(param2)<<std::endl;

	////////////////geom polygon test////////////////////////////////////
	ogc_wkt::geom_base_creator* creator_polygon = factory.get_object_link_geom(ogc_wkt::POLYGON);

	ogc_wkt::polygon_param<double>* param3 = new ogc_wkt::polygon_param<double>;
	param3->append(0,0);
	param3->append(0,4);
	param3->append(4,4);
	param3->append(4,0);
	param3->append(0,0);
	ogc_wkt::geom_param_base* param4 = (ogc_wkt::geom_param_base*)param3;

	std::cout<<creator_polygon->get_geom_wkt_string(param4)<<std::endl;
	//////////////////////linestring/////////////////////////////////////////////
	ogc_wkt::geom_base_creator* creator_line = factory.get_object_link_geom(ogc_wkt::LINESTRING);

	ogc_wkt::linestring_param<double>* param5 = new ogc_wkt::linestring_param<double>;
	param5->append(0,0);
	param5->append(0,4);
	param5->append(4,4);
	ogc_wkt::geom_param_base* param6 = (ogc_wkt::geom_param_base*)param5;

	std::cout<<creator_line->get_geom_wkt_string(param6)<<std::endl;
	/////////////////////segment///////////////////////////////////////////////////
	ogc_wkt::geom_base_creator* creator_segment = factory.get_object_link_geom(ogc_wkt::SEGMENT);

	ogc_wkt::segment_param<double>* param7 = new ogc_wkt::segment_param<double>(0,0,1,2);
	ogc_wkt::geom_param_base* param8 = (ogc_wkt::geom_param_base*)param7;

	std::cout<<creator_segment->get_geom_wkt_string(param8)<<std::endl;

	///支持修改
	param7->set_begin_point(10,10);
	param7->set_end_point(60,60);
	std::cout<<creator_segment->get_geom_wkt_string(param8)<<std::endl;

	////////////////////ring///////////////////////////////////////////////////// 
	ogc_wkt::geom_base_creator* creator_ring = factory.get_object_link_geom(ogc_wkt::RING);

	ogc_wkt::geom_param_base* param9 = new ogc_wkt::ring_param<double>;
	param9->append(0,0);
	param9->append(100, 0);
	param9->append(200, 100);
	param9->append(100, 200);
	param9->append(0, 200);
	param9->append(0, 0);
	//ogc_wkt::geom_param_base* param6 = (ogc_wkt::geom_param_base*)param5;

	std::cout<<creator_ring->get_geom_wkt_string(param9)<<std::endl;

	/////////////////multi_point////////////////////////////////////////////////
	ogc_wkt::geom_base_creator* creator_multi_point = factory.get_object_link_geom(ogc_wkt::MULTI_POINT);

	ogc_wkt::geom_param_base* param10 = new ogc_wkt::multi_point_param<double>;
	param10->append(0,0);
	param10->append(100, 0);
	param10->append(200, 100);
	param10->append(100, 200);

	std::cout<<creator_multi_point->get_geom_wkt_string(param10)<<std::endl;

	//////////////////////////////////////////////////////////////////////
	delete param1;
	delete param2;
	delete param3;
	param4 = NULL;

	getchar();
	return 0;
}
