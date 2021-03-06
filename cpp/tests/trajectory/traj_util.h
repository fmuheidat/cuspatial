#pragma once

#include <cuspatial/types.hpp>

namespace cuspatial {
	/**
	 * @brief retrive camera origin at a particular intersection from a configuration file

	 * @param[in]  df_fn: name of configuration file that contains paramters for all cameras

	 * @param[in]  inter_name:  the unique name of an intersection

	 * @param[out]  camera_origin  Location (lon/lat/alt) of the retrieved camera origin
	 *
	 * @return negative error code; 0 for success
	 */
	int get_camera_origin(const char *df_fn, const char * inter_name, location_3d<double> & camera_origin);


	/**
	 * @brief retrive id, timestamp and location fields of a "raw" trajectory dataset,
	 * i.e., a set of coordiantes (lon/lat/alt) with a timestamp and an object (e.g., vehicle) identifier.
	 *
	 * @param[in]  root_fn: the root of the three files stored in columnar format,
	 * with .objectid (uint32_t type),.time (its_timestamp type) and .location(location_3d type) extensions, respectively.
	 * @param[out]  objid: out array for ID
	 * @param[out]  time: out array for ID
	 * @param[out]  location: out array for ID
	 * @return the number of records (should be the same for all the three data files)
	 */
	size_t read_traj_soa(char *root_fn,int *& objid, its_timestamp *& time, location_3d<double>*&  location);

} // namespace cuspatial
