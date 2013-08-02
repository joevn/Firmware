/****************************************************************************
 *
 *   Copyright (C) 2012 PX4 Development Team. All rights reserved.
 *   Author: @author Lorenz Meier <lm@inf.ethz.ch>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file vehicle_local_position.h
 * Definition of the local fused NED position uORB topic.
 */

#ifndef TOPIC_VEHICLE_LOCAL_POSITION_H_
#define TOPIC_VEHICLE_LOCAL_POSITION_H_

#include <stdint.h>
#include <stdbool.h>
#include "../uORB.h"

/**
 * @addtogroup topics
 * @{
 */

/**
 * Fused local position in NED.
 */
struct vehicle_local_position_s
{
	uint64_t timestamp;			/**< time of this estimate, in microseconds since system start */
	bool valid;				/**< true if position satisfies validity criteria of estimator */

	float x;				/**< X positin in meters in NED earth-fixed frame */
	float y;				/**< X positin in meters in NED earth-fixed frame */
	float z;				/**< Z positin in meters in NED earth-fixed frame (negative altitude) */
	float absolute_alt;			/**< Altitude as defined by pressure / GPS, 			LOGME */
	float vx; 				/**< Ground X Speed (Latitude), m/s in NED				LOGME */
	float vy;				/**< Ground Y Speed (Longitude), m/s in NED				LOGME */
	float vz;				/**< Ground Z Speed (Altitude), m/s	in NED				LOGME */
	float hdg; 				/**< Compass heading in radians -PI..+PI.					  */

	// TODO Add covariances here

	/* Reference position in GPS / WGS84 frame */
	uint64_t home_timestamp;/**< Time when home position was set						  */
	int32_t home_lat;		/**< Latitude in 1E7 degrees							LOGME */
	int32_t home_lon;		/**< Longitude in 1E7 degrees							LOGME */
	float home_alt;			/**< Altitude in meters									LOGME */
	float home_hdg; 		/**< Compass heading in radians -PI..+PI.					  */

};

/**
 * @}
 */

/* register this as object request broker structure */
ORB_DECLARE(vehicle_local_position);

#endif
