/*
 * Copyright (C) 2006-2013  Music Technology Group - Universitat Pompeu Fabra
 *
 * This file is part of Essentia
 *
 * Essentia is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation (FSF), either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the Affero GNU General Public License
 * version 3 along with this program.  If not, see http://www.gnu.org/licenses/
 */

#ifndef MUSIC_EXTRACTOR_H
#define MUSIC_EXTRACTOR_H

#include "essentia/pool.h"
#include "essentia/algorithm.h"
#include "essentia/types.h"
#include "essentia/scheduler/network.h"
#include "essentia/streaming/sourcebase.h"
#include "essentia/streaming/streamingalgorithm.h"
#include "essentia/algorithmfactory.h"
#include "essentia/streaming/algorithms/poolstorage.h"
#include "essentia/streaming/algorithms/vectorinput.h"

#include "MusicLowlevelDescriptors.h"
#include "MusicRhythmDescriptors.h"
#include "MusicTonalDescriptors.h"


#define EXTRACTOR_VERSION "music 1.0"

using namespace std;
using namespace essentia;
using namespace streaming;

 class MusicExtractor{

 protected:

 	Pool computeAggregation(Pool& pool);

  Real analysisSampleRate;
  Real startTime;
  Real endTime;

  Real replayGain;
  string downmix;

 public:
 	Pool results;
 	Pool stats;
  Pool options;

 	void compute(const string& audioFilename);
  void setExtractorOptions(const std::string& filename);
  void setExtractorDefaultOptions();
  void mergeValues();
  void readMetadata(const string& audioFilename);
  void computeMD5(const string& audioFilename);
  void computeReplayGain(const string& audioFilename);
  void computeSVMDescriptors(Pool& pool);
  void outputToFile(Pool& pool, const string& outputFilename);
	
 };

 #endif