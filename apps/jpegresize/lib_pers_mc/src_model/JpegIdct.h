/* Copyright (c) 2015 Convey Computer Corporation
 *
 * This file is part of the OpenHT jpegscale application.
 *
 * Use and distribution licensed under the BSD 3-clause license.
 * See the LICENSE file for the complete license text.
 */
#pragma once

#include "JobInfo.h"

void jpegIdct ( JobInfo * pJobInfo, int ci, int16_t (&coefBlock)[8][8], uint8_t * outBlock[8] );
