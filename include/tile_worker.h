/*! \file */ 
#ifndef _TILE_WORKER_H
#define _TILE_WORKER_H

#include "shared_data.h"
#include <boost/asio/thread_pool.hpp>

/// Start function for worker threads
bool outputProc(boost::asio::thread_pool &pool, SharedData &sharedData, OSMStore &osmStore, std::vector<OutputObjectRef> const &data, TileCoordinates coordinates, uint zoom);

// User stop signal
bool signalStop=false;
void handleUserSignal(int signum) {
	std::cout << "User requested break in processing" << std::endl;
	signalStop=true;
}

#endif //_TILE_WORKER_H
