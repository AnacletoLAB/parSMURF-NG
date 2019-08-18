// parSMURFng
// 2019 - Alessandro Petrini - AnacletoLAB - Universita' degli Studi di Milano
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>	// Temporary, for sleeping a thread
#include <mpi.h>

#include "parSMURFUtils.h"
#include "easylogging++.h"
#include "MegaCache.h"
#include "organizer.h"
#include "hyperSMURF_core.h"

class Runner{
public:
	Runner(int rank, int worldSize, MegaCache * const cache, Organizer &organ, CommonParams commonParams, std::vector<GridParams> gridParams);
	~Runner() {};
	void go();
	void savePredictions();

	std::vector<double> 		preds;

private:
	void partProcess(int rank, int worldSize, size_t thrNum, MegaCache * const cache, Organizer &organ,
			CommonParams &commonParams, std::vector<GridParams> &gridParams, std::vector<size_t> &partsForThisRank,
			uint8_t currentFold, std::mutex * p_accumulLock, std::mutex * p_partVectLock, std::vector<double> &preds);

	int							rank;
	int							worldSize;
	MegaCache * const			cache;
	Organizer 					organ;
	CommonParams 				commonParams;
	std::vector<GridParams> 	gridParams;


};